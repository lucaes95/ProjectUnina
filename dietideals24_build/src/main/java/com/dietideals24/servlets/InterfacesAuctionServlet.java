package com.dietideals24.servlets;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.ServletContext;
import javax.servlet.http.*;
import javax.servlet.annotation.WebServlet;
import org.thymeleaf.TemplateEngine;
import org.thymeleaf.context.WebContext;
import org.thymeleaf.templateresolver.ServletContextTemplateResolver;

@WebServlet("/interfaces-auction")
public class InterfacesAuctionServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;
    private TemplateEngine templateEngine;

    @Override
    public void init() throws ServletException {
        ServletContext servletContext = getServletContext();
        ServletContextTemplateResolver templateResolver = new ServletContextTemplateResolver(servletContext);
        templateResolver.setPrefix("/static/");
        templateResolver.setSuffix(".html");

        templateEngine = new TemplateEngine();
        templateEngine.setTemplateResolver(templateResolver);
    }

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        HttpSession session = request.getSession(false);
        String role = (session != null) ? (String) session.getAttribute("role") : null;
        String username = (session != null) ? (String) session.getAttribute("username") : null;
        String action = request.getParameter("action");
        String menuCategory = "/includes/menu_category.html";
        String contentPage;

        if (role == null || action == null) {
            contentPage = "";
        } else if ("compratore".equals(role) && "inversa".equals(action)) {
            contentPage = "/pages/create_auction_buyer_inversa.html";
        } else if ("venditore".equals(role) && "ribasso".equals(action)) {
            contentPage = "/pages/create_auction_seller_alribasso.html";
        } else if ("venditore".equals(role) && "silenziosa".equals(action)) {
            contentPage = "/pages/create_auction_seller_silenziosa.html";
        } else {
            contentPage = "";
            response.sendError(HttpServletResponse.SC_BAD_REQUEST, "Azione non valida");
            return;
        }

        request.setAttribute("contentPage", contentPage);
        request.setAttribute("menuCategory", menuCategory);

        WebContext context = new WebContext(request, response, getServletContext());
        context.setVariable("contentPage", contentPage);
        context.setVariable("menuCategory", menuCategory);
        context.setVariable("role", role);
        context.setVariable("action", action);
        context.setVariable("username", username);

        templateEngine.process("create_auction_template", context, response.getWriter());
    }
}
