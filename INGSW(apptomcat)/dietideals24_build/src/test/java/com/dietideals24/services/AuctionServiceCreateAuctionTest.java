package com.dietideals24.services;

import com.dietideals24.models.Auction;
import com.dietideals24.utils.BaseIntegrationTest;
import com.dietideals24.utils.AuctionTestDataFactory;
import com.dietideals24.utils.AuctionTestAssertions;

import org.junit.jupiter.api.*;
import java.math.BigDecimal;
import java.sql.Timestamp;
import java.time.Instant;
import java.time.temporal.ChronoUnit;
import java.util.List;
import java.util.Optional;

import static org.junit.jupiter.api.Assertions.*;

public class AuctionServiceCreateAuctionTest extends BaseIntegrationTest {

    private static AuctionService auctionService;

    @BeforeAll
    public static void setUpService() {
        auctionService = new AuctionService();
    }

    @Test
    @DisplayName("createAuction [Azione] - Dovrebbe restituire true per dati validi (ribasso)")
    public void testCreateAuction_Action_ReturnsTrueOnSuccess_Ribasso() {
        Auction auctionData = AuctionTestDataFactory.createRealisticAuction("ribasso");
        boolean result = auctionService.createAuction(auctionData);
        assertTrue(result, "createAuction (ribasso) dovrebbe restituire true.");
    }

    @Test
    @DisplayName("createAuction [Azione] - Dovrebbe restituire true per dati validi (silenziosa)")
    public void testCreateAuction_Action_ReturnsTrueOnSuccess_Silenziosa() {
        Auction auctionData = AuctionTestDataFactory.createRealisticAuction("silenziosa");
        boolean result = auctionService.createAuction(auctionData);
        assertTrue(result, "createAuction (silenziosa) dovrebbe restituire true.");
    }

    @Test
    @DisplayName("createAuction [Azione] - Dovrebbe restituire true per dati validi (inversa)")
    public void testCreateAuction_Action_ReturnsTrueOnSuccess_Inversa() {
        Auction auctionData = AuctionTestDataFactory.createRealisticAuction("inversa");
        boolean result = auctionService.createAuction(auctionData);
        assertTrue(result, "createAuction (inversa) dovrebbe restituire true.");
    }

    @Test
    @DisplayName("createAuction [Azione] - Dovrebbe restituire false per Title nullo")
    public void testCreateAuction_Action_ReturnsFalse_NullTitle() {
        Auction invalidAuctionData = AuctionTestDataFactory.createRealisticAuction("inversa");
        invalidAuctionData.setTitle(null);
        boolean result = auctionService.createAuction(invalidAuctionData);
        assertFalse(result, "createAuction dovrebbe restituire false per titolo nullo.");
    }

    @Test
    @DisplayName("createAuction [Azione] - Dovrebbe restituire false per AuctionType nullo")
    public void testCreateAuction_Action_ReturnsFalse_NullAuctionType() {
        Auction auctionData = AuctionTestDataFactory.createRealisticAuction("silenziosa");
        auctionData.setAuctionType(null);
        boolean result = auctionService.createAuction(auctionData);
        assertFalse(result, "createAuction dovrebbe restituire false per auctionType nullo.");
    }

    @Test
    @DisplayName("createAuction [Azione] - Dovrebbe restituire false per StartTime nullo")
    public void testCreateAuction_Action_ReturnsFalse_NullStartTime() {
        Auction auctionData = AuctionTestDataFactory.createRealisticAuction("silenziosa");
        auctionData.setStartTime(null);
        boolean result = auctionService.createAuction(auctionData);
        assertFalse(result, "createAuction dovrebbe restituire false per startTime nullo.");
    }

    @Test
    @DisplayName("createAuction [Azione] - Dovrebbe restituire false per EndTime nullo")
    public void testCreateAuction_Action_ReturnsFalse_NullEndTime() {
        Auction auctionData = AuctionTestDataFactory.createRealisticAuction("silenziosa");
        auctionData.setEndTime(null);
        boolean result = auctionService.createAuction(auctionData);
        assertFalse(result, "createAuction dovrebbe restituire false per endTime nullo.");
    }

    @Test
    @DisplayName("createAuction [Azione] - Dovrebbe restituire false per StartPrice negativo")
    public void testCreateAuction_Action_ReturnsFalse_NegativeStartPrice() {
        Auction auctionData = AuctionTestDataFactory.createRealisticAuction("silenziosa");
        auctionData.setStartPrice(new BigDecimal("-10.00"));
        boolean result = auctionService.createAuction(auctionData);
        assertFalse(result, "createAuction non dovrebbe permettere startPrice negativo.");
    }

