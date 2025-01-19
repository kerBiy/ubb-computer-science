package ro.map.practic1.controller;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.cell.PropertyValueFactory;
import ro.map.practic1.domain.Order;
import ro.map.practic1.domain.MenuItem;
import ro.map.practic1.service.Service;
import ro.map.practic1.utils.Observer;

import java.util.List;
import java.util.stream.Collectors;

public class StaffController extends GenericController implements Observer {

    @FXML
    private TableView<OrderViewModel> ordersTable;

    @FXML
    private TableColumn<OrderViewModel, Integer> tableIdColumn;

    @FXML
    private TableColumn<OrderViewModel, String> dateColumn;

    @FXML
    private TableColumn<OrderViewModel, String> itemsColumn;

    private final ObservableList<OrderViewModel> ordersData = FXCollections.observableArrayList();

    @Override
    public void setService(Service service) {
        super.setService(service);
        service.addObserver(this);

        tableIdColumn.setCellValueFactory(new PropertyValueFactory<>("tableId"));
        dateColumn.setCellValueFactory(new PropertyValueFactory<>("date"));
        itemsColumn.setCellValueFactory(new PropertyValueFactory<>("items"));

        ordersTable.setItems(ordersData);
        ordersTable.setPrefWidth(600);

        loadOrders();
    }

    private void loadOrders() {
        List<Order> orders = service.getOrdersSortedByDate();
        List<OrderViewModel> viewModels = orders.stream().map(this::toViewModel).collect(Collectors.toList());
        ordersData.setAll(viewModels);
    }

    private OrderViewModel toViewModel(Order order) {
        String items = order.getMenuItems().stream()
                .map(itemId -> {
                    MenuItem menuItem = service.getMenuItemById(itemId);
                    return menuItem.getItem();
                })
                .collect(Collectors.joining(", "));
        return new OrderViewModel(order.getTable(), order.getDate().toString(), items);
    }

    @Override
    public void update() {
        loadOrders();
    }

    public static class OrderViewModel {
        private final Integer tableId;
        private final String date;
        private final String items;

        public OrderViewModel(Integer tableId, String date, String items) {
            this.tableId = tableId;
            this.date = date;
            this.items = items;
        }

        public Integer getTableId() {
            return tableId;
        }

        public String getDate() {
            return date;
        }

        public String getItems() {
            return items;
        }
    }
}
