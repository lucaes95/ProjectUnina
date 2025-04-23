package com.dietideals24.utils;

import org.mindrot.jbcrypt.BCrypt;

public class PasswordUtil {

    // Metodo per generare un hash della password
    public static String hashPassword(String password) {
        return BCrypt.hashpw(password, BCrypt.gensalt());
    }

    // Metodo per verificare se una password inserita corrisponde a quella salvata
    public static boolean checkPassword(String password, String hashedPassword) {
        return BCrypt.checkpw(password, hashedPassword);
    }
}