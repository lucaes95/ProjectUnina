package com.dietideals24.services;

import com.dietideals24.models.Auction;
import com.dietideals24.models.Bid;

import com.dietideals24.utils.BaseIntegrationTest;
import com.dietideals24.utils.DBQueryHelper;
import com.dietideals24.utils.AuctionTestDataFactory;

import org.junit.jupiter.api.*;
import java.math.BigDecimal;
import java.sql.SQLException;
import java.util.List;
import com.github.javafaker.Faker;

import static org.junit.jupiter.api.Assertions.*;

public class AuctionServiceCreateBidTest extends BaseIntegrationTest {

    private static AuctionService auctionService;
    private final Faker faker = new Faker();

    private Auction testAuctionRibasso;
    private int testAuctionIdRibasso;
    private Auction testAuctionInversa;
    private int testAuctionIdInversa;
    private Auction testAuctionSilenziosa;
    private int testAuctionIdSilenziosa;

    private String testBidderUsername;

    @BeforeAll
    public static void setUpService() {
        auctionService = new AuctionService();
    }

    @BeforeEach
    public void setUpTestAuctions() {
        testBidderUsername = "bidder_" + faker.internet().uuid().substring(0, 8);

        testAuctionRibasso = AuctionTestDataFactory.createAndPersistAuction("ribasso", auctionService);
        testAuctionIdRibasso = testAuctionRibasso.getAuctionId();

        testAuctionSilenziosa = AuctionTestDataFactory.createAndPersistAuction("silenziosa", auctionService);
        testAuctionIdSilenziosa = testAuctionSilenziosa.getAuctionId();

        testAuctionInversa = AuctionTestDataFactory.createAndPersistAuction("inversa", auctionService);
        testAuctionIdInversa = testAuctionInversa.getAuctionId();
    }

    @Test
    @DisplayName("createBid [Azione] - Dovrebbe restituire true per offerta valida su asta attiva")
    public void testCreateBid_Action_ReturnsTrueOnSuccess() {
        double validBidPrice = 1.00;
        int auctionId = testAuctionIdSilenziosa;

        boolean result = auctionService.createBid(auctionId, validBidPrice, testBidderUsername);

        assertTrue(result, "createBid dovrebbe restituire true per un'offerta valida su asta attiva.");
    }

    @Test
    @DisplayName("createBid [Stato] - Verifica offerta salvata tramite getBidsByAuctionId")
    public void testCreateBid_State_VerifiesBidViaService() {
        int auctionId = testAuctionIdSilenziosa;
        double validBidPrice = 55.50;
        BigDecimal expectedBidPrice = BigDecimal.valueOf(validBidPrice);

        boolean createResult = auctionService.createBid(auctionId, validBidPrice, testBidderUsername);
        assertTrue(createResult, "La creazione preliminare dell'offerta deve avere successo.");

        List<Bid> bids = auctionService.getBidsByAuctionId(auctionId);
        assertNotNull(bids, "La lista delle offerte non dovrebbe essere nulla.");
        assertEquals(1, bids.size(), "Dovrebbe esserci esattamente un'offerta per l'asta.");

        Bid retrievedBid = bids.get(0);
        assertEquals(auctionId, retrievedBid.getAuctionId(), "Auction ID nell'offerta recuperata");
        assertEquals(testBidderUsername, retrievedBid.getUserId(), "User ID nell'offerta recuperata");
        assertTrue(expectedBidPrice.compareTo(retrievedBid.getBidPrice()) == 0);
        assertNotNull(retrievedBid.getBidTime(), "Bid Time non dovrebbe essere nullo");
    }

    @Test
    @DisplayName("createBid [Azione] - Dovrebbe restituire false per auctionId inesistente")
    public void testCreateBid_Action_ReturnsFalse_InvalidAuctionId() {
        int nonExistentAuctionId = testAuctionIdSilenziosa + 999;
        double validBidPrice = 100.0;

        boolean result = auctionService.createBid(nonExistentAuctionId, validBidPrice, testBidderUsername);

        assertFalse(result, "createBid dovrebbe restituire false per un auctionId inesistente.");
    }

    @Test
    @DisplayName("createBid [Azione] - Dovrebbe restituire false per bidPrice non positivo (<= 0)")
    public void testCreateBid_Action_ReturnsFalse_NonPositiveBidPrice() {
        int auctionId = testAuctionIdSilenziosa;
        double zeroBidPrice = 0.0;
        double negativeBidPrice = -50.0;

        boolean resultZero = auctionService.createBid(auctionId, zeroBidPrice, testBidderUsername);
        assertFalse(resultZero, "createBid dovrebbe restituire false per un bidPrice uguale a zero.");

        boolean resultNegative = auctionService.createBid(auctionId, negativeBidPrice, testBidderUsername);
        assertFalse(resultNegative, "createBid dovrebbe restituire false per un bidPrice negativo.");
    }

    @Test
    @DisplayName("createBid [Azione] - Dovrebbe restituire false per username nullo")
    public void testCreateBid_Action_ReturnsFalse_NullUsername() {
        int auctionId = testAuctionIdSilenziosa;
        double validBidPrice = 100.0;
        String nullUsername = null;

        boolean result = auctionService.createBid(auctionId, validBidPrice, nullUsername);

        assertFalse(result, "createBid dovrebbe restituire false per un username nullo.");
    }

