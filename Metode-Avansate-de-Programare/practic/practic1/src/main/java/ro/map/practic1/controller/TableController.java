package ro.map.practic1.controller;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.layout.VBox;
import ro.map.practic1.domain.MenuItem;
import ro.map.practic1.domain.Order;
import ro.map.practic1.domain.OrderStatus;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Optional;

public class TableController extends GenericController {

    @FXML
    private VBox menuContainer;

    @FXML
    private Button placeOrderButton;

    private Integer tableId;

    @Override
    public void setSomething(Optional<Object> parameter) {
        tableId = (Integer) parameter.orElse(null);

        Map<String, List<MenuItem>> menu = service.getMenuGroupedByCategory();
        List<MenuItem> selectedItems = new ArrayList<>();

        menu.forEach((category, items) -> {
            Label categoryLabel = new Label(category);
            menuContainer.getChildren().add(categoryLabel);

            TableView<MenuItem> tableView = new TableView<>();
            tableView.setPrefHeight(100);

            TableColumn<MenuItem, String> itemColumn = new TableColumn<>("Item");
            itemColumn.setCellValueFactory(new PropertyValueFactory<>("item"));

            TableColumn<MenuItem, String> priceCurrencyColumn = new TableColumn<>("Price");
            priceCurrencyColumn.setCellValueFactory(cellData -> {
                MenuItem menuItem = cellData.getValue();
                return new javafx.beans.property.SimpleStringProperty(menuItem.getPrice() + " " + menuItem.getCurrency());
            });

            tableView.getColumns().addAll(itemColumn, priceCurrencyColumn);

            ObservableList<MenuItem> observableItems = FXCollections.observableArrayList(items);
            tableView.setItems(observableItems);

            tableView.getSelectionModel().setSelectionMode(SelectionMode.MULTIPLE);

            tableView.getSelectionModel().selectedItemProperty().addListener((obs, oldSelection, newSelection) -> {
                if (newSelection != null && !selectedItems.contains(newSelection)) {
                    selectedItems.add(newSelection);
                }
            });

            menuContainer.getChildren().add(tableView);
        });

        placeOrderButton.setOnAction(event -> {
            if (!selectedItems.isEmpty()) {
                Order order = new Order(
                        service.generateOrderId(),
                        tableId,
                        selectedItems.stream().map(MenuItem::getId).toList(),
                        LocalDateTime.now(),
                        OrderStatus.PLACED
                );

                service.saveOrder(order);
                selectedItems.clear();
                showAlert("Order Placed", "Your order has been placed successfully!", Alert.AlertType.INFORMATION);
            } else {
                showAlert("No Items Selected", "Please select items to place an order.", Alert.AlertType.WARNING);
            }
        });
    }

    private void showAlert(String title, String message, Alert.AlertType alertType) {
        Alert alert = new Alert(alertType);
        alert.setTitle(title);
        alert.setContentText(message);
        alert.showAndWait();
    }
}