package com.dietideals24.models;

import java.time.LocalDateTime;

public class Notification {

    private int notificationId;
    private String username;
    private Integer auctionId;
    private String notificationType;
    private String message;
    private String status;
    private LocalDateTime creationTimestamp;

    public Notification() {
    }

    public Notification(int notificationId, String username, Integer auctionId, String notificationType, String message,
            String status, LocalDateTime creationTimestamp) {
        this.notificationId = notificationId;
        this.username = username;
        this.auctionId = auctionId;
        this.notificationType = notificationType;
        this.message = message;
        this.status = status;
        this.creationTimestamp = creationTimestamp;
    }

    // --- Getters e Setters ---
    public int getNotificationId() {
        return notificationId;
    }

    public void setNotificationId(int notificationId) {
        this.notificationId = notificationId;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public Integer getAuctionId() {
        return auctionId;
    }

    public void setAuctionId(Integer auctionId) {
        this.auctionId = auctionId;
    }

    public String getNotificationType() {
        return notificationType;
    }

    public void setNotificationType(String notificationType) {
        this.notificationType = notificationType;
    }

    public String getMessage() {
        return message;
    }

    public void setMessage(String message) {
        this.message = message;
    }

    public String getStatus() {
        return status;
    }

    public void setStatus(String status) {
        this.status = status;
    }

    public LocalDateTime getCreationTimestamp() {
        return creationTimestamp;
    }

    public void setCreationTimestamp(LocalDateTime creationTimestamp) {
        this.creationTimestamp = creationTimestamp;
    }

    @Override
    public String toString() {
        return "Notification{" +
                "notificationId=" + notificationId +
                ", username='" + username + '\'' +
                ", auctionId=" + auctionId +
                ", notificationType='" + notificationType + '\'' +
                ", message='" + message + '\'' +
                ", status=" + status +
                ", creationTimestamp=" + creationTimestamp +
                '}';
    }
}