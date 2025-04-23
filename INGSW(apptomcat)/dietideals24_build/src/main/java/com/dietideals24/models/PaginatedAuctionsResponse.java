package com.dietideals24.models; // <--- Package corretto

import java.util.List;

public class PaginatedAuctionsResponse {

    public List<Auction> auctions;
    public boolean hasMore;

    public PaginatedAuctionsResponse(List<Auction> auctions, boolean hasMore) {
        this.auctions = auctions;
        this.hasMore = hasMore;
    }

}