    @Test
    @DisplayName("createAuction [Azione] - Dovrebbe restituire false per MinPrice negativo")
    public void testCreateAuction_Action_ReturnsFalse_NegativeMinPrice() {
        Auction auctionData = AuctionTestDataFactory.createRealisticAuction("silenziosa");
        auctionData.setMinPrice(new BigDecimal("-5.00"));
        boolean result = auctionService.createAuction(auctionData);
        assertFalse(result, "createAuction non dovrebbe permettere minPrice negativo.");
    }

    @Test
    @DisplayName("createAuction [Azione] - Dovrebbe restituire false per DecrementAmount non positivo (tipo ribasso)")
    public void testCreateAuction_Action_ReturnsFalse_NonPositiveDecrementAmount() {
        Auction auctionData = AuctionTestDataFactory.createRealisticAuction("ribasso");
        auctionData.setDecrementAmount(BigDecimal.ZERO);
        boolean resultZero = auctionService.createAuction(auctionData);
        assertFalse(resultZero, "createAuction non dovrebbe permettere decrementAmount = 0.");
        auctionData.setDecrementAmount(new BigDecimal("-1.00"));
        boolean resultNegative = auctionService.createAuction(auctionData);
        assertFalse(resultNegative, "createAuction non dovrebbe permettere decrementAmount negativo.");
    }

    @Test
    @DisplayName("createAuction [Azione] - Dovrebbe restituire false per Intervallo <= 0 (tipo ribasso)")
    public void testCreateAuction_Action_ReturnsFalse_IntervalZeroOrLess() {
        Auction auctionData = AuctionTestDataFactory.createRealisticAuction("ribasso");
        auctionData.setDecrementIntervalMinutes(0);
        boolean result = auctionService.createAuction(auctionData);
        assertFalse(result, "createAuction non dovrebbe permettere intervallo <= 0 per tipo ribasso.");
    }

    @Test
    @DisplayName("createAuction [Azione] - Dovrebbe restituire false per Intervallo > 720 (tipo ribasso)")
    public void testCreateAuction_Action_ReturnsFalse_IntervalTooLarge() {
        Auction auctionData = AuctionTestDataFactory.createRealisticAuction("ribasso");
        auctionData.setDecrementIntervalMinutes(721);
        boolean result = auctionService.createAuction(auctionData);
        assertFalse(result, "createAuction non dovrebbe permettere intervallo > 720 per tipo ribasso.");
    }

    @Test
    @DisplayName("createAuction [Azione] - Dovrebbe restituire false se EndTime < StartTime + 1 ora")
    public void testCreateAuction_Action_ReturnsFalse_EndTimeTooSoon() {
        Auction auctionData = AuctionTestDataFactory.createRealisticAuction("silenziosa");
        Instant startTime = Instant.now();
        Instant endTime = startTime.plus(30, ChronoUnit.MINUTES);
        auctionData.setStartTime(Timestamp.from(startTime));
        auctionData.setEndTime(Timestamp.from(endTime));
        boolean result = auctionService.createAuction(auctionData);
        assertFalse(result, "createAuction non dovrebbe permettere EndTime < StartTime + 1 ora.");
    }

    @Test
    @DisplayName("createAuction [Azione] - Dovrebbe restituire false se MinPrice > StartPrice")
    public void testCreateAuction_Action_ReturnsFalse_MinPriceExceedsStartPrice() {
        Auction auctionData = AuctionTestDataFactory.createRealisticAuction("silenziosa");
        BigDecimal startPrice = auctionData.getStartPrice();
        assertNotNull(startPrice, "StartPrice non dovrebbe essere null per questo test");
        auctionData.setMinPrice(startPrice.add(new BigDecimal("10.00")));
        boolean result = auctionService.createAuction(auctionData);
        assertFalse(result, "createAuction non dovrebbe permettere minPrice > startPrice.");
    }

