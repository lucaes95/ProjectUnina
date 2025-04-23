package com.dietideals24.utils;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class DBConnection {

    private static final String DB_URL = "jdbc:mysql://mariadb:3306/auth_db";
    private static final String DB_USER = "user";
    private static final String DB_PASSWORD = "password";

    public static Connection getConnection() throws SQLException {
        String env = System.getProperty("env");
        if ("test".equalsIgnoreCase(env)) {
            return TestDBConfig.getConnection();
        }
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            return DriverManager.getConnection(DB_URL, DB_USER, DB_PASSWORD);
        } catch (ClassNotFoundException e) {
            throw new SQLException("Driver MySQL non trovato", e);
        }
    }
}
