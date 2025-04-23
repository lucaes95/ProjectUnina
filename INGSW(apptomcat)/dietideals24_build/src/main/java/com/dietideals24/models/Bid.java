package com.dietideals24.models;

import java.math.BigDecimal;
import java.sql.Timestamp;

public class Bid {

    private int id;
    private int auctionId;
    private String userId;
    private BigDecimal bidPrice;
    private Timestamp bidTime;

    public Bid() {
    }

    public Bid(int id, int auctionId, String userId, BigDecimal bidPrice, Timestamp bidTime) {
        this.id = id;
        this.auctionId = auctionId;
        this.userId = userId;
        this.bidPrice = bidPrice;
        this.bidTime = bidTime;
    }

    // Getters e Setters
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getAuctionId() {
        return auctionId;
    }

    public void setAuctionId(int auctionId) {
        this.auctionId = auctionId;
    }

    public String getUserId() {
        return userId;
    }

    public void setUserId(String userId) {
        this.userId = userId;
    }

    public BigDecimal getBidPrice() {
        return bidPrice;
    }

    public void setBidPrice(BigDecimal bidPrice) {
        this.bidPrice = bidPrice;
    }

    public Timestamp getBidTime() {
        return bidTime;
    }

    public void setBidTime(Timestamp bidTime) {
        this.bidTime = bidTime;
    }

    // Override del metodo toString per un facile debug
    @Override
    public String toString() {
        return "Bid{id=" + id + ", auctionId=" + auctionId + ", userId=" + userId + ", bidPrice=" + bidPrice
                + ", bidTime=" + bidTime + "}";
    }
}
