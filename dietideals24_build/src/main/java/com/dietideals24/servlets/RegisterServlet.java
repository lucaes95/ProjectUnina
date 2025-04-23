package com.dietideals24.servlets;

import com.dietideals24.models.UserProfile;
import com.dietideals24.services.UserProfileService;
import com.dietideals24.services.UserService;

import java.io.IOException;
import java.sql.SQLException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/register")
public class RegisterServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;

    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {

        String email = request.getParameter("email");
        String firstName = request.getParameter("firstName");
        String lastName = request.getParameter("lastName");

        String username = request.getParameter("username");
        String password = request.getParameter("password");
        String role = request.getParameter("role");

        UserService userService = new UserService();
        Boolean isRegistered = userService.registerUser(email, username, password, role);

        UserProfile newProfile = new UserProfile(email, firstName, lastName, username);

        if (isRegistered != null) {

            try {
                UserProfileService.createBasicProfile(newProfile);
            } catch (SQLException e) {
                e.printStackTrace();
            }

            if (role.equals("venditore"))
                response.sendRedirect("/dietideals24/auth-servlet?action=registerV&success=successful_registration");
            else if (role.equals("compratore"))
                response.sendRedirect("/dietideals24/auth-servlet?action=register&success=successful_registration");
        } else {

            if (role.equals("venditore"))
                response.sendRedirect("/dietideals24/auth-servlet?action=registerV&error=register_failed");
            else if (role.equals("compratore"))
                response.sendRedirect("/dietideals24/auth-servlet?action=register&error=register_failed");
        }
    }
}