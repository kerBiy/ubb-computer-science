package ubb.map.practiczbor.controller;

import javafx.beans.property.ReadOnlyObjectWrapper;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import ubb.map.practiczbor.domain.Client;
import ubb.map.practiczbor.domain.Flight;
import ubb.map.practiczbor.domain.Ticket;
import ubb.map.practiczbor.service.Service;
import ubb.map.practiczbor.utils.Observer;

import java.time.LocalDate;
import java.time.LocalDateTime;
import java.util.List;
import java.util.Optional;

public class FlightController extends GenericController implements Observer {

    @FXML
    private ComboBox<String> fromComboBox;

    @FXML
    private ComboBox<String> toComboBox;

    @FXML
    private DatePicker departureDatePicker;

    @FXML
    private TableView<Flight> flightTableView;

    @FXML
    private TableColumn<Flight, String> fromColumn;

    @FXML
    private TableColumn<Flight, String> toColumn;

    @FXML
    private TableColumn<Flight, LocalDate> departureColumn;

    @FXML
    private TableColumn<Flight, Integer> seatsColumn;

    @FXML
    private TableColumn<Flight, Integer> availableSeatsColumn;

    @FXML
    private Button purchaseButton;

    private Client currentClient;

    @Override
    public void setService(Service service) {
        super.setService(service);
        service.addObserver(this);
    }

    @Override
    public void setSomething(Optional<Object> parameter) {
        if (parameter.isPresent() && parameter.get() instanceof Client) {
            currentClient = (Client) parameter.get();
        }
        loadLocations();
        setupTable();
        addListeners();
    }

    private void loadLocations() {
        List<String> locations = service.getAllLocations();
        ObservableList<String> locationList = FXCollections.observableArrayList(locations);
        fromComboBox.setItems(locationList);
        toComboBox.setItems(locationList);
    }

    private void setupTable() {
        fromColumn.setCellValueFactory(new PropertyValueFactory<>("from"));
        toColumn.setCellValueFactory(new PropertyValueFactory<>("to"));
        departureColumn.setCellValueFactory(new PropertyValueFactory<>("departureTime"));
        seatsColumn.setCellValueFactory(new PropertyValueFactory<>("seats"));
        availableSeatsColumn.setCellValueFactory(cellData -> {
            Flight flight = cellData.getValue();
            int purchasedTickets = service.getTicketCountForFlight(flight.getId());
            int availableSeats = flight.getSeats() - purchasedTickets;
            return new ReadOnlyObjectWrapper<>(availableSeats);
        });
    }

    private void addListeners() {
        fromComboBox.setOnAction(event -> filterFlights());
        toComboBox.setOnAction(event -> filterFlights());
        departureDatePicker.setOnAction(event -> filterFlights());

        purchaseButton.setOnAction(event -> handlePurchase());
    }

    private void filterFlights() {
        String from = fromComboBox.getValue();
        String to = toComboBox.getValue();
        LocalDate date = departureDatePicker.getValue();

        if (from != null && to != null && date != null) {
            List<Flight> flights = service.getFilteredFlights(from, to, date);
            flightTableView.setItems(FXCollections.observableArrayList(flights));
        }
    }

    private void handlePurchase() {
        Flight selectedFlight = flightTableView.getSelectionModel().getSelectedItem();

        if (selectedFlight != null && currentClient != null) {
            Ticket ticket = new Ticket(
                    currentClient.getUsername(),
                    selectedFlight.getId(),
                    LocalDateTime.now()
            );

            service.saveTicket(ticket);

            Alert successAlert = new Alert(Alert.AlertType.INFORMATION);
            successAlert.setTitle("Purchase Successful");
            successAlert.setHeaderText(null);
            successAlert.setContentText("Ticket purchased successfully!");
            successAlert.showAndWait();
        } else {
            Alert errorAlert = new Alert(Alert.AlertType.ERROR);
            errorAlert.setTitle("Purchase Error");
            errorAlert.setHeaderText(null);
            errorAlert.setContentText("Please select a flight and ensure you are logged in.");
            errorAlert.showAndWait();
        }
    }

    @Override
    public void update() {
        flightTableView.refresh();
    }
}
