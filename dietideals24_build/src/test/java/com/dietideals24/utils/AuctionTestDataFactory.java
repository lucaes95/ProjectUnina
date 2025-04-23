package com.dietideals24.utils;

import com.github.javafaker.Faker;
import com.dietideals24.models.Auction;
import com.dietideals24.services.AuctionService;

import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;

import java.math.BigDecimal;
import java.sql.Timestamp;
import java.time.Instant;
import java.util.List;
import java.util.Optional;
import java.util.UUID;

public class AuctionTestDataFactory {

        private static final Faker faker = new Faker();

        public static Auction createRealisticAuction(String type) {
                Auction auction = new Auction();
                String uniqueSuffix = UUID.randomUUID().toString().substring(0, 8);

                String sellerId = type.equals("inversa") ? null
                                : "testSeller_" + faker.internet().uuid().substring(0, 8);
                String buyerId = type.equals("inversa") ? "testBuyer_" + faker.internet().uuid().substring(0, 8) : null;

                auction.setSellerId(sellerId);
                auction.setBuyerId(buyerId);
                auction.setTitle(faker.commerce().productName() + " - " + type + " [" + uniqueSuffix + "]");
                auction.setDescription(faker.lorem().paragraph(1));
                String[] categories = { "Motori", "Immobili", "Servizi", "Elettronica", "Per la casa e la persona",
                                "Sport e Hobby", "Altro" };
                auction.setCategory(faker.options().option(categories));
                auction.setAuctionType(type);

                double startPriceDouble = faker.number().randomDouble(2, 50, 1500);
                BigDecimal startPrice = BigDecimal.valueOf(startPriceDouble);

                BigDecimal minPrice = !type.equals("inversa")
                                ? BigDecimal.valueOf(faker.number().randomDouble(2, 10, (int) (startPriceDouble * 0.8)))
                                : null;
                if (minPrice != null && minPrice.compareTo(BigDecimal.ZERO) < 0) {
                        minPrice = BigDecimal.ZERO;
                }
                if (minPrice != null && minPrice.compareTo(startPrice) > 0) {
                        minPrice = startPrice;
                }

                BigDecimal decrementAmount = type.equals("ribasso")
                                ? BigDecimal.valueOf(faker.number().randomDouble(2, 1, 50))
                                : null;
                if (decrementAmount != null && decrementAmount.compareTo(BigDecimal.ZERO) <= 0) {
                        decrementAmount = new BigDecimal("0.01");
                }

                int decrementInterval = 0;
                if (type.equals("ribasso")) {
                        decrementInterval = faker.number().numberBetween(1, 720);
                }

                auction.setStartPrice(startPrice);
                auction.setCurrentPrice(auction.getStartPrice());
                auction.setMinPrice(minPrice);
                auction.setDecrementAmount(decrementAmount);
                auction.setDecrementIntervalMinutes(decrementInterval);

                Instant startTime = Instant.now().minusSeconds(faker.number().numberBetween(0, 60));
                long minDurationSeconds = 60 * 60;
                long maxDurationSeconds = 5 * 24 * 60 * 60;
                long randomDurationSeconds = faker.number().numberBetween(minDurationSeconds, maxDurationSeconds + 1);
                Instant endTime = startTime.plusSeconds(randomDurationSeconds);

                auction.setStartTime(Timestamp.from(startTime));
                auction.setEndTime(Timestamp.from(endTime));
                auction.setStatus("attiva");
                auction.setWinnerId(null);
                auction.setImagePath(faker.internet().image());

                return auction;
        }

