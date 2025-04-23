package com.dietideals24.services;

import com.dietideals24.models.Auction;
import com.dietideals24.utils.BaseIntegrationTest;
import com.dietideals24.utils.AuctionTestDataFactory;

import org.junit.jupiter.api.*;
import java.util.List;
import java.util.stream.Collectors;

import static org.junit.jupiter.api.Assertions.*;

public class AuctionServiceGetAuctionsTest extends BaseIntegrationTest {

        private static AuctionService auctionService;

        @BeforeAll
        public static void setUpServiceAndData() {
                auctionService = new AuctionService();
                AuctionTestDataFactory.setupAuctionsForGetUserAuctionsTest(auctionService);
        }

        @Test
        @DisplayName("getUserAuctions - Filtro Ruolo Venditore")
        public void testGetUserAuctions_FilterBySellerRole() {
                int testPageSize = 20;
                List<Auction> results = auctionService.getUserAuctions(
                                AuctionTestDataFactory.SELLER_ID_1,
                                null,
                                "venditore",
                                1,
                                testPageSize,
                                null,
                                null,
                                testPageSize);
                assertNotNull(results);
                assertEquals(9, results.size());
                assertTrue(results.stream().allMatch(a -> AuctionTestDataFactory.SELLER_ID_1.equals(a.getSellerId())));
                assertTrue(results.stream().noneMatch(a -> "inversa".equals(a.getAuctionType())));
        }

        @Test
        @DisplayName("getUserAuctions - Filtro Ruolo Compratore")
        public void testGetUserAuctions_FilterByBuyerRole() {
                int testPageSize = 20;
                List<Auction> results = auctionService.getUserAuctions(
                                AuctionTestDataFactory.BUYER_ID_1,
                                null,
                                "compratore",
                                1,
                                testPageSize,
                                null,
                                null,
                                testPageSize);
                assertNotNull(results);
                assertEquals(2, results.size());
                assertTrue(results.stream().allMatch(a -> AuctionTestDataFactory.BUYER_ID_1.equals(a.getBuyerId())));
                assertTrue(results.stream().allMatch(a -> "inversa".equals(a.getAuctionType())));
        }

        @Test
        @DisplayName("getUserAuctions - Filtro Keyword (Case-Insensitive)")
        public void testGetUserAuctions_FilterByKeyword() {
                int testPageSize = 20;
                List<Auction> results = auctionService.getUserAuctions(
                                AuctionTestDataFactory.SELLER_ID_1,
                                AuctionTestDataFactory.KEYWORD_UNIQUE_1.toLowerCase(),
                                "venditore",
                                1,
                                testPageSize,
                                null,
                                null,
                                testPageSize);
                assertNotNull(results);
                assertEquals(1, results.size());
                assertTrue(results.get(0).getTitle().contains(AuctionTestDataFactory.KEYWORD_UNIQUE_1));

                List<Auction> resultsCommon = auctionService.getUserAuctions(
                                AuctionTestDataFactory.SELLER_ID_1,
                                AuctionTestDataFactory.KEYWORD_COMMON.toLowerCase(),
                                "venditore",
                                1,
                                testPageSize,
                                null,
                                null,
                                testPageSize);
                assertEquals(9, resultsCommon.size());
        }

        @Test
        @DisplayName("getUserAuctions - Filtro Categoria (Case-Insensitive)")
        public void testGetUserAuctions_FilterByCategory() {
                int testPageSize = 20;
                List<Auction> results = auctionService.getUserAuctions(
                                AuctionTestDataFactory.SELLER_ID_1,
                                null,
                                "venditore",
                                1,
                                testPageSize,
                                null,
                                AuctionTestDataFactory.CATEGORY_1.toUpperCase(),
                                testPageSize);
                assertNotNull(results);
                assertEquals(3, results.size());
                assertTrue(results.stream()
                                .allMatch(a -> AuctionTestDataFactory.CATEGORY_1.equalsIgnoreCase(a.getCategory())));
        }

        @Test
        @DisplayName("getUserAuctions - Filtro Tipo Asta")
        public void testGetUserAuctions_FilterByType() {
                int testPageSize = 20;
                List<Auction> results = auctionService.getUserAuctions(
                                AuctionTestDataFactory.SELLER_ID_1,
                                null,
                                "venditore",
                                1,
                                testPageSize,
                                "ribasso",
                                null,
                                testPageSize);
                assertNotNull(results);
                assertEquals(2, results.size());
                assertTrue(results.stream().allMatch(a -> "ribasso".equals(a.getAuctionType())));
        }

        @Test
        @DisplayName("getUserAuctions - Filtro Combinato (Keyword, Categoria, Tipo)")
        public void testGetUserAuctions_FilterCombined() {
                String userId = AuctionTestDataFactory.SELLER_ID_1;
                String keyword = AuctionTestDataFactory.KEYWORD_COMMON;
                String role = "venditore";
                int page = 1;
                int pageSize = 20;
                String type = "silenziosa";
                String category = AuctionTestDataFactory.CATEGORY_1;
                int limit = pageSize;

                List<Auction> results = auctionService.getUserAuctions(
                                userId,
                                keyword,
                                role,
                                page,
                                pageSize,
                                type,
                                category,
                                limit);

                assertNotNull(results);
                assertEquals(2, results.size());

                final String keywordLower = keyword.toLowerCase();
                final String categoryLower = category.toLowerCase();

                assertTrue(results.stream().allMatch(a -> type.equals(a.getAuctionType()) &&
                                a.getCategory() != null && categoryLower.equalsIgnoreCase(a.getCategory()) &&
                                ((a.getTitle() != null && a.getTitle().toLowerCase().contains(keywordLower)) ||
                                                (a.getDescription() != null && a.getDescription().toLowerCase()
                                                                .contains(keywordLower))
                                                ||
                                                (a.getCategory() != null && a.getCategory().toLowerCase()
                                                                .contains(keywordLower)))));
        }

        @Test
        @DisplayName("getUserAuctions - Paginazione")
        public void testGetUserAuctions_Pagination() {
                int pageSize = 5;
                int limit = pageSize;

                List<Auction> page1 = auctionService.getUserAuctions(
                                AuctionTestDataFactory.SELLER_ID_1, null, "venditore",
                                1, pageSize, null, null, limit);
                List<Auction> page2 = auctionService.getUserAuctions(
                                AuctionTestDataFactory.SELLER_ID_1, null, "venditore",
                                2, pageSize, null, null, limit);
                List<Auction> page3 = auctionService.getUserAuctions(
                                AuctionTestDataFactory.SELLER_ID_1, null, "venditore",
                                3, pageSize, null, null, limit);

                assertNotNull(page1);
                assertNotNull(page2);
                assertNotNull(page3);

                assertEquals(pageSize, page1.size());
                assertEquals(9 - pageSize, page2.size());
                assertEquals(0, page3.size());

                List<Integer> ids1 = page1.stream().map(Auction::getAuctionId).collect(Collectors.toList());
                List<Integer> ids2 = page2.stream().map(Auction::getAuctionId).collect(Collectors.toList());
                assertTrue(ids1.stream().noneMatch(ids2::contains));
        }

        @Test
        @DisplayName("getUserAuctions - Caso Nessun Risultato")
        public void testGetUserAuctions_NoResults() {
                int testPageSize = 10;
                List<Auction> results = auctionService.getUserAuctions(
                                "utente_inesistente",
                                "keyword_impossibile",
                                "venditore",
                                1,
                                testPageSize,
                                "tipo_strano",
                                "categoria_strana",
                                testPageSize);
                assertNotNull(results);
                assertTrue(results.isEmpty());
        }
}