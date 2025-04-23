package com.dietideals24.services;

import com.dietideals24.models.UserProfile;
import com.dietideals24.utils.DBConnection;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class UserProfileService {

    // Recupera il profilo di un utente in base all'email.
    public static UserProfile getProfile(String email) throws SQLException {
        UserProfile profile = null;
        try (Connection conn = DBConnection.getConnection()) {
            String query = "SELECT * FROM user_profiles WHERE email = ?";
            PreparedStatement stmt = conn.prepareStatement(query);
            stmt.setString(1, email);
            ResultSet rs = stmt.executeQuery();
            if (rs.next()) {
                profile = new UserProfile();
                profile.setProfileId(rs.getInt("profile_id"));
                profile.setEmail(rs.getString("email"));
                profile.setFirstName(rs.getString("first_name"));
                profile.setLastName(rs.getString("last_name"));
                profile.setLocation(rs.getString("location"));
                profile.setBio(rs.getString("bio"));
                profile.setWebsite(rs.getString("website"));
                profile.setFacebook(rs.getString("facebook"));
                profile.setTwitter(rs.getString("twitter"));
                profile.setLinkedin(rs.getString("linkedin"));
                profile.setInstagram(rs.getString("instagram"));
                profile.setUsername(rs.getString("username"));
            }
        }
        return profile;
    }

    public static UserProfile getProfileByUsername(String username) throws SQLException {
        UserProfile profile = null;
        try (Connection conn = DBConnection.getConnection()) {
            String query = "SELECT * FROM user_profiles WHERE username = ?";
            PreparedStatement stmt = conn.prepareStatement(query);
            stmt.setString(1, username);
            ResultSet rs = stmt.executeQuery();
            if (rs.next()) {
                profile = new UserProfile();
                profile.setProfileId(rs.getInt("profile_id"));
                profile.setEmail(rs.getString("email"));
                profile.setFirstName(rs.getString("first_name"));
                profile.setLastName(rs.getString("last_name"));
                profile.setLocation(rs.getString("location"));
                profile.setBio(rs.getString("bio"));
                profile.setWebsite(rs.getString("website"));
                profile.setFacebook(rs.getString("facebook"));
                profile.setTwitter(rs.getString("twitter"));
                profile.setLinkedin(rs.getString("linkedin"));
                profile.setInstagram(rs.getString("instagram"));
                profile.setUsername(rs.getString("username"));
            }
        }
        return profile;
    }

    // Salva (inserisce o aggiorna) il profilo utente nel DB.
    public static void saveProfile(UserProfile profile, String username) throws SQLException {
        try (Connection conn = DBConnection.getConnection()) {
            // Verifica se esiste già un profilo per questa email.
            String checkQuery = "SELECT COUNT(*) AS count FROM user_profiles WHERE email = ?";
            PreparedStatement checkStmt = conn.prepareStatement(checkQuery);
            checkStmt.setString(1, profile.getEmail());
            ResultSet rs = checkStmt.executeQuery();
            boolean exists = false;
            if (rs.next()) {
                exists = rs.getInt("count") > 0;
            }

            if (exists) {
                // Aggiorna il profilo esistente.
                String updateQuery = "UPDATE user_profiles SET first_name = ?, last_name = ?, location = ?, bio = ?, website = ?, facebook = ?, twitter = ?, linkedin = ?, instagram = ? WHERE email = ?";
                PreparedStatement updateStmt = conn.prepareStatement(updateQuery);
                updateStmt.setString(1, profile.getFirstName());
                updateStmt.setString(2, profile.getLastName());
                updateStmt.setString(3, profile.getLocation());
                updateStmt.setString(4, profile.getBio());
                updateStmt.setString(5, profile.getWebsite());
                updateStmt.setString(6, profile.getFacebook());
                updateStmt.setString(7, profile.getTwitter());
                updateStmt.setString(8, profile.getLinkedin());
                updateStmt.setString(9, profile.getInstagram());
                updateStmt.setString(10, profile.getEmail());
                updateStmt.executeUpdate();
            }
        }
    }

    public static void createBasicProfile(UserProfile profile) throws SQLException {
        try (Connection conn = DBConnection.getConnection()) {
            // Verifica se esiste già un profilo per questa email.
            String checkQuery = "SELECT COUNT(*) AS count FROM user_profiles WHERE email = ?";
            PreparedStatement checkStmt = conn.prepareStatement(checkQuery);
            checkStmt.setString(1, profile.getEmail());
            ResultSet rs = checkStmt.executeQuery();
            boolean exists = false;
            if (rs.next()) {
                exists = rs.getInt("count") > 0;
            }

            if (!exists) {
                // Inserisce un nuovo profilo con solo email, nome e cognome.
                String insertQuery = "INSERT INTO user_profiles (profile_id, email, first_name, last_name, username) VALUES (?, ?, ?, ?, ?)";
                PreparedStatement insertStmt = conn.prepareStatement(insertQuery);
                insertStmt.setObject(1, null); // Utilizza l'ID utente generato durante la registrazione.
                insertStmt.setString(2, profile.getEmail());
                insertStmt.setString(3, profile.getFirstName());
                insertStmt.setString(4, profile.getLastName());
                insertStmt.setString(5, profile.getUsername());
                insertStmt.executeUpdate();
            } else {
                // Se il profilo esiste già, puoi decidere cosa fare.
                System.out.println("Profilo già esistente per questa email.");
            }
        }
    }

}
