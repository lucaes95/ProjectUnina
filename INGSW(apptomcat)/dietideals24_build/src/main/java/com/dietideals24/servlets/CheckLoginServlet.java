package com.dietideals24.servlets;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

@WebServlet("/check-login")
public class CheckLoginServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {

        HttpSession session = request.getSession(false);

        // Verifica se la sessione esiste e se l'utente è loggato
        boolean isLoggedIn = session != null && session.getAttribute("username") != null;

        response.setContentType("application/json");
        response.getWriter().write("{\"isLoggedIn\": " + isLoggedIn + "}");
    }
}