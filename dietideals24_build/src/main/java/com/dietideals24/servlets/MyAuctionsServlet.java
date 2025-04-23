package com.dietideals24.servlets;

import com.dietideals24.services.AuctionService;
import com.dietideals24.models.Auction;
import com.dietideals24.models.PaginatedAuctionsResponse;
import com.google.gson.Gson;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;

@WebServlet("/my-auctions")
public class MyAuctionsServlet extends HttpServlet {
    private AuctionService auctionService = new AuctionService();
    private final Gson gson = new Gson();

    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {

        System.out.println("La servlet è stata chiamata correttamente!");
        HttpSession session = request.getSession(false);

        String userId = (String) session.getAttribute("username");

        if (session == null || userId == null) {
            response.sendRedirect("login.html");
            return;
        }

        String userRole = (String) session.getAttribute("role");

        response.setContentType("application/json");
        response.setCharacterEncoding("UTF-8");

        String pageParam = request.getParameter("page");
        String pageSizeParam = request.getParameter("pageSize");
        String keyword = request.getParameter("keyword");
        String filterType = request.getParameter("filterType");

        String category = request.getParameter("category");

        int page = (pageParam != null) ? Integer.parseInt(pageParam) : 1;
        int pageSize = (pageSizeParam != null) ? Integer.parseInt(pageSizeParam) : 9;

        int limit = pageSize + 1;

        List<Auction> potentialAuctions = auctionService.getUserAuctions(userId, keyword, userRole, page, pageSize,
                filterType, category, limit);

        boolean hasMore = potentialAuctions.size() > pageSize;

        List<Auction> auctionsToSend = hasMore ? potentialAuctions.subList(0, pageSize) : potentialAuctions;

        PaginatedAuctionsResponse paginatedResponse = new PaginatedAuctionsResponse(auctionsToSend, hasMore);

        String json = gson.toJson(paginatedResponse);

        try (PrintWriter out = response.getWriter()) {
            out.print(json);
            out.flush();
        } catch (Exception e) {
            e.printStackTrace();
            response.setStatus(HttpServletResponse.SC_INTERNAL_SERVER_ERROR);
            response.getWriter().write("{\"error\": \"Errore durante la serializzazione JSON.\"}");
        }
    }
}
