package com.dietideals24.services;

import com.dietideals24.models.Bid;
import com.dietideals24.utils.DBConnection;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class BidService {

    public List<Bid> getBidsForAuction(String auctionIdStr) throws SQLException {
        List<Bid> bids = new ArrayList<>();
        int auctionId = Integer.parseInt(auctionIdStr);
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
        }
        return bids;
    }

    // Metodo per ottenere l'username dell'utente che ha fatto l'offerta
    public String getUserByBidId(String bidId) {
        String sql = "SELECT user_id FROM bids WHERE id = ?";

        try (Connection conn = DBConnection.getConnection();
                PreparedStatement stmt = conn.prepareStatement(sql)) {

            stmt.setString(1, bidId);
            ResultSet rs = stmt.executeQuery();

            if (rs.next()) {
                return rs.getString("user_id");
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }

        return null;
    }
}
