package ubb.map.examenpractic.controller;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.CheckBox;
import javafx.scene.control.ComboBox;
import javafx.scene.control.Label;
import javafx.scene.control.TextArea;
import ubb.map.examenpractic.service.Service;
import ubb.map.examenpractic.utils.Observer;

import java.util.List;
import java.util.Optional;

public class ClientController extends GenericController implements Observer {

    @FXML
    private ComboBox<String> departureCityComboBox;

    @FXML
    private ComboBox<String> destinationCityComboBox;

    @FXML
    private CheckBox directRoutesOnlyCheckBox;

    @FXML
    private TextArea resultTextArea;

    @FXML
    private Label notificationLabel;

    private String lastDepartureCity;
    private String lastDestinationCity;

    @Override
    public void setService(Service service) {
        super.setService(service);
        service.addObserver(this);
    }

    @Override
    public void update() {
        if (lastDepartureCity != null && lastDestinationCity != null) {
            int count = service.getActiveFilterCount(lastDepartureCity, lastDestinationCity) - 1; // Exclude current client
            if (count > 0) {
                notificationLabel.setText(String.format("%d other user(s) are looking at the same route.", count));
            } else {
                notificationLabel.setText("");
            }
        } else {
            notificationLabel.setText("");
        }
    }

    @Override
    public void setSomething(Optional<Object> parameter) {
        List<String> cityNames = service.getCityNames();
        departureCityComboBox.getItems().setAll(cityNames);
        destinationCityComboBox.getItems().setAll(cityNames);

        departureCityComboBox.setOnAction(e -> updateFilter());
        destinationCityComboBox.setOnAction(e -> updateFilter());
    }

    private void updateFilter() {
        String newDepartureCity = departureCityComboBox.getValue();
        String newDestinationCity = destinationCityComboBox.getValue();

        if (lastDepartureCity != null && lastDestinationCity != null) {
            service.unregisterFilter(lastDepartureCity, lastDestinationCity);
        }

        if (newDepartureCity != null && newDestinationCity != null) {
            service.registerFilter(newDepartureCity, newDestinationCity);
            lastDepartureCity = newDepartureCity;
            lastDestinationCity = newDestinationCity;
        }
        update();
    }

    @FXML
    private void handleSearch(ActionEvent event) {
        String departureCity = departureCityComboBox.getValue();
        String destinationCity = destinationCityComboBox.getValue();

        if (departureCity == null || destinationCity == null) {
            resultTextArea.setText("Error: Please select both departure and destination cities.");
            return;
        }

        boolean directRoutesOnly = directRoutesOnlyCheckBox.isSelected();

        List<String> routes = service.searchRoutes(departureCity, destinationCity, directRoutesOnly);

        if (routes.isEmpty()) {
            resultTextArea.setText("No routes found.");
        } else {
            StringBuilder result = new StringBuilder();
            for (String route : routes) {
                int price = service.calculatePrice(route);
                result.append(String.format("%s | Price: %d\n", route, price));
            }
            resultTextArea.setText(result.toString());
        }
    }

}