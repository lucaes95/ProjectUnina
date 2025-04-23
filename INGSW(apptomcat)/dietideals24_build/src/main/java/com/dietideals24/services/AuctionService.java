package com.dietideals24.services;

import java.math.BigDecimal;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;
import java.sql.Timestamp;
import java.time.Instant;
import java.time.Duration;

import com.dietideals24.models.Auction;
import com.dietideals24.models.Bid;
import com.dietideals24.utils.DBConnection;

public class AuctionService {

    public boolean createAuction(Auction auction) {
        String sql = "INSERT INTO auctions (seller_id, buyer_id, title, description, category, auction_type, start_price, current_price, "
                + "min_price, decrement_amount, decrement_interval_minutes, start_time, end_time, status, winner_id, image_path) "
                + "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

        try (Connection conn = DBConnection.getConnection();
                PreparedStatement stmt = conn.prepareStatement(sql)) {

            auction.prepareStatementForInsert(stmt);

            return stmt.executeUpdate() > 0;
        } catch (SQLException e) {
            e.printStackTrace();
            return false;
        }
    }

    public Auction getAuctionById(int auctionId) {
        String query = "SELECT \r\n" + //
                "    auctions.*,\r\n" + //
                "    (SELECT bids.user_id \r\n" + //
                "     FROM bids \r\n" + //
                "     WHERE bids.auction_id = auctions.auction_id \r\n" + //
                "     ORDER BY bids.bid_price ASC \r\n" + //
                "     LIMIT 1\r\n" + //
                "    ) AS possible_winner\r\n" + //
                "FROM auctions\r\n" + //
                "WHERE auction_id = ?";

        try (Connection conn = DBConnection.getConnection();
                PreparedStatement stmt = conn.prepareStatement(query)) {
            stmt.setInt(1, auctionId);

            try (ResultSet rs = stmt.executeQuery()) {
                if (rs.next()) {
                    return Auction.fromResultSet(rs); // Restituisce l'asta trovata
                }
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }

        return null; // Se l'asta non viene trovata
    }

    public List<Bid> getBidsByAuctionId(int auctionId) {
        List<Bid> bids = new ArrayList<>();
        String query = "SELECT id, bid_price, user_id, bid_time, auction_id FROM bids WHERE auction_id = ?";

        try (Connection conn = DBConnection.getConnection();
                PreparedStatement pstmt = conn.prepareStatement(query)) {

            pstmt.setInt(1, auctionId);

            try (ResultSet rs = pstmt.executeQuery()) {
                while (rs.next()) {
                    Bid bid = new Bid();
                    bid.setId(rs.getInt("id"));
                    bid.setBidPrice(rs.getBigDecimal("bid_price"));
                    bid.setUserId(rs.getString("user_id"));
                    bid.setBidTime(rs.getTimestamp("bid_time"));
                    bid.setAuctionId(rs.getInt("auction_id"));
                    bids.add(bid);
                }
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }

        return bids;
    }

    public Instant getLastBidTime(int auctionId, String username) {
        String query = "SELECT bid_time FROM bids WHERE auction_id = ? AND user_id = ? ORDER BY bid_time DESC LIMIT 1";
        try (Connection conn = DBConnection.getConnection();
                PreparedStatement stmt = conn.prepareStatement(query)) {
            stmt.setInt(1, auctionId);
            stmt.setString(2, username);
            try (ResultSet rs = stmt.executeQuery()) {
                if (rs.next()) {
                    Timestamp timestamp = rs.getTimestamp("bid_time");
                    return timestamp.toInstant();
                }
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return null;
    }

    public long getWaitTimeForNextBid(int auctionId, String username) {
        Instant now = Instant.now();
        Instant lastBidTime = getLastBidTime(auctionId, username);
        // Se non ci sono offerte precedenti, non occorre attendere
        if (lastBidTime == null) {
            return 0;
        }
        Duration elapsed = Duration.between(lastBidTime, now);
        long requiredWait = 300; // secondi di attesa richiesti
        long secondsElapsed = elapsed.getSeconds();
        // Se sono trascorsi meno di 300 secondi, ritorna quanti secondi ancora
        // attendere
        if (secondsElapsed < requiredWait) {
            return requiredWait - secondsElapsed;
        }
        return 0;
    }

    public boolean acceptBid(int auctionId, int bidId) {
        String sql = "UPDATE auctions SET " +
                "status = 'completata', " +
                "winner_id = (SELECT b.user_id FROM bids b WHERE b.id = ? AND b.auction_id = auctions.auction_id), " +
                "current_price = (SELECT b.bid_price FROM bids b WHERE b.id = ? AND b.auction_id = auctions.auction_id) "
                +
                "WHERE auction_id = ? AND EXISTS (SELECT 1 FROM bids b WHERE b.id = ? AND b.auction_id = auctions.auction_id)";

        try (Connection conn = DBConnection.getConnection();
                PreparedStatement pstmt = conn.prepareStatement(sql)) {

            pstmt.setInt(1, bidId);
            pstmt.setInt(2, bidId);
            pstmt.setInt(3, auctionId);
            pstmt.setInt(4, bidId);

            int affectedRows = pstmt.executeUpdate();

            return affectedRows > 0;
        } catch (SQLException e) {
            e.printStackTrace();
            return false;
        }
    }

    public boolean updateAuctionPrice(int auctionId, double newPrice, String username) {
        String query = "UPDATE auctions \n" + //
                "SET current_price = ?, \n" + //
                "    winner_id = ?, \n" + //
                "WHERE auction_id = ?";

        try (Connection conn = DBConnection.getConnection();
                PreparedStatement stmt = conn.prepareStatement(query)) {
            stmt.setDouble(1, newPrice);
            stmt.setString(2, username);
            stmt.setInt(3, auctionId);

            return stmt.executeUpdate() > 0;
        } catch (SQLException e) {
            e.printStackTrace();
        }

        return false;
    }

    public boolean updateAuctionPriceInversa(int auctionId, double newPrice, String username) {
        String query = "UPDATE auctions SET current_price = ?, winner_id = ? WHERE auction_id = ?";

        try (Connection conn = DBConnection.getConnection();
                PreparedStatement stmt = conn.prepareStatement(query)) {
            stmt.setDouble(1, newPrice);
            stmt.setString(2, username);
            stmt.setInt(3, auctionId);

            return stmt.executeUpdate() > 0;
        } catch (SQLException e) {
            e.printStackTrace();
        }

        return false;
    }

    public boolean updateAuctionRibasso(int auctionId, double newPrice, String username, boolean enableModify) {

        String query;

        if (enableModify) {
            query = """
                    UPDATE auctions
                        SET current_price = ?,
                            status = 'completata',
                            winner_id = ?
                        WHERE auction_id = ?
                    """;
        } else {
            query = """
                    UPDATE auctions
                        SET current_price = current_price,
                            status = status,
                            winner_id = winner_id
                        WHERE auction_id = ?
                    """;
        }

        try (Connection conn = DBConnection.getConnection();
                PreparedStatement stmt = conn.prepareStatement(query)) {
            if (!enableModify) {
                stmt.setDouble(1, auctionId);
            } else {
                stmt.setDouble(1, newPrice);
                stmt.setString(2, username);
                stmt.setInt(3, auctionId);
            }

            stmt.executeUpdate();
            return true;
        } catch (SQLException e) {
            e.printStackTrace();
        }

        return false;
    }

    public boolean isAuctionValid(Auction auction) {
        switch (auction.getAuctionType()) {
            case "ribasso":
                return auction.getDecrementAmount() != null;
            case "silenziosa":
                return auction.getDecrementAmount() == null;
            case "inversa":
                return auction.getMinPrice() != null;
            default:
                return false;
        }
    }

    public List<Auction> getUserAuctions(String userId, String keyword, String userRole, int page, int pageSize,
            String filterType, String category, int limit) { // Aggiunto parametro limit

        String query = userRole.equalsIgnoreCase("compratore")
                ? "SELECT * FROM auctions WHERE (buyer_id = ? AND auction_type = 'inversa') ORDER BY start_time DESC"
                : "SELECT * FROM auctions WHERE (seller_id = ? AND (auction_type = 'ribasso' OR auction_type = 'silenziosa')) ORDER BY start_time DESC";

        List<Auction> auctions = fetchAuctions(query, userId);

        if (keyword != null && !keyword.trim().isEmpty()) {
            final String keywordLower = keyword.toLowerCase();
            auctions = auctions.stream()
                    .filter(a -> (a.getTitle() != null && a.getTitle().toLowerCase().contains(keywordLower)) ||
                            (a.getDescription() != null && a.getDescription().toLowerCase().contains(keywordLower)) ||
                            (a.getCategory() != null && a.getCategory().toLowerCase().contains(keywordLower)))
                    .collect(Collectors.toList());
        }
        if (category != null && !category.trim().isEmpty()) {
            final String categoryLower = category.toLowerCase();
            auctions = auctions.stream()
                    .filter(a -> a.getCategory() != null && categoryLower.equalsIgnoreCase(a.getCategory()))
                    .collect(Collectors.toList());
        }
        if (filterType != null && !filterType.trim().isEmpty()) {
            final String filterTypeLower = filterType.toLowerCase();
            auctions = auctions.stream()
                    .filter(a -> a.getAuctionType() != null && a.getAuctionType().toLowerCase().equals(filterTypeLower))
                    .collect(Collectors.toList());
        }

        if (page < 1)
            page = 1;
        int start = (page - 1) * pageSize;

        if (start >= auctions.size()) {
            return Collections.emptyList();
        }

        int end = Math.min(start + limit, auctions.size());

        return auctions.subList(start, end);
    }

    public List<Auction> getActiveAuctions(String userRole, String keyword, String category, int page, int pageSize,
            String filterType, int limit) {

        List<Auction> auctions = fetchAuctions(
                "SELECT * FROM auctions WHERE status = 'attiva' ORDER BY start_time DESC");

        if ("compratore".equals(userRole)) {
            auctions = auctions.stream()
                    .filter(a -> !"inversa".equalsIgnoreCase(a.getAuctionType()))
                    .collect(Collectors.toList());
        } else if ("venditore".equals(userRole)) {
            auctions = auctions.stream()
                    .filter(a -> "inversa".equalsIgnoreCase(a.getAuctionType()))
                    .collect(Collectors.toList());
        }

        if (keyword != null && !keyword.trim().isEmpty()) {
            final String keywordLower = keyword.toLowerCase();
            auctions = auctions.stream()
                    .filter(a -> (a.getTitle() != null && a.getTitle().toLowerCase().contains(keywordLower)) ||
                            (a.getDescription() != null && a.getDescription().toLowerCase().contains(keywordLower)) ||
                            (a.getCategory() != null && a.getCategory().toLowerCase().contains(keywordLower)))
                    .collect(Collectors.toList());
        }

        if (category != null && !category.trim().isEmpty()) {
            final String categoryLower = category.toLowerCase();
            auctions = auctions.stream()
                    .filter(a -> a.getCategory() != null && a.getCategory().toLowerCase().equals(categoryLower))
                    .collect(Collectors.toList());
        }

        if (filterType != null && !filterType.trim().isEmpty()) {
            final String filterTypeLower = filterType.toLowerCase();
            auctions = auctions.stream()
                    .filter(a -> a.getAuctionType() != null && a.getAuctionType().toLowerCase().equals(filterTypeLower))
                    .collect(Collectors.toList());
        }

        int start = (page - 1) * pageSize;

        if (start >= auctions.size()) {
            return new ArrayList<>();
        }

        int end = Math.min(start + limit, auctions.size());

        return auctions.subList(start, end);
    }

    public boolean isUserAuctionCreator(int auctionId, String username) {

        String query = "SELECT 1 FROM auctions WHERE auction_id = ? AND (buyer_id = ? OR seller_id = ?)";

        try (Connection conn = DBConnection.getConnection();
                PreparedStatement stmt = conn.prepareStatement(query)) {
            stmt.setInt(1, auctionId);
            stmt.setString(2, username);
            stmt.setString(3, username);

            try (ResultSet rs = stmt.executeQuery()) {
                return rs.next(); // Se trova almeno una riga, significa che l'utente è il creatore
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }

        return false;
    }

    public boolean isUserWinner(int auctionId, String username) {
        String query = "SELECT COUNT(*) FROM auctions WHERE auction_id = ? AND winner_id = ?";

        try (Connection conn = DBConnection.getConnection();
                PreparedStatement stmt = conn.prepareStatement(query)) {
            stmt.setInt(1, auctionId);
            stmt.setString(2, username);

            try (ResultSet rs = stmt.executeQuery()) {
                if (rs.next() && rs.getInt(1) > 0) {
                    return true; // L'utente è già il vincitore
                }
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }

        return false; // L'utente non è il vincitore
    }

    public boolean createBid(int auctionId, double bidPrice, String username) {

        // 1. Input Base
        if (username == null || username.trim().isEmpty()) {
            System.err.println("[VALIDATION SERVICE - createBid] Username nullo.");
            return false;
        }
        // Controlla se bidPrice è positivo
        if (bidPrice <= 0) {
            System.err.println("[VALIDATION SERVICE - createBid] BidPrice deve essere positivo.");
            return false;
        }

        // 2. Recupera Asta
        Auction auction = getAuctionById(auctionId);
        if (auction == null) {
            System.err.println("[VALIDATION SERVICE - createBid] Asta ID " + auctionId + " non trovata.");
            return false;
        }

        // 3. Stato Asta Attiva
        if (!"attiva".equalsIgnoreCase(auction.getStatus())) {
            System.err
                    .println("[VALIDATION SERVICE - createBid] Asta non attiva (Stato: " + auction.getStatus() + ").");
            return false;
        }

        long waitTime = getWaitTimeForNextBid(auctionId, username);
        if (waitTime > 0) {
            // Se waitTime > 0, il cooldown è attivo
            System.err.println("[VALIDATION SERVICE - createBid] Cooldown non rispettato. Attendere ancora " + waitTime
                    + " secondi.");
            return false; // Blocca l'offerta
        }

        // Impedisce all'utente che ha già fatto l'offerta vincente (più bassa) in
        // un'asta inversa
        // di fare ulteriori offerte sulla stessa asta.
        if ("inversa".equalsIgnoreCase(auction.getAuctionType()) &&
                auction.getWinnerId() != null &&
                auction.getWinnerId().equals(username)) {
            System.err.println("[VALIDATION SERVICE - createBid] Utente è già vincitore per asta inversa.");
            return false;
        }

        String auctionType = auction.getAuctionType();

        // Esegui i controlli basati sul prezzo corrente SOLO se l'asta NON è
        // silenziosa.
        if (!"silenziosa".equalsIgnoreCase(auctionType)) {

            BigDecimal currentPriceBD = auction.getCurrentPrice();
            BigDecimal bidPriceBD = BigDecimal.valueOf(bidPrice);

            // Se l'asta NON è silenziosa, un prezzo corrente nullo è generalmente un
            // errore.
            if (currentPriceBD == null) {
                System.err.println(
                        "[VALIDATION SERVICE - createBid] Prezzo corrente nullo per asta di tipo: " + auctionType);
                return false; // Blocca l'offerta se il prezzo è nullo e l'asta non è silenziosa
            }

            // Ora esegui i controlli specifici per i tipi di asta che richiedono confronto
            // col prezzo corrente
            if ("ribasso".equalsIgnoreCase(auctionType) && bidPriceBD.compareTo(currentPriceBD) > 0) {
                // Asta a ribasso: l'offerta non può essere maggiore del prezzo corrente
                System.err.println("[VALIDATION SERVICE - createBid] Offerta > Prezzo corrente (Ribasso).");
                return false;
            } else if ("inversa".equalsIgnoreCase(auctionType) && bidPriceBD.compareTo(currentPriceBD) >= 0) {
                // Asta inversa: l'offerta non può essere maggiore o uguale al prezzo corrente
                // (che rappresenta il minimo attuale)
                System.err.println("[VALIDATION SERVICE - createBid] Offerta >= Prezzo corrente (Inversa).");
                return false;
            }

        }

        String query = "INSERT INTO bids (auction_id, bid_price, user_id) VALUES (?, ?, ?)";

        try (Connection conn = DBConnection.getConnection();
                PreparedStatement stmt = conn.prepareStatement(query)) {

            stmt.setInt(1, auctionId);

            stmt.setDouble(2, bidPrice);
            stmt.setString(3, username);

            int rowsAffected = stmt.executeUpdate();
            return rowsAffected > 0;

        } catch (SQLException e) {
            System.err.println("Errore SQL durante createBid:");
            e.printStackTrace();
            return false;
        }
    }

    private List<Auction> fetchAuctions(String query, Object... params) {
        List<Auction> auctions = new ArrayList<>();
        try (Connection conn = DBConnection.getConnection();
                PreparedStatement stmt = conn.prepareStatement(query)) {

            for (int i = 0; i < params.length; i++) {
                stmt.setObject(i + 1, params[i]);
            }

            try (ResultSet rs = stmt.executeQuery()) {
                while (rs.next()) {

                    auctions.add(Auction.fromResultSet(rs));
                }
            }
        } catch (SQLException e) {

            System.err.println("Errore SQL durante fetchAuctions:");
            e.printStackTrace();
        }

        return auctions;
    }

    public boolean hasUnreadNotifications(String username) {
        String sql = "SELECT 1 FROM notifications WHERE username = ? AND status = 'UNREAD' LIMIT 1";

        if (username == null || username.trim().isEmpty()) {
            return false;
        }

        try (Connection conn = DBConnection.getConnection();
                PreparedStatement stmt = conn.prepareStatement(sql)) {

            stmt.setString(1, username);

            try (ResultSet rs = stmt.executeQuery()) {
                return rs.next();
            }
        } catch (SQLException e) {
            System.err.println("Errore SQL durante il controllo delle notifiche non lette per " + username);
            e.printStackTrace();
            return false;
        }
    }

}
