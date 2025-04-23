package com.dietideals24.listeners;

import com.dietideals24.services.schedular.AuctionUpdater;

import javax.servlet.ServletContextEvent;
import javax.servlet.ServletContextListener;
import javax.servlet.annotation.WebListener;

@WebListener
public class AuctionSchedulerListener implements ServletContextListener {
    private AuctionUpdater auctionUpdater;

    @Override
    public void contextInitialized(ServletContextEvent sce) {
        auctionUpdater = new AuctionUpdater();
        auctionUpdater.start(); // Avvia lo scheduler quando il server parte
        System.out.println("AuctionUpdater avviato!");
    }

    @Override
    public void contextDestroyed(ServletContextEvent sce) {
        if (auctionUpdater != null) {
            auctionUpdater.stop(); // Ferma lo scheduler alla chiusura dell'applicazione
            System.out.println("AuctionUpdater fermato!");
        }
    }
}