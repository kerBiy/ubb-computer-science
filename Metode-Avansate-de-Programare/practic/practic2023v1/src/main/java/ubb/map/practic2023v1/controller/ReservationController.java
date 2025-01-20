// ReservationController.java
package ubb.map.practic2023v1.controller;

import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.VBox;
import ubb.map.practic2023v1.domain.Client;
import ubb.map.practic2023v1.domain.Reservation;
import ubb.map.practic2023v1.domain.SpecialOffer;
import ubb.map.practic2023v1.service.Service;

import java.time.LocalDate;
import java.util.Map;
import java.util.Optional;

public class ReservationController extends GenericController {

    @FXML
    private Label hotelNameLabel;

    @FXML
    private Label locationNameLabel;

    @FXML
    private DatePicker startDatePicker;

    @FXML
    private TextField numberOfNightsField;

    @FXML
    private Button confirmReservationButton;

    @FXML
    private VBox reservationBox;

    private SpecialOffer selectedOffer;
    private Client currentClient;

    @Override
    public void setSomething(Optional<Object> parameter) {
        parameter.ifPresent(value -> {
            if (value instanceof Map) {
                Map<String, Object> params = (Map<String, Object>) value;
                if (params.containsKey("specialOffer")) {
                    this.selectedOffer = (SpecialOffer) params.get("specialOffer");
                    loadOfferDetails();
                }
                if (params.containsKey("client")) {
                    this.currentClient = (Client) params.get("client");
                }
            }
        });
        confirmReservationButton.setOnAction(event -> handleReservation());
    }

    private void loadOfferDetails() {
        if (selectedOffer != null) {
            var hotel = service.getHotelById(selectedOffer.getHotelId());
            var location = service.getLocationById(hotel.getLocationId());
            hotelNameLabel.setText("Hotel: " + hotel.getHotelName());
            locationNameLabel.setText("Location: " + location.getLocationName());
        }
    }

    private void handleReservation() {
        try {
            if (currentClient == null || selectedOffer == null) {
                throw new IllegalArgumentException("Client or Offer not provided!");
            }

            LocalDate startDate = startDatePicker.getValue();
            int numberOfNights = Integer.parseInt(numberOfNightsField.getText());

            if (startDate == null || numberOfNights <= 0) {
                throw new IllegalArgumentException("Invalid reservation details!");
            }

            // Create and save the reservation
            Reservation reservation = new Reservation(
                    service.generateNewReservationId(),
                    currentClient.getId(),
                    selectedOffer.getHotelId(),
                    startDate,
                    numberOfNights
            );

            service.addReservation(reservation);

            // Confirmation
            Alert confirmationAlert = new Alert(Alert.AlertType.INFORMATION);
            confirmationAlert.setTitle("Reservation Confirmed");
            confirmationAlert.setHeaderText(null);
            confirmationAlert.setContentText("Reservation successfully created for " + hotelNameLabel.getText());
            confirmationAlert.showAndWait();
        } catch (Exception e) {
            // Show error alert
            Alert errorAlert = new Alert(Alert.AlertType.ERROR);
            errorAlert.setTitle("Reservation Error");
            errorAlert.setHeaderText(null);
            errorAlert.setContentText(e.getMessage());
            errorAlert.showAndWait();
        }
    }
}