package com.dietideals24.servlets;

import com.dietideals24.services.UserService;
import com.dietideals24.services.UserRepository;

import java.io.IOException;
import java.sql.SQLException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class LoginServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;
    private UserService userService = new UserService();

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {

        String error = request.getParameter("error");

        if (error != null && error.equals("not_logged_in")) {
            request.setAttribute("errorMessage", "Per fare un'offerta devi essere registrato e loggato.");
        }

        String username = request.getParameter("username");
        String password = request.getParameter("password");
        String role = request.getParameter("role");

        if (userService.loginUser(username, password, role)) {

            try {
                String email = UserRepository.getEmailByUsername(username);
                HttpSession session = request.getSession(true);
                session.setAttribute("role", role);
                session.setAttribute("username", username);
                session.setAttribute("email", email);
            } catch (SQLException e) {
                e.printStackTrace();
            }

            // Reindirizza alla pagina /index
            response.sendRedirect("/dietideals24/index");
        } else {
            // Se il login fallisce, mostra il messaggio di errore
            // Se il login fallisce, reindirizza alla pagina di login con un parametro di
            // errore
            if (role.equals("venditore"))
                response.sendRedirect("/dietideals24/auth-servlet?action=loginV&error=login_failed");
            else if (role.equals("compratore"))
                response.sendRedirect("/dietideals24/auth-servlet?action=login&error=login_failed");

        }
    }
}
