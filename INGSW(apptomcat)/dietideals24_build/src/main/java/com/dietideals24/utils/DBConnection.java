package com.dietideals24.utils;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class DBConnection {

    // Parametri di connessione configurati nel docker-compose
    private static final String DB_URL = "jdbc:mysql://mariadb:3306/auth_db"; // Cambiato per usare il nome del
                                                                              // container 'mariadb' e la porta 3306
    private static final String DB_USER = "user"; // Utente definito nel docker-compose
    private static final String DB_PASSWORD = "password"; // Password definita nel docker-compose

    public static Connection getConnection() throws SQLException {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            return DriverManager.getConnection(DB_URL, DB_USER, DB_PASSWORD);
        } catch (ClassNotFoundException e) {
            throw new SQLException("Driver MySQL non trovato", e);
        }
    }
}
