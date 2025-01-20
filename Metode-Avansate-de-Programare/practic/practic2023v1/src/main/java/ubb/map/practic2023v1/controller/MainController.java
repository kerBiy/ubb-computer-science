package ubb.map.practic2023v1.controller;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.input.MouseEvent;
import ubb.map.practic2023v1.GUI;
import ubb.map.practic2023v1.domain.Hotel;
import ubb.map.practic2023v1.service.Service;

import java.util.Optional;
import java.util.stream.Collectors;

public class MainController extends GenericController {

    @FXML
    private Label titleLabel;

    @FXML
    private ComboBox<String> locationComboBox;

    @FXML
    private TableView<Hotel> hotelTableView;

    @FXML
    private TableColumn<Hotel, String> hotelNameColumn;

    @FXML
    private TableColumn<Hotel, Integer> hotelRoomsColumn;

    @FXML
    private TableColumn<Hotel, Double> hotelPriceColumn;

    private ObservableList<String> locations = FXCollections.observableArrayList();
    private ObservableList<Hotel> hotels = FXCollections.observableArrayList();

    @Override
    public void setSomething(Optional<Object> parameter) {
        parameter.ifPresent(value -> titleLabel.setText(value.toString()));

        // Initialize columns
        hotelNameColumn.setCellValueFactory(new PropertyValueFactory<>("hotelName"));
        hotelRoomsColumn.setCellValueFactory(new PropertyValueFactory<>("noRooms"));
        hotelPriceColumn.setCellValueFactory(new PropertyValueFactory<>("pricePerNight"));
        hotelTableView.setItems(hotels);

        // Load locations into ComboBox
        locations.setAll(service.getAllLocations().stream()
                .map(location -> location.getLocationName())
                .collect(Collectors.toList()));
        locationComboBox.setItems(locations);

        hotelTableView.setOnMouseClicked(this::onHotelDoubleClick);
    }

    @FXML
    public void onLocationSelected(ActionEvent event) {
        String selectedLocation = locationComboBox.getValue();
        if (selectedLocation != null) {
            hotels.setAll(service.getHotelsByLocation(selectedLocation));
        }
    }

    private void onHotelDoubleClick(MouseEvent event) {
        if (event.getClickCount() == 2) {
            Hotel selectedHotel = hotelTableView.getSelectionModel().getSelectedItem();
            if (selectedHotel != null) {
                GUI.showOffersView(selectedHotel);
            }
        }
    }
}