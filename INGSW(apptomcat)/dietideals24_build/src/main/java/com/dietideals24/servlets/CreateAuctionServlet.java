package com.dietideals24.servlets;

import com.dietideals24.models.Auction;
import com.dietideals24.services.AuctionService;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.math.BigDecimal;
import java.sql.Timestamp;
import javax.imageio.ImageIO;
import javax.servlet.ServletException;
import javax.servlet.annotation.MultipartConfig;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import javax.servlet.http.Part;

@WebServlet("/createAuction")
@MultipartConfig(fileSizeThreshold = 1024 * 1024, // 1MB in memoria
        maxFileSize = 5 * 1024 * 1024, // 5MB per file
        maxRequestSize = 10 * 1024 * 1024 // 10MB per richiesta
)
public class CreateAuctionServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;

    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        HttpSession session = request.getSession(false);
        if (session != null && session.getAttribute("username") != null) {
            String role = (String) session.getAttribute("role");
            if (role.equals("venditore")) {
                request.getRequestDispatcher("/createAuctionSeller.html").forward(request, response);
            } else if (role.equals("compratore")) {
                request.getRequestDispatcher("/createAuctionBuyer.html").forward(request, response);
            } else {
                response.sendRedirect("/dietideals24/index");
            }
        } else {
            response.sendRedirect(request.getContextPath() + "/login");
        }
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        HttpSession session = request.getSession(false);
        if (session != null && session.getAttribute("username") != null) {
            // Gestione dell'upload dell'immagine
            Part filePart = request.getPart("image");
            String imagePath = null;
            if (filePart != null && filePart.getSize() > 0) {
                InputStream fileContent = filePart.getInputStream();
                BufferedImage originalImage = ImageIO.read(fileContent);

                // Verifica se l'immagine è stata letta correttamente
                if (originalImage != null) {
                    // Ridimensiona l'immagine a circa 250x200 pixel
                    int newWidth = 250;
                    int newHeight = 200;
                    Image resizedImage = originalImage.getScaledInstance(newWidth, newHeight, Image.SCALE_SMOOTH);

                    BufferedImage outputImage = new BufferedImage(newWidth, newHeight, BufferedImage.TYPE_INT_RGB);
                    Graphics2D g2d = outputImage.createGraphics();
                    g2d.drawImage(resizedImage, 0, 0, null);
                    g2d.dispose();

                    // Salva l'immagine ridimensionata
                    String fileName = "auction_" + System.currentTimeMillis() + ".jpg";
                    String uploadDir = getServletContext().getRealPath("/static/images/auctions/");
                    File uploadFolder = new File(uploadDir);
                    if (!uploadFolder.exists()) {
                        uploadFolder.mkdirs();
                    }
                    String uploadPath = uploadDir + File.separator + fileName;
                    ImageIO.write(outputImage, "jpg", new File(uploadPath));

                    // Memorizza il percorso relativo da salvare nel DB
                    imagePath = "/static/images/auctions/" + fileName;
                }
            }

            String title = request.getParameter("title");
            String description = request.getParameter("description");
            String category = request.getParameter("category");
            String auctionType = request.getParameter("auctionType");
            String startPriceStr = request.getParameter("startPrice");
            BigDecimal startPrice = (startPriceStr != null && !startPriceStr.isEmpty())
                    ? new BigDecimal(startPriceStr)
                    : null;
            BigDecimal currentPrice = startPrice;
            BigDecimal minPrice = request.getParameter("minPrice") != null
                    && !request.getParameter("minPrice").isEmpty()
                            ? new BigDecimal(request.getParameter("minPrice"))
                            : null;
            BigDecimal decrementAmount = request.getParameter("decrementAmount") != null
                    && !request.getParameter("decrementAmount").isEmpty()
                            ? new BigDecimal(request.getParameter("decrementAmount"))
                            : null;

            String decrementIntervalMinutesStr = request.getParameter("decrementIntervalMinutes");
            Integer decrementIntervalMinutes = 0;
            if (decrementIntervalMinutesStr != null && !decrementIntervalMinutesStr.isEmpty()) {
                try {
                    decrementIntervalMinutes = Integer.parseInt(decrementIntervalMinutesStr);
                } catch (NumberFormatException e) {
                    response.sendRedirect("/dietideals24/index");
                    return;
                }
            }

            String endTimeStr = request.getParameter("endTime");
            if (endTimeStr != null && !endTimeStr.trim().isEmpty()) {
                endTimeStr = endTimeStr.replace("T", " ") + ":00";
            } else {
                throw new ServletException("End time is missing.");
            }

            Timestamp startTime = null;
            Timestamp endTime = Timestamp.valueOf(endTimeStr);
            String status = "attiva";

            // Verifica il ruolo dell'utente e crea l'asta di conseguenza
            String role = (String) session.getAttribute("role");
            String username = (String) session.getAttribute("username");
            Auction auction = null;
            AuctionService auctionService = new AuctionService();

            if (role.equals("venditore")) {
                if (auctionType.equals("silenziosa") || auctionType.equals("ribasso")) {
                    String sellerId = username;
                    if (sellerId == null || sellerId.isEmpty()) {
                        response.sendRedirect("/dietideals24/index");
                        return;
                    }
                    auction = new Auction(0, sellerId, null, title, description, category, auctionType,
                            startPrice, currentPrice, minPrice, decrementAmount, decrementIntervalMinutes, startTime,
                            endTime, status, null, imagePath);
                    auctionService.createAuction(auction);
                    response.sendRedirect(request.getContextPath() + "/user-auctions?action=my_auctions");
                } else {
                    response.sendRedirect("/dietideals24/index");
                }
            } else if (role.equals("compratore")) {
                if (auctionType.equals("inversa")) {
                    String buyerId = username;
                    if (buyerId == null || buyerId.isEmpty()) {
                        response.sendRedirect("/dietideals24/index");
                        return;
                    }
                    auction = new Auction(0, null, buyerId, title, description, category, auctionType,
                            startPrice, currentPrice, minPrice, decrementAmount, decrementIntervalMinutes, startTime,
                            endTime, status, null, imagePath);
                    auctionService.createAuction(auction);
                    response.sendRedirect(request.getContextPath() + "/user-auctions?action=my_auctions");
                } else {
                    response.sendRedirect("/dietideals24/index");
                }
            } else {
                response.sendRedirect("/dietideals24/index");
            }
        } else {
            response.sendRedirect(request.getContextPath() + "/login");
        }
    }
}
