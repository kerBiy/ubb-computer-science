package ubb.map.practic2023v1.controller;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.DatePicker;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.cell.PropertyValueFactory;
import ubb.map.practic2023v1.domain.Hotel;
import ubb.map.practic2023v1.domain.SpecialOffer;
import ubb.map.practic2023v1.service.Service;

import java.time.LocalDate;
import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;

public class OffersController extends GenericController {

    @FXML
    private DatePicker startDatePicker;

    @FXML
    private DatePicker endDatePicker;

    @FXML
    private TableView<SpecialOffer> offersTableView;

    @FXML
    private TableColumn<SpecialOffer, LocalDate> startDateColumn;

    @FXML
    private TableColumn<SpecialOffer, LocalDate> endDateColumn;

    @FXML
    private TableColumn<SpecialOffer, Integer> discountColumn;

    private ObservableList<SpecialOffer> specialOffers = FXCollections.observableArrayList();
    private Hotel currentHotel;

    @Override
    public void setSomething(Optional<Object> parameter) {
        parameter.ifPresent(value -> {
            if (value instanceof Hotel) {
                currentHotel = (Hotel) value;
            }
        });
    }

    @FXML
    public void initialize() {
        // Initialize table columns
        startDateColumn.setCellValueFactory(new PropertyValueFactory<>("startDate"));
        endDateColumn.setCellValueFactory(new PropertyValueFactory<>("endDate"));
        discountColumn.setCellValueFactory(new PropertyValueFactory<>("percents"));

        offersTableView.setItems(specialOffers);
    }

    @FXML
    public void onSearchOffersClick(ActionEvent event) {
        LocalDate startDate = startDatePicker.getValue();
        LocalDate endDate = endDatePicker.getValue();

        if (startDate != null && endDate != null && currentHotel != null) {
            List<SpecialOffer> offers = service.getOffersByHotelAndPeriod(currentHotel, startDate, endDate);
            specialOffers.setAll(offers);
        }
    }
}
