// ClientController.java
package ubb.map.practic2023v1.controller;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.input.MouseEvent;
import ubb.map.practic2023v1.GUI;
import ubb.map.practic2023v1.domain.Client;
import ubb.map.practic2023v1.domain.SpecialOffer;
import ubb.map.practic2023v1.service.Service;

import java.sql.Date;
import java.time.LocalDate;
import java.util.Optional;
import java.util.stream.Collectors;

public class ClientController extends GenericController {

    @FXML
    private TableView<SpecialOfferDisplay> offersTableView;

    @FXML
    private TableColumn<SpecialOfferDisplay, String> hotelNameColumn;

    @FXML
    private TableColumn<SpecialOfferDisplay, String> locationNameColumn;

    @FXML
    private TableColumn<SpecialOfferDisplay, LocalDate> startDateColumn;

    @FXML
    private TableColumn<SpecialOfferDisplay, LocalDate> endDateColumn;

    private ObservableList<SpecialOfferDisplay> specialOffers = FXCollections.observableArrayList();
    private Client currentClient;

    @Override
    public void setSomething(Optional<Object> parameter) {
        parameter.ifPresent(value -> {
            if (value instanceof Client) {
                currentClient = (Client) value;
                loadEligibleOffers();
            }
        });

        // Initialize table columns
        hotelNameColumn.setCellValueFactory(new PropertyValueFactory<>("hotelName"));
        locationNameColumn.setCellValueFactory(new PropertyValueFactory<>("locationName"));
        startDateColumn.setCellValueFactory(new PropertyValueFactory<>("startDate"));
        endDateColumn.setCellValueFactory(new PropertyValueFactory<>("endDate"));

        offersTableView.setItems(specialOffers);

        // Add double-click event to open reservation view
        offersTableView.setOnMouseClicked(this::onOfferDoubleClick);
    }

    private void loadEligibleOffers() {
        if (currentClient != null) {
            java.sql.Date today = Date.valueOf(LocalDate.now());

            // Get all eligible offers for the client
            specialOffers.setAll(service.getAllSpecialOffers().stream()
                    .filter(offer -> offer.getPercents() < currentClient.getFidelityGrade()
                            && offer.getEndDate().after(today))
                    .map(offer -> {
                        var hotel = service.getHotelById(offer.getHotelId());
                        var location = service.getLocationById(hotel.getLocationId());
                        return new SpecialOfferDisplay(
                                offer,
                                hotel.getHotelName(),
                                location.getLocationName(),
                                ((Date) offer.getStartDate()).toLocalDate(),
                                ((Date) offer.getEndDate()).toLocalDate()
                        );
                    })
                    .collect(Collectors.toList()));
        }
    }

    private void onOfferDoubleClick(MouseEvent event) {
        if (event.getClickCount() == 2) {
            SpecialOfferDisplay selectedOfferDisplay = offersTableView.getSelectionModel().getSelectedItem();
            if (selectedOfferDisplay != null) {
                GUI.reservationView(currentClient, selectedOfferDisplay.getSpecialOffer());
            }
        }
    }

    // Helper class for displaying special offers
    public static class SpecialOfferDisplay {
        private final SpecialOffer specialOffer;
        private final String hotelName;
        private final String locationName;
        private final LocalDate startDate;
        private final LocalDate endDate;

        public SpecialOfferDisplay(SpecialOffer specialOffer, String hotelName, String locationName, LocalDate startDate, LocalDate endDate) {
            this.specialOffer = specialOffer;
            this.hotelName = hotelName;
            this.locationName = locationName;
            this.startDate = startDate;
            this.endDate = endDate;
        }

        public SpecialOffer getSpecialOffer() {
            return specialOffer;
        }

        public String getHotelName() {
            return hotelName;
        }

        public String getLocationName() {
            return locationName;
        }

        public LocalDate getStartDate() {
            return startDate;
        }

        public LocalDate getEndDate() {
            return endDate;
        }
    }
}