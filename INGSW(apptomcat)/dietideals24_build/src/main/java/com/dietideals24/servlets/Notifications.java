package com.dietideals24.servlets;

import com.dietideals24.models.Notification;
import com.dietideals24.services.NotificationService;
import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.google.gson.TypeAdapter;
import com.google.gson.stream.JsonReader;
import com.google.gson.stream.JsonToken;
import com.google.gson.stream.JsonWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import java.io.IOException;
import java.sql.SQLException;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.List;

@WebServlet("/notifications")
public class Notifications extends HttpServlet {
    private static final long serialVersionUID = 1L;

    private NotificationService notificationService;
    private Gson gson;

    @Override
    public void init() throws ServletException {
        this.notificationService = new NotificationService();

        this.gson = new GsonBuilder()
                .registerTypeAdapter(LocalDateTime.class, new TypeAdapter<LocalDateTime>() {
                    private final DateTimeFormatter formatter = DateTimeFormatter.ISO_LOCAL_DATE_TIME;

                    @Override
                    public void write(JsonWriter out, LocalDateTime value) throws IOException {
                        if (value == null) {
                            out.nullValue();
                        } else {
                            out.value(value.format(formatter));
                        }
                    }

                    @Override
                    public LocalDateTime read(JsonReader in) throws IOException {
                        if (in.peek() == JsonToken.NULL) {
                            in.nextNull();
                            return null;
                        } else {
                            return LocalDateTime.parse(in.nextString(), formatter);
                        }
                    }
                })
                .create();
    }

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        HttpSession session = request.getSession(false);
        String username = (session != null) ? (String) session.getAttribute("username") : null;

        if (username == null) {
            response.sendError(HttpServletResponse.SC_UNAUTHORIZED, "Utente non autenticato.");
            return;
        }
        try {
            List<Notification> notifications = notificationService.getNotificationsForUser(username);
            response.setContentType("application/json");
            response.setCharacterEncoding("UTF-8");
            String jsonResponse = gson.toJson(notifications);
            response.getWriter().write(jsonResponse);
        } catch (Exception e) {
            System.err.println("Errore in doGet /notifications per utente " + username);
            e.printStackTrace();
            response.sendError(HttpServletResponse.SC_INTERNAL_SERVER_ERROR,
                    "Errore durante il recupero delle notifiche.");
        }
    }

    @Override
    protected void doPut(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        HttpSession session = request.getSession(false);
        String username = (session != null) ? (String) session.getAttribute("username") : null;

        if (username == null) {
            response.sendError(HttpServletResponse.SC_UNAUTHORIZED, "Utente non autenticato.");
            return;
        }
        try {
            boolean success = notificationService.markAllNotificationsAsRead(username);
            if (success) {
                response.setStatus(HttpServletResponse.SC_NO_CONTENT);
                System.out.println("Servlet /notifications (PUT): Notifiche segnate come lette per " + username);
            } else {
                System.out.println(
                        "Servlet /notifications (PUT): Nessuna notifica aggiornata a READ (o errore lieve) per "
                                + username);
                response.setStatus(HttpServletResponse.SC_NO_CONTENT);
            }
        } catch (Exception e) {
            System.err.println("Errore in doPut /notifications per utente " + username);
            e.printStackTrace();
            response.sendError(HttpServletResponse.SC_INTERNAL_SERVER_ERROR,
                    "Errore durante l'aggiornamento dello stato delle notifiche.");
        }
    }

    @Override
    protected void doDelete(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {

        HttpSession session = request.getSession(false);
        String username = (session != null) ? (String) session.getAttribute("username") : null;

        if (username == null) {
            response.sendError(HttpServletResponse.SC_UNAUTHORIZED, "Utente non autenticato per eliminare notifiche.");
            return;
        }

        String idParam = request.getParameter("id");

        if (idParam != null && !idParam.trim().isEmpty()) {

            handleDeleteSingleNotification(request, response, username, idParam);
        } else {

            handleDeleteAllNotifications(request, response, username);
        }
    }

    private void handleDeleteSingleNotification(HttpServletRequest request, HttpServletResponse response,
            String username, String idParam) throws IOException {
        int notificationId;
        try {
            notificationId = Integer.parseInt(idParam);
            if (notificationId <= 0) {
                throw new NumberFormatException("ID notifica non valido (deve essere positivo).");
            }
        } catch (NumberFormatException e) {
            response.sendError(HttpServletResponse.SC_BAD_REQUEST,
                    "Parametro 'id' non valido: " + e.getMessage());
            return;
        }

        try {
            System.out.println("Servlet /notifications (DELETE Single): Tentativo eliminazione ID " + notificationId
                    + " per utente " + username);
            boolean success = notificationService.deleteNotification(notificationId, username);

            if (success) {
                response.setStatus(HttpServletResponse.SC_NO_CONTENT); // 204 No Content
                System.out.println("Servlet /notifications (DELETE Single): Notifica ID " + notificationId
                        + " eliminata per utente " + username);
            } else {
                response.sendError(HttpServletResponse.SC_NOT_FOUND,
                        "Notifica ID " + notificationId + " non trovata o non appartenente all'utente.");
                System.out.println("Servlet /notifications (DELETE Single): Notifica ID " + notificationId
                        + " non trovata per utente " + username);
            }
        } catch (Exception e) {
            System.err.println(
                    "Errore in doDelete (Single) /notifications per utente " + username + ", ID " + notificationId);
            e.printStackTrace();
            response.sendError(HttpServletResponse.SC_INTERNAL_SERVER_ERROR,
                    "Errore interno durante l'eliminazione della notifica ID " + notificationId);
        }
    }

    private void handleDeleteAllNotifications(HttpServletRequest request, HttpServletResponse response, String username)
            throws IOException {
        try {
            System.out.println(
                    "Servlet /notifications (DELETE All): Tentativo eliminazione TUTTE le notifiche per utente "
                            + username);

            int deletedCount = notificationService.deleteAllNotificationsForUser(username);

            System.out.println("Servlet /notifications (DELETE All): Eliminate " + deletedCount
                    + " notifiche per utente " + username);
            response.setStatus(HttpServletResponse.SC_NO_CONTENT);

        } catch (SQLException e) {
            System.err.println("Errore SQL in doDelete (All) /notifications per utente " + username);
            e.printStackTrace();
            response.sendError(HttpServletResponse.SC_INTERNAL_SERVER_ERROR,
                    "Errore database durante l'eliminazione di tutte le notifiche.");
        } catch (Exception e) {
            System.err.println("Errore generico in doDelete (All) /notifications per utente " + username);
            e.printStackTrace();
            response.sendError(HttpServletResponse.SC_INTERNAL_SERVER_ERROR,
                    "Errore interno generico durante l'eliminazione di tutte le notifiche.");
        }
    }

}