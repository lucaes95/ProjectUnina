package com.dietideals24.utils;

import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.BeforeAll;

public abstract class BaseIntegrationTest {

    @BeforeAll
    public static void setUpDatabase() throws Exception {
        System.out.println("--- BASE TEST SETUP START ---");
        System.out.println("Dropping tables...");
        DBQueryHelper.dropTables();
        System.out.println("Tables dropped.");
        System.out.println("Creating tables (with CHECK constraints)...");
        try {
            DBQueryHelper.createTables();
            System.out.println("H2 Tables created successfully.");
        } catch (Exception e) {
            System.err.println("!!! ERROR CREATING H2 TABLES in BaseIntegrationTest !!!");
            e.printStackTrace();
            throw e;
        }
        System.out.println("--- BASE TEST SETUP END ---");
    }

    @AfterAll
    public static void tearDownDatabase() throws Exception {
        System.out.println("--- BASE TEST TEARDOWN START ---");
        DBQueryHelper.dropTables();
        System.out.println("H2 Tables dropped.");
        System.out.println("--- BASE TEST TEARDOWN END ---");
    }
}