        public static Auction createAndPersistAuction(String type, AuctionService auctionService) {
                Auction auctionData = createRealisticAuction(type);
                boolean created = auctionService.createAuction(auctionData);
                assertTrue(created, "TEST SETUP FAILED: impossibile creare l'asta di test preliminare (" + type + ").");
                String searchId = type.equals("inversa") ? auctionData.getBuyerId() : auctionData.getSellerId();
                String searchRole = type.equals("inversa") ? "compratore" : "venditore";
                List<Auction> potentialMatches = auctionService.getUserAuctions(
                                searchId, auctionData.getTitle(), searchRole, 1, 10,
                                auctionData.getAuctionType(), auctionData.getCategory(), 10);
                Optional<Auction> foundAuctionOpt = potentialMatches.stream()
                                .filter(a -> a.getTitle().equals(auctionData.getTitle())).findFirst();
                assertTrue(foundAuctionOpt.isPresent(),
                                "TEST SETUP FAILED: impossibile trovare l'asta (" + type
                                                + ") appena creata tramite getUserAuctions. Titolo cercato: "
                                                + auctionData.getTitle());
                Auction persistedAuction = foundAuctionOpt.get();
                assertTrue(persistedAuction.getAuctionId() > 0,
                                "TEST SETUP FAILED: ID asta (" + type + ") non valido dopo il recupero.");
                if (persistedAuction.getCurrentPrice() == null && persistedAuction.getStartPrice() != null) {
                        persistedAuction.setCurrentPrice(persistedAuction.getStartPrice());
                } else if (persistedAuction.getCurrentPrice() == null) {
                        persistedAuction.setCurrentPrice(BigDecimal.ZERO);
                }
                System.out.println("--- Auction (" + type + ") creata e persistita per test (ID: "
                                + persistedAuction.getAuctionId() + ") ---");
                return persistedAuction;
        }

        private static void createAndPersistSingleTestAuction(String sellerId, String buyerId, String type,
                        String category, String title, AuctionService auctionService) {
                Auction auction = createRealisticAuction(type);
                auction.setSellerId(sellerId);
                auction.setBuyerId(buyerId);
                auction.setTitle(title);
                auction.setDescription("Descrizione per " + title + ". Contiene " + KEYWORD_COMMON);
                auction.setCategory(category);
                auction.setAuctionType(type);
                auction.setStatus("attiva");
                boolean created = auctionService.createAuction(auction);
                assertTrue(created, "Setup fallito (helper): creazione asta '" + title + "'");
        }

        public static final String SELLER_ID_1 = "seller_test_1";
        public static final String SELLER_ID_2 = "seller_test_2";
        public static final String BUYER_ID_1 = "buyer_test_1";
        public static final String CATEGORY_1 = "Elettronica";
        public static final String CATEGORY_2 = "Immobili";
        public static final String KEYWORD_UNIQUE_1 = "AlfaRomeoGiulia";
        public static final String KEYWORD_COMMON = "TestAsta";

        public static void setupAuctionsForGetUserAuctionsTest(AuctionService auctionService) {
                System.out.println("--- Factory: Setting up specific test data for GetUserAuctions ---");
                int count = 0;
                try {
                        createAndPersistSingleTestAuction(SELLER_ID_1, null, "ribasso", CATEGORY_1,
                                        KEYWORD_COMMON + " Ribasso Elettronica 1", auctionService);
                        count++;
                        createAndPersistSingleTestAuction(SELLER_ID_1, null, "ribasso", CATEGORY_2,
                                        KEYWORD_COMMON + " Ribasso Immobili 2", auctionService);
                        count++;
                        createAndPersistSingleTestAuction(SELLER_ID_1, null, "silenziosa", CATEGORY_1,
                                        KEYWORD_COMMON + " Silenziosa Elettronica 3", auctionService);
                        count++;
                        createAndPersistSingleTestAuction(SELLER_ID_1, null, "silenziosa", CATEGORY_1,
                                        "Speciale " + KEYWORD_UNIQUE_1 + " 4", auctionService);
                        count++;
                        createAndPersistSingleTestAuction(SELLER_ID_2, null, "ribasso", CATEGORY_1,
                                        KEYWORD_COMMON + " Altro Venditore 5", auctionService);
                        count++;
                        createAndPersistSingleTestAuction(null, BUYER_ID_1, "inversa", CATEGORY_2,
                                        KEYWORD_COMMON + " Inversa Immobili 6", auctionService);
                        count++;
                        createAndPersistSingleTestAuction(null, BUYER_ID_1, "inversa", CATEGORY_2,
                                        KEYWORD_COMMON + " Inversa Immobili 7", auctionService);
                        count++;
                        for (int i = 8; i <= 12; i++) {
                                createAndPersistSingleTestAuction(SELLER_ID_1, null, "silenziosa", CATEGORY_2,
                                                KEYWORD_COMMON + " Paginazione " + i, auctionService);
                                count++;
                        }
                        System.out.println(
                                        "--- Factory: Test data setup complete (" + count + " auctions created) ---");
                } catch (Exception e) {
                        fail("TEST SETUP FAILED in AuctionTestDataFactory.setupAuctionsForGetUserAuctionsTest: "
                                        + e.getMessage(), e);
                }
        }
}