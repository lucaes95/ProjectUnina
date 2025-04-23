package com.dietideals24.utils;

import com.dietideals24.models.Auction;
import java.time.temporal.ChronoUnit;
import static org.junit.jupiter.api.Assertions.*;

public class AuctionTestAssertions {

        public static void assertAuctionFieldsEqual(Auction expected, Auction actual) {
                assertNotNull(actual, "L'oggetto Auction attuale non dovrebbe essere nullo");
                assertNotNull(expected, "L'oggetto Auction atteso non dovrebbe essere nullo");

                assertEquals(expected.getSellerId(), actual.getSellerId(), "Seller ID");
                assertEquals(expected.getBuyerId(), actual.getBuyerId(), "Buyer ID");
                assertEquals(expected.getTitle(), actual.getTitle(), "Title");
                assertEquals(expected.getDescription(), actual.getDescription(), "Description");
                assertEquals(expected.getCategory(), actual.getCategory(), "Category");
                assertEquals(expected.getAuctionType(), actual.getAuctionType(), "Auction Type");

                assertNotNull(expected.getStartPrice(), "Expected StartPrice non nullo");
                assertNotNull(actual.getStartPrice(), "Actual StartPrice non nullo");
                assertTrue(expected.getStartPrice().compareTo(actual.getStartPrice()) == 0,
                                "Start Price (Expected: " + expected.getStartPrice() + ", Actual: "
                                                + actual.getStartPrice() + ")");

                assertNotNull(expected.getCurrentPrice(), "Expected CurrentPrice non nullo");
                assertNotNull(actual.getCurrentPrice(), "Actual CurrentPrice non nullo");
                assertTrue(expected.getCurrentPrice().compareTo(actual.getCurrentPrice()) == 0,
                                "Current Price (Expected: " + expected.getCurrentPrice() + ", Actual: "
                                                + actual.getCurrentPrice() + ")");

                if (expected.getMinPrice() != null) {
                        assertNotNull(actual.getMinPrice(), "Actual Min Price non nullo se atteso");
                        assertTrue(expected.getMinPrice().compareTo(actual.getMinPrice()) == 0,
                                        "Min Price (Expected: " + expected.getMinPrice() + ", Actual: "
                                                        + actual.getMinPrice() + ")");
                } else {
                        assertNull(actual.getMinPrice(), "Actual Min Price nullo se non atteso");
                }

                if (expected.getDecrementAmount() != null) {
                        assertNotNull(actual.getDecrementAmount(), "Actual Decrement Amount non nullo se atteso");
                        assertTrue(expected.getDecrementAmount().compareTo(actual.getDecrementAmount()) == 0,
                                        "Decrement Amount (Expected: " + expected.getDecrementAmount() + ", Actual: "
                                                        + actual.getDecrementAmount() + ")");
                } else {
                        assertNull(actual.getDecrementAmount(), "Actual Decrement Amount nullo se non atteso");
                }

                assertEquals(expected.getDecrementIntervalMinutes(), actual.getDecrementIntervalMinutes(),
                                "Decrement Interval");

                assertNotNull(expected.getStartTime(), "Expected Start Time non nullo");
                assertNotNull(actual.getStartTime(), "Actual Start Time non nullo");
                assertEquals(expected.getStartTime().toInstant().truncatedTo(ChronoUnit.MILLIS),
                                actual.getStartTime().toInstant().truncatedTo(ChronoUnit.MILLIS),
                                "Start Time (confrontato a millisecondi)");

                assertNotNull(expected.getEndTime(), "Expected End Time non nullo");
                assertNotNull(actual.getEndTime(), "Actual End Time non nullo");
                assertEquals(expected.getEndTime().toInstant().truncatedTo(ChronoUnit.MILLIS),
                                actual.getEndTime().toInstant().truncatedTo(ChronoUnit.MILLIS),
                                "End Time (confrontato a millisecondi)");

                assertEquals(expected.getStatus(), actual.getStatus(), "Status");
                assertEquals(expected.getWinnerId(), actual.getWinnerId(), "Winner ID");
                assertEquals(expected.getImagePath(), actual.getImagePath(), "Image Path");
        }
}