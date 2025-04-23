package com.dietideals24.servlets;

import com.google.gson.Gson;
import com.dietideals24.services.BidService;
import com.dietideals24.models.Bid;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.sql.SQLException;
import java.util.List;

@WebServlet("/auction-bid-details")
public class AuctionBidDetailsServlet extends HttpServlet {

    private BidService bidService = new BidService();

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {

        String auctionId = request.getParameter("id");

        if (auctionId == null || auctionId.isEmpty()) {
            response.setStatus(HttpServletResponse.SC_BAD_REQUEST);
            response.getWriter().write("{\"error\": \"ID asta mancante\"}");
            return;
        }

        try {
            List<Bid> bids = bidService.getBidsForAuction(auctionId);
            String jsonResponse = new Gson().toJson(bids);

            response.setContentType("application/json");
            response.getWriter().write(jsonResponse);

        } catch (SQLException e) {
            response.setStatus(HttpServletResponse.SC_INTERNAL_SERVER_ERROR);
            response.getWriter().write("{\"error\": \"Errore nel recupero dei dati\"}");
        }
    }
}
