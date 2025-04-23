package com.dietideals24.servlets;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.ServletContext;
import javax.servlet.http.*;
import org.thymeleaf.TemplateEngine;
import org.thymeleaf.context.WebContext;
import org.thymeleaf.templateresolver.ServletContextTemplateResolver;

@WebServlet("/profile")
public class ProfileServlet extends HttpServlet {
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
        String action = request.getParameter("action");
        String contentPage;
        HttpSession session = request.getSession(false);

        String role = null;
        String username = null;

        if (session != null) {
            role = (String) session.getAttribute("role");
            username = (String) session.getAttribute("username");
        }

        if (!"edit".equals(action)) {
            contentPage = "/pages/profile_user.html";
        } else if ("edit".equals(action) || action == null) {
            contentPage = "/pages/editProfile.html";
        } else {
            response.sendError(HttpServletResponse.SC_BAD_REQUEST, "Azione non valida");
            return;
        }

        request.setAttribute("contentPage", contentPage);

        WebContext context = new WebContext(request, response, getServletContext());
        context.setVariable("contentPage", contentPage);
        context.setVariable("action", action);
        context.setVariable("role", role);
        context.setVariable("username", username);

        templateEngine.process("profile_template", context, response.getWriter());
    }
}
