package com.dietideals24.services.schedular;

import com.dietideals24.utils.DBConnection;

import java.sql.*;
import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;

public class AuctionUpdater {
    private final ScheduledExecutorService scheduler = Executors.newScheduledThreadPool(1);

    public void start() {
        scheduler.scheduleAtFixedRate(this::updateAuctions, 0, 1, TimeUnit.MINUTES); // Controllo ogni minuto
    }

    private void updateAuctions() {
        try (Connection conn = DBConnection.getConnection()) {
            Timestamp now = new Timestamp(System.currentTimeMillis());

            // 1. Scadere le aste che hanno superato endTime e non hanno un vincitore
            String updateStatusQuery = """
                        UPDATE auctions
                        SET status = 'scaduta'
                        WHERE end_time <= ?
                        AND (auction_type = 'ribasso' OR auction_type = 'silenziosa')
                        AND status = 'attiva'
                    """;
            try (PreparedStatement stmt = conn.prepareStatement(updateStatusQuery)) {
                stmt.setTimestamp(1, now);
                stmt.executeUpdate();
            }

            // 1. Scadere le aste che hanno superato endTime e non hanno un vincitore
            String updateInverseStatusQuery = """
                        UPDATE auctions
                        SET status = 'scaduta'
                        WHERE end_time <= ?
                        AND auction_type = 'inversa'
                        AND status = 'attiva'
                        AND winner_id IS NULL
                    """;
            try (PreparedStatement stmt = conn.prepareStatement(updateInverseStatusQuery)) {
                stmt.setTimestamp(1, now);
                stmt.executeUpdate();
            }

            // 2. Aggiornare il prezzo delle aste al ribasso solo quando è passato un
            // intervallo valido
            String updatePriceQuery = """
                        UPDATE auctions
                        SET current_price = GREATEST(current_price - decrement_amount, min_price)  -- Assicura che il prezzo non scenda sotto min_price
                        WHERE auction_type = 'ribasso'
                        AND status = 'attiva'
                        AND current_price > min_price
                        AND MOD(TIMESTAMPDIFF(MINUTE, start_time, NOW()), decrement_interval_minutes) = 0
                    """;
            try (PreparedStatement stmt = conn.prepareStatement(updatePriceQuery)) {
                stmt.executeUpdate();
            }

            // 3. Segnare come scadute le aste al ribasso che hanno raggiunto il prezzo
            // minimo senza compratore
            String expireAuctionQuery = """
                        UPDATE auctions
                        SET status = 'scaduta'
                        WHERE auction_type = 'ribasso'
                        AND status = 'attiva'
                        AND current_price <= min_price
                        AND buyer_id IS NULL
                    """;
            try (PreparedStatement stmt = conn.prepareStatement(expireAuctionQuery)) {
                stmt.executeUpdate();
            }

            // 6. Completare le aste inverse che hanno un vincitore quando scadono
            String completeInverseAuctionQuery = """
                        UPDATE auctions
                        SET status = 'completata'
                        WHERE auction_type = 'inversa'
                        AND end_time <= ?
                        AND status = 'attiva'
                        AND winner_id IS NOT NULL
                    """;
            try (PreparedStatement stmt = conn.prepareStatement(completeInverseAuctionQuery)) {
                stmt.setTimestamp(1, now);
                stmt.executeUpdate();
            }

            System.out.println("Aste aggiornate con successo!");
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public void stop() {
        scheduler.shutdown();
    }
}
