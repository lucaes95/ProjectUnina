package com.dietideals24.servlets;

import com.dietideals24.services.AuctionService;
import com.dietideals24.models.Auction;
import com.google.gson.Gson;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/auction-details")
public class AuctionDetailsServlet extends HttpServlet {

    private final AuctionService auctionService = new AuctionService();

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("application/json");
        response.setCharacterEncoding("UTF-8");

        String auctionIdParam = request.getParameter("id");
        String username = (String) request.getSession().getAttribute("username");
        String role = (String) request.getSession().getAttribute("role");

        if (auctionIdParam != null) {
            try {
                int auctionId = Integer.parseInt(auctionIdParam);
                Auction auction = auctionService.getAuctionById(auctionId);

                if (auction == null) {
                    response.setStatus(HttpServletResponse.SC_NOT_FOUND);
                    response.getWriter().write("{\"error\":\"Asta non trovata\"}");
                    return;
                }

                Gson gson = new Gson();

                String json = gson.toJson(new AuctionResponse(auction, username, role));
                response.getWriter().write(json);
            } catch (NumberFormatException e) {
                response.setStatus(HttpServletResponse.SC_BAD_REQUEST);
                response.getWriter().write("{\"error\":\"ID asta non valido\"}");
            }
        } else {
            response.setStatus(HttpServletResponse.SC_BAD_REQUEST);
            response.getWriter().write("{\"error\":\"Parametro ID asta mancante\"}");
        }
    }

    @SuppressWarnings("unused")
    private static class AuctionResponse {
        private final Auction auction;
        private final String username;
        private final String role;

        public AuctionResponse(Auction auction, String username, String role) {
            this.auction = auction;
            this.username = username;
            this.role = role;
        }
    }
}
