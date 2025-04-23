package com.dietideals24.servlets;

import com.dietideals24.models.UserProfile;
import com.dietideals24.services.UserProfileService;
import com.google.gson.Gson;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.sql.SQLException;

@WebServlet("/editProfile")
public class EditProfileServlet extends HttpServlet {

    private final Gson gson = new Gson();

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {

        HttpSession session = request.getSession();
        String email = (String) session.getAttribute("email");

        response.setContentType("application/json;charset=UTF-8");

        if (email == null) {
            response.getWriter().print(gson.toJson(new ErrorResponse("User not logged in")));
            return;
        }

        StringBuilder sb = new StringBuilder();
        try (BufferedReader reader = request.getReader()) {
            String line;
            while ((line = reader.readLine()) != null) {
                sb.append(line);
            }
        }
        String json = sb.toString();

        UserProfile updatedProfile = gson.fromJson(json, UserProfile.class);
        updatedProfile.setEmail(email);

        String username = (String) session.getAttribute("username");

        try {
            // Salva il profilo (inserisce o aggiorna in base alla presenza della email nel
            // DB)
            UserProfileService.saveProfile(updatedProfile, username);
            response.getWriter().print(gson.toJson(new SuccessResponse("Profile aggiornato")));
        } catch (SQLException e) {
            e.printStackTrace();
            response.getWriter().print(gson.toJson(new ErrorResponse("Errore durante il salvataggio del profilo")));
        }
    }

    // Classe interna per gestire le risposte di errore
    @SuppressWarnings("unused")
    private static class ErrorResponse {
        private final String error;

        public ErrorResponse(String error) {
            this.error = error;
        }
    }

    // Classe interna per gestire le risposte di successo
    @SuppressWarnings("unused")
    private static class SuccessResponse {
        private final String message;

        public SuccessResponse(String message) {
            this.message = message;
        }
    }
}