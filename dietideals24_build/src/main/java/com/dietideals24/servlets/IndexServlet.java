package com.dietideals24.servlets;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.ServletContext;
import javax.servlet.http.*;
import org.thymeleaf.TemplateEngine;
import org.thymeleaf.context.WebContext;
import org.thymeleaf.templateresolver.ServletContextTemplateResolver;

import com.dietideals24.services.AuctionService;

public class IndexServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;
    private TemplateEngine templateEngine;
    private AuctionService auctionService;

    @Override
    public void init() throws ServletException {

        ServletContext servletContext = getServletContext();
        ServletContextTemplateResolver templateResolver = new ServletContextTemplateResolver(servletContext);
        templateResolver.setPrefix("/static/");
        templateResolver.setSuffix(".html");

        templateEngine = new TemplateEngine();
        templateEngine.setTemplateResolver(templateResolver);

        this.auctionService = new AuctionService();
    }

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        HttpSession session = request.getSession(false);
        String role = (session != null) ? (String) session.getAttribute("role") : null;
        String action = request.getParameter("action");
        String username = (session != null) ? (String) session.getAttribute("username") : null;

        String contentPage;

        if (role == null) {
            contentPage = "/pages/active_auctions.html";
        } else if ("compratore".equals(role) && "my_auctions".equals(action)) {
            contentPage = "/pages/my_auctions.html";
        } else if ("venditore".equals(role) && "my_auctions".equals(action)) {
            contentPage = "/pages/my_auctions.html";
        } else {
            contentPage = "/pages/active_auctions.html";
        }

        boolean hasUnread = false;
        if (username != null && !username.trim().isEmpty()) {
            try {

                hasUnread = this.auctionService.hasUnreadNotifications(username);
            } catch (Exception e) {

                System.err
                        .println("Errore durante la chiamata a auctionService.hasUnreadNotifications per " + username);
                e.printStackTrace();
                hasUnread = false;
            }
        }

        WebContext context = new WebContext(request, response, getServletContext(), request.getLocale());
        context.setVariable("contentPage", contentPage);
        context.setVariable("role", role);
        context.setVariable("action", action);
        context.setVariable("username", username);
        context.setVariable("hasUnreadNotifications", hasUnread);

        response.setContentType("text/html;charset=UTF-8");
        templateEngine.process("index_template", context, response.getWriter());
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doGet(req, resp);
    }

    @Override
    public void destroy() {

        super.destroy();
    }
}