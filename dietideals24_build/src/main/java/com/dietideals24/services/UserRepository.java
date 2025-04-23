package com.dietideals24.services;

import com.dietideals24.utils.DBConnection;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class UserRepository {

    // Metodo per ottenere l'ID dell'utente dal database
    public int getUserIdFromDatabase(String username) {
        String sql = "SELECT id FROM users WHERE username = ?";

        try (Connection conn = DBConnection.getConnection();
                PreparedStatement stmt = conn.prepareStatement(sql)) {

            stmt.setString(1, username);
            ResultSet rs = stmt.executeQuery();

            if (rs.next()) {
                return rs.getInt("id");
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }

        return -1; // Restituisce -1 se l'utente non viene trovato
    }

    public static String getEmailByUsername(String username) throws SQLException {
        String email = null;
        String sql = "SELECT email FROM users WHERE username = ? LIMIT 1";

        try (Connection conn = DBConnection.getConnection();
                PreparedStatement stmt = conn.prepareStatement(sql)) {

            stmt.setString(1, username);
            try (ResultSet rs = stmt.executeQuery()) {
                if (rs.next()) {
                    email = rs.getString("email");
                }
            }
        }
        return email;
    }

}