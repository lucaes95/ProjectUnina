package com.dietideals24.services;

import com.dietideals24.utils.DBConnection;
import com.dietideals24.utils.PasswordUtil;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.sql.Statement;

public class UserService {

    public Boolean registerUser(String email, String username, String password, String role) {
        final int MIN_PASSWORD_LENGTH = 8;
        if (password == null || password.length() < MIN_PASSWORD_LENGTH) {
            System.err.println("Errore registrazione: La password fornita è nulla o troppo corta (minimo "
                    + MIN_PASSWORD_LENGTH + " caratteri).");
            return false;
        }

        String hashedPassword = PasswordUtil.hashPassword(password);

        String sql = "INSERT INTO users (email, username, password, role, created_at) VALUES (?, ?, ?, ?, NOW())";

        try (Connection conn = DBConnection.getConnection();
                PreparedStatement stmt = conn.prepareStatement(sql, Statement.RETURN_GENERATED_KEYS)) {

            stmt.setString(1, email);
            stmt.setString(2, username);
            stmt.setString(3, hashedPassword);
            stmt.setString(4, role);

            int rowsAffected = stmt.executeUpdate();
            return rowsAffected > 0;

        } catch (SQLException e) {
            System.err.println("Errore SQL durante la registrazione dell'utente:");
            e.printStackTrace();
            return false;
        } catch (Exception e) {
            System.err.println("Errore generico durante la registrazione dell'utente:");
            e.printStackTrace();
            return false;
        }
    }

    public boolean loginUser(String username, String password, String role) {
        String sql = "SELECT password FROM users WHERE username = ? AND role = ?";

        try (Connection conn = DBConnection.getConnection();
                PreparedStatement stmt = conn.prepareStatement(sql)) {
            stmt.setString(1, username);
            stmt.setString(2, role);

            ResultSet rs = stmt.executeQuery();

            if (rs.next()) {
                String hashedPassword = rs.getString("password");
                return PasswordUtil.checkPassword(password, hashedPassword);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }

        return false;
    }
}