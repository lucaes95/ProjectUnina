package com.dietideals24.utils;

import com.dietideals24.models.Auction;

import java.math.BigDecimal;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.Timestamp;
import java.time.LocalDateTime;

public class DBQueryHelper {

    public static void createTables() throws SQLException {
        try (Connection conn = TestDBConfig.getConnection();
                Statement stmt = conn.createStatement()) {

            String createAuctions = "CREATE TABLE auctions ("
                    + "auction_id INT AUTO_INCREMENT PRIMARY KEY, "
                    + "seller_id VARCHAR(255), "
                    + "buyer_id VARCHAR(255), "
                    + "title VARCHAR(255) NOT NULL, "
                    + "description VARCHAR(1024), "
                    + "category VARCHAR(255), "
                    + "auction_type VARCHAR(50) NOT NULL, "
                    + "start_price DECIMAL(19,2) CHECK (start_price IS NULL OR start_price >= 0), "
                    + "current_price DECIMAL(19,2) CHECK (current_price IS NULL OR current_price >= 0), "
                    + "min_price DECIMAL(19,2) CHECK (min_price IS NULL OR min_price >= 0), "
                    + "decrement_amount DECIMAL(19,2) CHECK (decrement_amount IS NULL OR decrement_amount > 0), "
                    + "decrement_interval_minutes INT CHECK (auction_type <> 'ribasso' OR (decrement_interval_minutes >= 1 AND decrement_interval_minutes <= 720)), "
                    + "start_time TIMESTAMP NOT NULL, "
                    + "end_time TIMESTAMP NOT NULL, "
                    + "status VARCHAR(50), "
                    + "winner_id VARCHAR(255), "
                    + "image_path VARCHAR(512), "
                    + "CONSTRAINT chk_auctions_h2_time_order CHECK (end_time >= DATEADD('HOUR', 1, start_time)), "
                    + "CONSTRAINT chk_auctions_h2_min_le_start CHECK (min_price IS NULL OR start_price IS NULL OR min_price <= start_price)"
                    + ")";
            stmt.execute(createAuctions);

            String createBids = "CREATE TABLE bids ("
                    + "id INT AUTO_INCREMENT PRIMARY KEY, "
                    + "auction_id INT NOT NULL, "
                    + "bid_price DECIMAL(19,2) NOT NULL CHECK (bid_price > 0), "
                    + "user_id VARCHAR(255) NOT NULL, "
                    + "bid_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL"
                    + ")";
            stmt.execute(createBids);

        } catch (SQLException e) {
            throw e;
        }
    }

    public static void dropTables() throws SQLException {
        try (Connection conn = TestDBConfig.getConnection();
                Statement stmt = conn.createStatement()) {
            stmt.execute("DROP TABLE IF EXISTS bids");
            stmt.execute("DROP TABLE IF EXISTS auctions");
        } catch (SQLException e) {
            throw e;
        }
    }

    public static void setAuctionStatus(int auctionId, String newStatus) throws SQLException {
        String sql = "UPDATE auctions SET status = ? WHERE auction_id = ?";
        try (Connection conn = TestDBConfig.getConnection();
                PreparedStatement stmt = conn.prepareStatement(sql)) {
            stmt.setString(1, newStatus);
            stmt.setInt(2, auctionId);
            int rowsAffected = stmt.executeUpdate();
            if (rowsAffected == 0) {
                throw new SQLException("Impossibile impostare lo stato per auctionId " + auctionId);
            }
        } catch (SQLException e) {
            throw e;
        }
    }

    public static int createTestAuction(String status, String sellerId, String winnerId, BigDecimal startPrice)
            throws SQLException {
        String sql = "INSERT INTO auctions (status, seller_id, winner_id, start_price, current_price, title, description, category, auction_type, start_time, end_time) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
        String title = "Test Auction " + System.currentTimeMillis();
        Timestamp now = Timestamp.valueOf(LocalDateTime.now());
        Timestamp future = Timestamp.valueOf(LocalDateTime.now().plusDays(1));

        try (Connection conn = TestDBConfig.getConnection();
                PreparedStatement pstmt = conn.prepareStatement(sql, Statement.RETURN_GENERATED_KEYS)) {
            pstmt.setString(1, status);
            pstmt.setString(2, sellerId);
            pstmt.setString(3, winnerId);
            pstmt.setBigDecimal(4, startPrice);
            pstmt.setBigDecimal(5, startPrice);
            pstmt.setString(6, title);
            pstmt.setString(7, "Test Description");
            pstmt.setString(8, "TestCategory");
            pstmt.setString(9, "ribasso");
            pstmt.setTimestamp(10, now);
            pstmt.setTimestamp(11, future);

            int affectedRows = pstmt.executeUpdate();
            if (affectedRows == 0) {
                throw new SQLException("Creazione asta fallita, nessuna riga modificata.");
            }

            try (ResultSet generatedKeys = pstmt.getGeneratedKeys()) {
                if (generatedKeys.next()) {
                    return generatedKeys.getInt(1);
                } else {
                    throw new SQLException("Creazione asta fallita, nessun ID ottenuto.");
                }
            }
        } catch (SQLException e) {
            throw e;
        }
    }

    public static int createTestBid(int auctionId, String userId, BigDecimal bidPrice) throws SQLException {
        String sql = "INSERT INTO bids (auction_id, user_id, bid_price, bid_time) VALUES (?, ?, ?, ?)";
        Timestamp bidTime = Timestamp.valueOf(LocalDateTime.now());

        try (Connection conn = TestDBConfig.getConnection();
                PreparedStatement pstmt = conn.prepareStatement(sql, Statement.RETURN_GENERATED_KEYS)) {
            pstmt.setInt(1, auctionId);
            pstmt.setString(2, userId);
            pstmt.setBigDecimal(3, bidPrice);
            pstmt.setTimestamp(4, bidTime);

            int affectedRows = pstmt.executeUpdate();
            if (affectedRows == 0) {
                throw new SQLException("Creazione offerta fallita, nessuna riga modificata.");
            }

            try (ResultSet generatedKeys = pstmt.getGeneratedKeys()) {
                if (generatedKeys.next()) {
                    return generatedKeys.getInt(1);
                } else {
                    throw new SQLException("Creazione offerta fallita, nessun ID ottenuto.");
                }
            }
        } catch (SQLException e) {
            throw e;
        }
    }

    public static Auction getAuctionFromDbById(int auctionId) throws SQLException {
        String sql = "SELECT auction_id, status, winner_id, current_price, seller_id, buyer_id, title, description, category, auction_type, start_price, min_price, decrement_amount, decrement_interval_minutes, start_time, end_time, image_path FROM auctions WHERE auction_id = ?";
        try (Connection conn = TestDBConfig.getConnection();
                PreparedStatement pstmt = conn.prepareStatement(sql)) {
            pstmt.setInt(1, auctionId);
            try (ResultSet rs = pstmt.executeQuery()) {
                if (rs.next()) {
                    return Auction.fromResultSet(rs);
                } else {
                    return null;
                }
            }
        } catch (SQLException e) {
            throw e;
        }
    }
}