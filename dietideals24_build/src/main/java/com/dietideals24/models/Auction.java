package com.dietideals24.models;

import java.math.BigDecimal;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Timestamp;
import java.sql.Types;

public class Auction {
    private int auctionId;
    private String sellerId;
    private String buyerId;
    private String title;
    private String description;
    private String category;
    private String auctionType;
    private BigDecimal startPrice;
    private BigDecimal currentPrice;
    private BigDecimal minPrice;
    private BigDecimal decrementAmount;
    private Integer decrementIntervalMinutes;
    private Timestamp startTime;
    private Timestamp endTime;
    private String status;
    private String winnerId;
    private String imagePath;

    // Costruttore vuoto richiesto per la creazione degli oggetti senza parametri
    public Auction() {
    }

    public Auction(int auctionId, String sellerId, String buyerId, String title, String description, String category,
            String auctionType,
            BigDecimal startPrice, BigDecimal currentPrice, BigDecimal minPrice,
            BigDecimal decrementAmount, Integer decrementIntervalMinutes,
            Timestamp startTime, Timestamp endTime, String status, String winnerId, String imagePath) {
        this.auctionId = auctionId;
        this.sellerId = sellerId;
        this.buyerId = buyerId;
        this.title = title;
        this.description = description;
        this.category = category;
        this.auctionType = auctionType;
        this.startPrice = startPrice;
        this.currentPrice = currentPrice;
        this.minPrice = minPrice;
        this.decrementAmount = decrementAmount;
        this.decrementIntervalMinutes = decrementIntervalMinutes;
        this.startTime = startTime;
        this.endTime = endTime;
        this.status = status;
        this.winnerId = winnerId;
        this.imagePath = imagePath;
    }

    // Metodo helper per impostare Timestamp o NULL
    private void setTimestampOrNull(PreparedStatement s, int index, Timestamp value) throws SQLException {
        if (value != null) {
            s.setTimestamp(index, value);
        } else {
            s.setNull(index, Types.TIMESTAMP);
        }
    }

    // Metodo helper per impostare BigDecimal o NULL
    private void setBigDecimalOrNull(PreparedStatement s, int index, BigDecimal value) throws SQLException {
        if (value != null) {
            s.setBigDecimal(index, value);
        } else {
            s.setNull(index, Types.DECIMAL);
        }
    }

    public void prepareStatementForInsert(PreparedStatement stmt) throws SQLException {
        stmt.setString(1, sellerId);
        stmt.setString(2, buyerId);
        stmt.setString(3, title);
        stmt.setString(4, description);
        stmt.setString(5, category);
        stmt.setString(6, auctionType);
        setBigDecimalOrNull(stmt, 7, this.startPrice);
        setBigDecimalOrNull(stmt, 8, this.currentPrice);
        setBigDecimalOrNull(stmt, 9, this.minPrice);
        setBigDecimalOrNull(stmt, 10, this.decrementAmount);
        stmt.setObject(11, decrementIntervalMinutes, java.sql.Types.INTEGER);
        setTimestampOrNull(stmt, 12, this.startTime);
        setTimestampOrNull(stmt, 13, this.endTime);

        // Se la data di fine è passata, imposta lo stato su "scaduta"
        stmt.setString(14, this.status);
        stmt.setString(15, winnerId);
        stmt.setString(16, imagePath);
    }

    public static Auction fromResultSet(ResultSet rs) throws SQLException {
        return new Auction(
                rs.getInt("auction_id"),
                rs.getString("seller_id") != null ? rs.getString("seller_id") : null,
                rs.getString("buyer_id") != null ? rs.getString("buyer_id") : null,
                rs.getString("title"),
                rs.getString("description"),
                rs.getString("category"),
                rs.getString("auction_type"),
                rs.getBigDecimal("start_price"),
                rs.getBigDecimal("current_price"),
                rs.getBigDecimal("min_price"),
                rs.getBigDecimal("decrement_amount"),
                rs.getObject("decrement_interval_minutes") != null ? rs.getInt("decrement_interval_minutes") : null,
                rs.getTimestamp("start_time"),
                rs.getTimestamp("end_time"),
                rs.getString("status"),
                rs.getString("winner_id") != null ? rs.getString("winner_id") : null,
                rs.getString("image_path"));
    }

    // Getters e Setters
    public int getAuctionId() {
        return auctionId;
    }

    public void setAuctionId(int auctionId) {
        this.auctionId = auctionId;
    }

    public String getSellerId() {
        return sellerId;
    }

    public void setSellerId(String sellerId) {
        this.sellerId = sellerId;
    }

    public String getBuyerId() {
        return buyerId;
    }

    public void setBuyerId(String buyerId) {
        this.buyerId = buyerId;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public String getAuctionType() {
        return auctionType;
    }

    public void setAuctionType(String auctionType) {
        this.auctionType = auctionType;
    }

    public BigDecimal getStartPrice() {
        return startPrice;
    }

    public void setStartPrice(BigDecimal startPrice) {
        this.startPrice = startPrice;
    }

    public BigDecimal getCurrentPrice() {
        return currentPrice;
    }

    public String getWinnerId() {
        return winnerId;
    }

    public void setWinnerId(String winnerId) {
        this.winnerId = winnerId;
    }

    public void setCurrentPrice(BigDecimal currentPrice) {
        this.currentPrice = currentPrice;
    }

    public BigDecimal getMinPrice() {
        return minPrice;
    }

    public void setMinPrice(BigDecimal minPrice) {
        this.minPrice = minPrice;
    }

    public BigDecimal getDecrementAmount() {
        return decrementAmount;
    }

    public void setDecrementAmount(BigDecimal decrementAmount) {
        this.decrementAmount = decrementAmount;
    }

    public Integer getDecrementIntervalMinutes() {
        return decrementIntervalMinutes;
    }

    public void setDecrementIntervalMinutes(int decrementIntervalMinutes) {
        this.decrementIntervalMinutes = decrementIntervalMinutes;
    }

    public Timestamp getStartTime() {
        return startTime;
    }

    public void setStartTime(Timestamp startTime) {
        this.startTime = startTime;
    }

    public Timestamp getEndTime() {
        return endTime;
    }

    public void setEndTime(Timestamp endTime) {
        this.endTime = endTime;
    }

    public String getStatus() {
        return status;
    }

    public void setStatus(String status) {
        this.status = status;
    }

    public String getCategory() {
        return category;
    }

    public void setCategory(String category) {
        this.category = category;
    }

    public String getImagePath() {
        return imagePath;
    }

    public void setImagePath(String imagePath) {
        this.imagePath = imagePath;
    }

    @Override
    public String toString() {
        return "Auction{" +
                "auctionId=" + auctionId +
                ", sellerId=" + sellerId +
                ", buyerId=" + buyerId +
                ", title='" + title + '\'' +
                ", description='" + description + '\'' +
                ", category='" + category + '\'' +
                ", auctionType='" + auctionType + '\'' +
                ", startPrice=" + startPrice +
                ", currentPrice=" + currentPrice +
                ", minPrice=" + minPrice +
                ", decrementAmount=" + decrementAmount +
                ", decrementIntervalMinutes=" + decrementIntervalMinutes +
                ", startTime=" + startTime +
                ", endTime=" + endTime +
                ", status='" + status + '\'' +
                ", winnerID=" + winnerId +
                ", imagePath='" + imagePath + '\'' + '}';
    }
}
