package com.dietideals24.servlets;

import com.google.gson.Gson;
import com.dietideals24.services.AuctionService;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet("/accept-bid")
public class AcceptBidServlet extends HttpServlet {

    private final AuctionService auctionService = new AuctionService();
    private final Gson gson = new Gson();

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("application/json;charset=UTF-8");
        PrintWriter out = response.getWriter();

        try {
            int auctionId = Integer.parseInt(request.getParameter("auctionId"));
            int bidId = Integer.parseInt(request.getParameter("bidId"));

            boolean success = auctionService.acceptBid(auctionId, bidId);

            if (success) {
                // Reindirizza alla pagina dell'asta corrispondente
                out.print(gson.toJson(new Response(true, "Offerta accettata con successo!")));
            } else {
                out.print(gson.toJson(new Response(false, "Errore durante l'accettazione dell'offerta.")));
            }
        } catch (Exception e) {
            e.printStackTrace();
            out.print(gson.toJson(new Response(false, "Parametri non validi.")));
        } finally {
            out.flush();
        }
    }

    @SuppressWarnings("unused")
    private class Response {
        private final boolean success;
        private final String message;

        public Response(boolean success, String message) {
            this.success = success;
            this.message = message;
        }
    }
}