    @Test
    @DisplayName("createBid [Azione] - Dovrebbe restituire false per asta non attiva (scaduta)")
    public void testCreateBid_Action_ReturnsFalse_AuctionNotActive() {
        int auctionId = testAuctionIdSilenziosa;
        double validBidPrice = 100.0;
        String targetStatus = "scaduta";

        try {
            DBQueryHelper.setAuctionStatus(auctionId, targetStatus);
        } catch (SQLException e) {
            fail("Setup fallito: impossibile aggiornare lo stato dell'asta a '" + targetStatus + "'.", e);
        }

        boolean result = auctionService.createBid(auctionId, validBidPrice, testBidderUsername);

        assertFalse(result, "createBid dovrebbe restituire false per un'asta non attiva.");
    }

    @Test
    @DisplayName("createBid [Azione] - Dovrebbe restituire false se Cooldown non rispettato")
    public void testCreateBid_Action_ReturnsFalse_WhenCooldownActive() {
        int auctionId = testAuctionIdRibasso;
        BigDecimal currentPrice = testAuctionRibasso.getCurrentPrice();
        assertNotNull(currentPrice, "Prezzo corrente nullo nel setup");
        double price1 = currentPrice.doubleValue();
        if (price1 <= 0)
            price1 = 1.0;

        double price2 = price1;

        boolean result1 = auctionService.createBid(auctionId, price1, testBidderUsername);
        assertTrue(result1, "La prima offerta dovrebbe avere successo.");

        boolean result2 = auctionService.createBid(auctionId, price2, testBidderUsername);

        assertFalse(result2, "La seconda offerta immediata dovrebbe fallire per cooldown.");
    }

    @Test
    @DisplayName("createBid [Azione] - Dovrebbe restituire false se Utente è Vincitore (Asta Inversa)")
    public void testCreateBid_Action_ReturnsFalse_WhenUserIsWinnerOnInverse() {
        int auctionId = testAuctionIdInversa;
        BigDecimal initialPrice = testAuctionInversa.getStartPrice();
        double winningBidPrice = initialPrice.doubleValue() - 10.0;
        assertTrue(winningBidPrice > 0, "Il prezzo vincente deve essere positivo");

        boolean result1 = auctionService.createBid(auctionId, winningBidPrice, testBidderUsername);
        assertTrue(result1, "La prima offerta (vincente) dovrebbe avere successo.");

        boolean updateResult = auctionService.updateAuctionPriceInversa(auctionId, winningBidPrice, testBidderUsername);
        assertTrue(updateResult, "Setup fallito: Aggiornamento asta inversa con vincitore fallito.");

        Auction updatedAuction = auctionService.getAuctionById(auctionId);
        assertNotNull(updatedAuction);
        assertEquals(testBidderUsername, updatedAuction.getWinnerId());
        assertTrue(BigDecimal.valueOf(winningBidPrice).compareTo(updatedAuction.getCurrentPrice()) == 0);

        double anotherBidPrice = winningBidPrice - 5.0;

        boolean result2 = auctionService.createBid(auctionId, anotherBidPrice, testBidderUsername);

        assertFalse(result2, "createBid dovrebbe restituire false se l'utente è già il vincitore di un'asta inversa.");
    }

    @Test
    @DisplayName("createBid [Azione] - Dovrebbe restituire false se Prezzo > Corrente (Asta Ribasso)")
    public void testCreateBid_Action_ReturnsFalse_PriceTooHighForRibasso() {
        int auctionId = testAuctionIdRibasso;
        BigDecimal currentPrice = testAuctionRibasso.getCurrentPrice();
        assertNotNull(currentPrice, "Prezzo corrente non nullo per asta ribasso.");
        double invalidBidPrice = currentPrice.doubleValue() + 10.0;

        boolean result = auctionService.createBid(auctionId, invalidBidPrice, testBidderUsername);

        assertFalse(result, "createBid dovrebbe restituire false se offerta > prezzo corrente per asta al ribasso.");
    }

    @Test
    @DisplayName("createBid [Azione] - Dovrebbe restituire false se Prezzo >= Corrente (Asta Inversa)")
    public void testCreateBid_Action_ReturnsFalse_PriceNotLowerForInversa() {
        int auctionId = testAuctionIdInversa;
        BigDecimal currentPrice = testAuctionInversa.getCurrentPrice();
        assertNotNull(currentPrice, "Prezzo corrente non nullo per asta inversa.");

        double equalBidPrice = currentPrice.doubleValue();
        boolean resultEqual = auctionService.createBid(auctionId, equalBidPrice, testBidderUsername);
        assertFalse(resultEqual, "createBid dovrebbe restituire false se offerta = prezzo corrente per asta inversa.");

        double higherBidPrice = currentPrice.doubleValue() + 10.0;
        boolean resultHigher = auctionService.createBid(auctionId, higherBidPrice, testBidderUsername);
        assertFalse(resultHigher, "createBid dovrebbe restituire false se offerta > prezzo corrente per asta inversa.");
    }
}