package com.dietideals24.servlets;

import com.dietideals24.services.AuctionService;
import com.dietideals24.models.Auction;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;

@WebServlet("/make-bid")
public class MakeBidServlet extends HttpServlet {

    private final AuctionService auctionService = new AuctionService();

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {

        HttpSession session = request.getSession(false);

        if (session == null) {
            response.sendRedirect("/dietideals24/static/auth/login.html?error=not_logged_in");
            return;
        }

        String auctionIdParam = request.getParameter("auctionId");
        String bidpriceParam = request.getParameter("offer");
        String username = (String) session.getAttribute("username");

        if (auctionIdParam == null || bidpriceParam == null || username == null) {
            response.setStatus(HttpServletResponse.SC_BAD_REQUEST);
            response.getWriter().write("{\"error\":\"Dati mancanti (ID asta o offerta o utente)\"}");
            return;
        }

        try {
            int auctionId = Integer.parseInt(auctionIdParam);

            Auction auction = auctionService.getAuctionById(auctionId);

            double bidprice = Double.parseDouble(bidpriceParam);

            String auctionType = auction.getAuctionType();

            long waitTime = auctionService.getWaitTimeForNextBid(auctionId, username);

            double currentPrice = 0;
            double minPrice = 0;

            // Controllo la possibilità o quanto tempo manca prima di effettuare una nuova
            // offerta
            if (waitTime > 0) {

                response.sendRedirect("/dietideals24/auction?id=" + auctionId + "&errmsg=failed_bid_wait" + waitTime);

                return;
            }

            // **Controllo se l'utente è il creatore dell'asta**
            if (auctionService.isUserAuctionCreator(auctionId, username)) {

                response.sendRedirect("/dietideals24/auction?id=" + auctionId + "&errmsg=failed_bid_personal_auction");

                return;
            }

            if (!auction.getAuctionType().equals("silenziosa")) {
                currentPrice = auction.getCurrentPrice().doubleValue();
            }

            if (auction.getAuctionType().equals("ribasso")) {
                minPrice = auction.getMinPrice().doubleValue();
            }

            // Validità azione offerta Asta Inversa
            if (auctionType.equals("inversa")) {
                // Controllo del prezzo dell'offerta in base al tipo dell'asta
                if (bidprice >= currentPrice) {

                    response.sendRedirect(
                            "/dietideals24/auction?id=" + auctionId + "&errmsg=failed_bid_inversa_higher");
                    return;
                }

                if (auctionService.isUserWinner(auctionId, username)) {

                    response.sendRedirect("/dietideals24/auction?id=" + auctionId + "&errmsg=failed_bid_winner");
                    return;
                }
            }

            // Validità azione Asta Al Ribasso
            if (auctionType.equals("ribasso")) {
                // Verifica che l'offerta sia maggiore del prezzo attuale
                if (bidprice > currentPrice) {

                    response.sendRedirect(
                            "/dietideals24/auction?id=" + auctionId + "&errmsg=failed_bid_ribasso_higher");

                    return;
                }
            }

            // Creazione dell'offerta e aggiornamento del prezzo dell'asta
            if (auctionService.createBid(auctionId, bidprice, username)) {
                // Aggiorna il prezzo dell'asta con la nuova offerta
                if (auctionType.equals("ribasso")) {

                    if (bidprice >= minPrice) {
                        auctionService.updateAuctionRibasso(auctionId, bidprice, username, true);
                    } else {
                        auctionService.updateAuctionRibasso(auctionId, bidprice, username, false);
                    }

                } else if (auctionType.equals("inversa")) {
                    if (bidprice < currentPrice) {

                        auctionService.updateAuctionPriceInversa(auctionId, bidprice, username);
                    } else {
                        response.sendRedirect(
                                "/dietideals24/auction?id=" + auctionId + "&errmsg=failed_bid_inversa_higher");
                        return;
                    }
                }
                // Asta silenziosa
                else {
                    auctionService.updateAuctionPrice(auctionId, bidprice, username);
                }

                // Risposta di successo
                response.sendRedirect("/dietideals24/auction?id=" + auctionId + "&success=successful_bid");

            } else {

                response.sendRedirect("/dietideals24/auction?id=" + auctionId + "&errmsg=failed_bid_insert");
            }

        } catch (

        NumberFormatException e) {
            response.setStatus(HttpServletResponse.SC_BAD_REQUEST);
            response.getWriter().write("{\"error\":\"Dati non validi\"}");
        }
    }
}