    @Test
    @DisplayName("createAuction [Stato] - Verifica dati salvati per tipo 'silenziosa'")
    public void testCreateAuction_State_VerifiesData_Silenziosa() {
        Auction auctionData = AuctionTestDataFactory.createRealisticAuction("silenziosa");
        boolean createResult = auctionService.createAuction(auctionData);
        assertTrue(createResult, "La creazione preliminare (silenziosa) deve avere successo.");
        List<Auction> potentialMatches = auctionService.getUserAuctions(
                auctionData.getSellerId(), auctionData.getTitle(), "venditore", 1, 10,
                auctionData.getAuctionType(), auctionData.getCategory(), 10);
        Optional<Auction> foundAuctionOpt = potentialMatches.stream()
                .filter(a -> a.getTitle().equals(auctionData.getTitle())).findFirst();
        assertTrue(foundAuctionOpt.isPresent(), "L'asta (silenziosa) trovata via getUserAuctions.");
        int createdAuctionId = foundAuctionOpt.get().getAuctionId();
        assertTrue(createdAuctionId > 0, "ID Asta (silenziosa) > 0");
        Auction retrievedAuction = auctionService.getAuctionById(createdAuctionId);
        assertNotNull(retrievedAuction, "L'asta (silenziosa) recuperabile via ID.");
        AuctionTestAssertions.assertAuctionFieldsEqual(auctionData, retrievedAuction);
    }

    @Test
    @DisplayName("createAuction [Stato] - Verifica dati salvati per tipo 'ribasso'")
    public void testCreateAuction_State_VerifiesData_Ribasso() {
        Auction auctionData = AuctionTestDataFactory.createRealisticAuction("ribasso");
        assertNotNull(auctionData.getDecrementAmount(), "DecrementAmount non nullo per ribasso (dati test)");
        assertTrue(auctionData.getDecrementIntervalMinutes() >= 1 && auctionData.getDecrementIntervalMinutes() <= 720,
                "Intervallo valido per ribasso (dati test)");
        boolean createResult = auctionService.createAuction(auctionData);
        assertTrue(createResult, "La creazione preliminare (ribasso) deve avere successo.");
        List<Auction> potentialMatches = auctionService.getUserAuctions(
                auctionData.getSellerId(), auctionData.getTitle(), "venditore", 1, 10,
                auctionData.getAuctionType(), auctionData.getCategory(),
                10);
        Optional<Auction> foundAuctionOpt = potentialMatches.stream()
                .filter(a -> a.getTitle().equals(auctionData.getTitle())).findFirst();
        assertTrue(foundAuctionOpt.isPresent(), "L'asta (ribasso) trovata via getUserAuctions.");
        int createdAuctionId = foundAuctionOpt.get().getAuctionId();
        assertTrue(createdAuctionId > 0, "ID Asta (ribasso) > 0");
        Auction retrievedAuction = auctionService.getAuctionById(createdAuctionId);
        assertNotNull(retrievedAuction, "L'asta (ribasso) recuperabile via ID.");
        AuctionTestAssertions.assertAuctionFieldsEqual(auctionData, retrievedAuction);
    }

    @Test
    @DisplayName("createAuction [Stato] - Verifica dati salvati per tipo 'inversa'")
    public void testCreateAuction_State_VerifiesData_Inversa() {
        Auction auctionData = AuctionTestDataFactory.createRealisticAuction("inversa");
        assertNotNull(auctionData.getBuyerId(), "BuyerId non nullo per inversa (dati test).");
        assertNull(auctionData.getDecrementAmount(), "DecrementAmount nullo per inversa (dati test).");
        assertEquals(0, auctionData.getDecrementIntervalMinutes(), "Intervallo 0 per inversa (dati test).");
        assertNull(auctionData.getSellerId(), "SellerId nullo per inversa (dati test).");
        boolean createResult = auctionService.createAuction(auctionData);
        assertTrue(createResult, "La creazione preliminare (inversa) deve avere successo.");
        List<Auction> potentialMatches = auctionService.getUserAuctions(
                auctionData.getBuyerId(),
                auctionData.getTitle(),
                "compratore",
                1, 10,
                auctionData.getAuctionType(),
                auctionData.getCategory(),
                10);
        Optional<Auction> foundAuctionOpt = potentialMatches.stream()
                .filter(a -> a.getTitle().equals(auctionData.getTitle())).findFirst();
        assertTrue(foundAuctionOpt.isPresent(), "L'asta (inversa) trovata via getUserAuctions.");
        int createdAuctionId = foundAuctionOpt.get().getAuctionId();
        assertTrue(createdAuctionId > 0, "ID Asta (inversa) > 0");
        Auction retrievedAuction = auctionService.getAuctionById(createdAuctionId);
        assertNotNull(retrievedAuction, "L'asta (inversa) recuperabile via ID.");
        AuctionTestAssertions.assertAuctionFieldsEqual(auctionData, retrievedAuction);
        assertNull(retrievedAuction.getSellerId(), "SellerId recuperato deve essere nullo per inversa.");
    }
}