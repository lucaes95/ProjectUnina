package com.dietideals24.services;

import com.dietideals24.models.Notification;
import com.dietideals24.utils.DBConnection;

import java.sql.*;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class NotificationService {

    public NotificationService() {
    }

    /**
     * Recupera tutte le notifiche per un utente specifico dal database,
     * ordinate dalle più recenti.
     */
    public List<Notification> getNotificationsForUser(String username) {
        if (username == null || username.trim().isEmpty()) {
            System.err.println("NotificationService: Tentativo di recuperare notifiche per username nullo/vuoto.");
            return Collections.emptyList();
        }

        System.out.println("NotificationService: Recupero notifiche per utente: " + username);
        List<Notification> notifications = new ArrayList<>();
        String sql = "SELECT * FROM notifications WHERE username = ? ORDER BY creation_timestamp DESC";

        try (Connection conn = DBConnection.getConnection();
                PreparedStatement stmt = conn.prepareStatement(sql)) {

            stmt.setString(1, username);

            try (ResultSet rs = stmt.executeQuery()) {
                while (rs.next()) {
                    Notification notification = new Notification();
                    notification.setNotificationId(rs.getInt("notification_id"));
                    notification.setUsername(rs.getString("username"));

                    int auctionIdInt = rs.getInt("auction_id");
                    notification.setAuctionId(rs.wasNull() ? null : auctionIdInt);

                    notification.setNotificationType(rs.getString("notification_type"));
                    notification.setMessage(rs.getString("message"));

                    // --- Modifica Qui ---
                    // Leggi lo stato direttamente come String dal DB
                    notification.setStatus(rs.getString("status"));
                    // --- Fine Modifica ---

                    Timestamp ts = rs.getTimestamp("creation_timestamp");
                    if (ts != null) {
                        notification.setCreationTimestamp(ts.toLocalDateTime());
                    } else {
                        notification.setCreationTimestamp(null);
                    }

                    notifications.add(notification);
                }
            }
        } catch (SQLException e) {
            System.err.println("Errore SQL durante il recupero delle notifiche per l'utente " + username);
            e.printStackTrace();
            // Restituisce lista parziale o vuota in caso di errore
            return notifications; // O return Collections.emptyList(); a seconda di cosa preferisci
        }

        System.out.println(
                "NotificationService: Restituite " + notifications.size() + " notifiche per utente: " + username);
        return notifications;
    }

    public boolean markAllNotificationsAsRead(String username) {
        if (username == null || username.trim().isEmpty()) {
            System.err.println(
                    "NotificationService: Tentativo di segnare come lette notifiche per username nullo/vuoto.");
            return false;
        }

        String sql = "UPDATE notifications SET status = 'READ' WHERE username = ? AND status = 'UNREAD'";
        int rowsAffected = 0;

        System.out.println("NotificationService: Tentativo di segnare come lette notifiche per utente: " + username);

        try (Connection conn = DBConnection.getConnection();
                PreparedStatement stmt = conn.prepareStatement(sql)) {

            stmt.setString(1, username);
            rowsAffected = stmt.executeUpdate();

            System.out.println(
                    "NotificationService: Aggiornate " + rowsAffected + " notifiche a READ per utente: " + username);

        } catch (SQLException e) {
            System.err.println("Errore SQL durante markAllNotificationsAsRead per l'utente " + username);
            e.printStackTrace();
            return false;
        }

        return rowsAffected > 0;
    }

    public boolean createNotification(String username, Integer auctionId, String type, String message) {
        if (username == null || username.trim().isEmpty() || type == null || type.trim().isEmpty() || message == null
                || message.trim().isEmpty()) {
            System.err
                    .println("NotificationService (convenience): Tentativo di creare notifica con parametri mancanti.");
            return false;
        }

        System.out.println(
                "NotificationService (convenience): Creazione notifica per utente: " + username + ", Tipo: " + type);

        Notification notification = new Notification();

        notification.setUsername(username);
        notification.setAuctionId(auctionId);
        notification.setNotificationType(type);
        notification.setMessage(message);

        return this.createNotification(notification);
    }

    public boolean createNotification(Notification notification) {
        if (notification == null || notification.getUsername() == null || notification.getUsername().trim().isEmpty()
                || notification.getNotificationType() == null || notification.getMessage() == null) {
            System.err.println("NotificationService: Tentativo di creare notifica con dati mancanti.");
            if (notification != null) {
                System.err.println("Dettagli notifica: " + notification);
            }
            return false;
        }

        System.out.println("NotificationService: Creazione notifica per utente: " + notification.getUsername());
        String sql = "INSERT INTO notifications (username, auction_id, notification_type, message, status, creation_timestamp) VALUES (?, ?, ?, ?, ?, ?)";
        int rowsAffected = 0;

        try (Connection conn = DBConnection.getConnection();
                PreparedStatement stmt = conn.prepareStatement(sql)) {

            stmt.setString(1, notification.getUsername());

            if (notification.getAuctionId() != null) {
                stmt.setInt(2, notification.getAuctionId());
            } else {
                stmt.setNull(2, Types.INTEGER);
            }

            stmt.setString(3, notification.getNotificationType());
            stmt.setString(4, notification.getMessage());

            String status = (notification.getStatus() != null && !notification.getStatus().trim().isEmpty())
                    ? notification.getStatus()
                    : "UNREAD";
            stmt.setString(5, status);

            stmt.setTimestamp(6, Timestamp.valueOf(LocalDateTime.now()));

            rowsAffected = stmt.executeUpdate();

        } catch (SQLException e) {
            System.err.println(
                    "Errore SQL durante la creazione della notifica per l'utente " + notification.getUsername());
            e.printStackTrace();
            return false;
        }

        return rowsAffected == 1;
    }

    public boolean deleteNotification(int notificationId, String username) {

        if (username == null || username.trim().isEmpty() || notificationId <= 0) {
            System.err.println(
                    "NotificationService: Tentativo di eliminare notifica con ID non valido o username nullo/vuoto. ID: "
                            + notificationId + ", User: " + username);
            return false;
        }

        System.out.println("NotificationService: Tentativo di eliminare notifica ID: " + notificationId
                + " per utente: " + username);

        String sql = "DELETE FROM notifications WHERE notification_id = ? AND username = ?";
        int rowsAffected = 0;

        try (Connection conn = DBConnection.getConnection();
                PreparedStatement stmt = conn.prepareStatement(sql)) {

            stmt.setInt(1, notificationId);
            stmt.setString(2, username);

            rowsAffected = stmt.executeUpdate();

        } catch (SQLException e) {
            System.err.println("Errore SQL durante l'eliminazione della notifica ID " + notificationId
                    + " per l'utente " + username);
            e.printStackTrace();
            return false;
        }

        return rowsAffected == 1;
    }

    public int deleteAllNotificationsForUser(String username) throws SQLException {

        if (username == null || username.trim().isEmpty()) {
            System.err.println(
                    "NotificationService: Tentativo di eliminare tutte le notifiche con username nullo o vuoto.");

            throw new IllegalArgumentException(
                    "Username non può essere nullo o vuoto per eliminare tutte le notifiche.");

        }

        System.out.println("NotificationService: Tentativo di eliminare TUTTE le notifiche per l'utente: " + username);

        String sql = "DELETE FROM notifications WHERE username = ?";
        int rowsAffected = 0;

        try (Connection conn = DBConnection.getConnection();
                PreparedStatement stmt = conn.prepareStatement(sql)) {

            stmt.setString(1, username);

            rowsAffected = stmt.executeUpdate();

            System.out.println("NotificationService: Eliminate con successo " + rowsAffected
                    + " notifiche per l'utente: " + username);

        }

        return rowsAffected;
    }

}