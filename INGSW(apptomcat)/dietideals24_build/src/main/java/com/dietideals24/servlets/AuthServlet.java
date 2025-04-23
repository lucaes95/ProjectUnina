package com.dietideals24.servlets;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.ServletContext;
import javax.servlet.http.*;
import javax.servlet.annotation.WebServlet;
import org.thymeleaf.TemplateEngine;
import org.thymeleaf.context.WebContext;
import org.thymeleaf.templateresolver.ServletContextTemplateResolver;

@WebServlet("/auth-servlet")
public class AuthServlet extends HttpServlet {
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

        if ("login".equals(action) || "loginV".equals(action)) {
            contentPage = "/auth/login.html";
        } else if ("register".equals(action) || "registerV".equals(action)) {
            contentPage = "/auth/register.html";
        } else {
            response.sendError(HttpServletResponse.SC_BAD_REQUEST, "Azione non valida");
            return;
        }

        request.setAttribute("contentPage", contentPage);

        String error = request.getParameter("error");
        String success = request.getParameter("success");

        WebContext context = new WebContext(request, response, getServletContext());
        context.setVariable("contentPage", contentPage);
        context.setVariable("action", action);
        context.setVariable("error", error);
        context.setVariable("success", success);

        templateEngine.process("auth_template", context, response.getWriter());
    }
}
