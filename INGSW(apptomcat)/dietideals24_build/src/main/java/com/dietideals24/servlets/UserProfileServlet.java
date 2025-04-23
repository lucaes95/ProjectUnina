package com.dietideals24.servlets;

import com.dietideals24.models.UserProfile;
import com.dietideals24.services.UserProfileService;
import com.google.gson.Gson;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.SQLException;

@WebServlet("/userProfile")
public class UserProfileServlet extends HttpServlet {

    private final Gson gson = new Gson();

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        HttpSession session = request.getSession();
        String email = (String) session.getAttribute("email");

        response.setContentType("application/json;charset=UTF-8");
        PrintWriter out = response.getWriter();

        UserProfile profile = null;

        String usernameParam = request.getParameter("username");
        try {
            if (usernameParam != null && !usernameParam.isEmpty()) {
                profile = UserProfileService.getProfileByUsername(usernameParam);
            } else {
                profile = UserProfileService.getProfile(email);
            }
        } catch (NumberFormatException e) {
            out.print(gson.toJson(new ErrorResponse("Invalid username parameter")));
            return;
        } catch (SQLException e) {
            e.printStackTrace();
            out.print(gson.toJson(new ErrorResponse("Error retrieving profile data")));
            return;
        }

        out.print(gson.toJson(profile));
    }

    @SuppressWarnings("unused")
    private static class ErrorResponse {
        private final String error;

        public ErrorResponse(String error) {
            this.error = error;
        }
    }
}
