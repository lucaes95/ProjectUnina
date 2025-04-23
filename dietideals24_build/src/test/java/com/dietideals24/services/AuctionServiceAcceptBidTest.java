package com.dietideals24.services;

import com.dietideals24.models.Auction;
import com.dietideals24.utils.BaseIntegrationTest;
import com.dietideals24.utils.DBQueryHelper;

import org.junit.jupiter.api.*;
import static org.junit.jupiter.api.Assertions.*;

import java.math.BigDecimal;
import java.sql.SQLException;

public class AuctionServiceAcceptBidTest extends BaseIntegrationTest {

        private static AuctionService auctionService;

        private static int testAuctionIdActive;
        private static int testBidIdValid;
        private static String expectedWinnerId;
        private static BigDecimal expectedWinningPrice;
        private static int anotherAuctionId;

        @BeforeAll
        public static void setUpService() {
                auctionService = new AuctionService();
        }

        @BeforeEach
        public void setupTestData() throws SQLException {
                testAuctionIdActive = DBQueryHelper.createTestAuction("attiva", "seller1", null,
                                new BigDecimal("10.00"));
                expectedWinnerId = "user123";
                expectedWinningPrice = new BigDecimal("55.50");
                testBidIdValid = DBQueryHelper.createTestBid(testAuctionIdActive, expectedWinnerId,
                                expectedWinningPrice);
                anotherAuctionId = DBQueryHelper.createTestAuction("attiva", "seller2", null, new BigDecimal("20.00"));
                DBQueryHelper.createTestBid(anotherAuctionId, "user456", new BigDecimal("30.00"));
        }

        @Test
        @DisplayName("acceptBid - Successo: Accetta offerta valida per asta attiva")
        public void testAcceptBid_Success() throws SQLException {
                boolean result = auctionService.acceptBid(testAuctionIdActive, testBidIdValid);

                assertTrue(result, "Il metodo acceptBid dovrebbe restituire true per successo.");

                Auction updatedAuction = DBQueryHelper.getAuctionFromDbById(testAuctionIdActive);
                assertNotNull(updatedAuction, "L'asta aggiornata non dovrebbe essere null.");
                assertEquals("completata", updatedAuction.getStatus(),
                                "Lo stato dell'asta dovrebbe essere 'completata'.");
                assertEquals(expectedWinnerId, updatedAuction.getWinnerId(), "Il winnerId non corrisponde.");
                assertNotNull(updatedAuction.getCurrentPrice(), "CurrentPrice non dovrebbe essere null.");
                assertEquals(0, expectedWinningPrice.compareTo(updatedAuction.getCurrentPrice()),
                                "Il currentPrice non corrisponde al prezzo dell'offerta accettata.");
        }

        @Test
        @DisplayName("acceptBid - Fallimento: Asta Inesistente")
        public void testAcceptBid_Failure_AuctionNotFound() {
                int nonExistentAuctionId = 99999;
                boolean result = auctionService.acceptBid(nonExistentAuctionId, testBidIdValid);
                assertFalse(result, "Il metodo acceptBid dovrebbe restituire false se l'asta non esiste.");
        }

        @Test
        @DisplayName("acceptBid - Fallimento: Offerta Inesistente")
        public void testAcceptBid_Failure_BidNotFound() throws SQLException {
                int nonExistentBidId = 88888;
                boolean result = auctionService.acceptBid(testAuctionIdActive, nonExistentBidId);

                assertFalse(result, "Il metodo acceptBid dovrebbe restituire false se l'offerta non esiste.");

                Auction auction = DBQueryHelper.getAuctionFromDbById(testAuctionIdActive);
                assertNotNull(auction,
                                "L'asta originale testAuctionIdActive non è stata trovata dopo il tentativo fallito di acceptBid!");
                assertEquals("attiva", auction.getStatus(), "Lo stato dell'asta non doveva cambiare.");
                assertNull(auction.getWinnerId(), "Il winnerId doveva rimanere null.");
        }

        @Test
        @DisplayName("acceptBid - Fallimento: Offerta per Asta Sbagliata")
        public void testAcceptBid_Failure_BidForWrongAuction() throws SQLException {
                boolean result = auctionService.acceptBid(anotherAuctionId, testBidIdValid);

                assertFalse(result,
                                "acceptBid dovrebbe restituire false se l'offerta non appartiene all'asta specificata.");

                Auction auction = DBQueryHelper.getAuctionFromDbById(anotherAuctionId);
                assertNotNull(auction,
                                "L'asta target anotherAuctionId non è stata trovata dopo il tentativo fallito di acceptBid!");
                assertEquals("attiva", auction.getStatus(), "Lo stato dell'asta target non doveva cambiare.");
                assertNull(auction.getWinnerId(), "Il winnerId dell'asta target doveva rimanere null.");
        }

        @Test
        @DisplayName("acceptBid - Caso Limite: Asta Già Completata")
        public void testAcceptBid_EdgeCase_AuctionAlreadyCompleted() throws SQLException {
                boolean firstAccept = auctionService.acceptBid(testAuctionIdActive, testBidIdValid);
                assertTrue(firstAccept, "Il primo acceptBid doveva avere successo.");

                boolean secondAccept = auctionService.acceptBid(testAuctionIdActive, testBidIdValid);

                assertTrue(secondAccept,
                                "acceptBid potrebbe restituire true anche su asta completata (comportamento attuale).");

                Auction updatedAuction = DBQueryHelper.getAuctionFromDbById(testAuctionIdActive);
                assertNotNull(updatedAuction, "L'asta completata dovrebbe ancora esistere.");
                assertEquals("completata", updatedAuction.getStatus());
                assertEquals(expectedWinnerId, updatedAuction.getWinnerId());
                assertEquals(0, expectedWinningPrice.compareTo(updatedAuction.getCurrentPrice()));
        }
}