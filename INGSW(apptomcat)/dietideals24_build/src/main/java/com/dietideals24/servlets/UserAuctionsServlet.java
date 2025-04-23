package com.dietideals24.servlets;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.ServletContext;
import javax.servlet.http.*;
import org.thymeleaf.TemplateEngine;
import org.thymeleaf.context.WebContext;
import org.thymeleaf.templateresolver.ServletContextTemplateResolver;

@WebServlet("/user-auctions")
public class UserAuctionsServlet extends HttpServlet {
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

        String contentPage;
        if (role == null) {
            contentPage = "";
        } else if ("compratore".equals(role) && "my_auctions".equals(action)) {
            contentPage = "/pages/my_auctions.html";
        } else if ("venditore".equals(role) && "my_auctions".equals(action)) {
            contentPage = "/pages/my_auctions.html";
        } else {
            contentPage = "";
        }

        request.setAttribute("contentPage", contentPage);

        String actionUrl = request.getContextPath() + "/user-auctions";
        request.setAttribute("actionUrl", actionUrl);

        WebContext context = new WebContext(request, response, getServletContext());
        context.setVariable("contentPage", contentPage);
        context.setVariable("role", role);
        context.setVariable("username", username);
        context.setVariable("action", action);
        context.setVariable("actionUrl", actionUrl);

        templateEngine.process("user_auction_template", context, response.getWriter());
    }
}