package org.university.socialapp.Controller;

import org.university.socialapp.Domain.User;
import org.university.socialapp.Service.Service;
import org.university.socialapp.Utils.Observer;

import javafx.application.Platform;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.value.ObservableValue;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.stage.Stage;
import javafx.util.Callback;

import java.time.format.DateTimeFormatter;
import java.util.Optional;

public class FriendRequestsController extends GenericController implements Observer {
    private User user;

    private static final ObservableList<User> requestsTableData = FXCollections.observableArrayList();

    @FXML
    TableView<User> requestsTable;

    @FXML
    TableColumn<User, String> requestsUsernameColumn;

    @FXML
    TableColumn<User, String> requestsSinceColumn;

    @Override
    public void update() {
        populateTables();
    }

    private class FriendshipSinceFactory implements Callback<TableColumn.CellDataFeatures<User, String>, ObservableValue<String>> {
        @Override
        public ObservableValue<String> call(TableColumn.CellDataFeatures<User, String> param) {
            DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd-MM-yyyy");
            User user = param.getValue();
            return new SimpleStringProperty(service.getFriendship(user.getName(),
                    FriendRequestsController.this.user.getName()).getDate().format(formatter));
        }
    }

    @FXML
    public void initialize() {
        requestsUsernameColumn.setCellValueFactory(new PropertyValueFactory<>("name"));
        requestsSinceColumn.setCellValueFactory(new FriendRequestsController.FriendshipSinceFactory());
        requestsTable.setItems(requestsTableData);

        Platform.runLater(() -> {
            Stage stage = (Stage) requestsTable.getScene().getWindow();
            stage.setOnCloseRequest(event -> service.removeObserver(this));
        });
    }

    @Override
    public void setService(Service service) {
        super.setService(service);
        service.addObserver(this);
        populateTables();
    }

    public void populateTables() {
        requestsTableData.setAll(service.getReceivedFriendRequests(user.getName()));
    }

    @Override
    public void setSomething(Optional<Object> parameter) {
        user = (User) parameter.get();
    }

    public void handleAcceptFriendship() {
        User friend = requestsTable.getSelectionModel().getSelectedItem();
        if (friend != null) {
            try {
                service.respondToFriendship(user.getName(), friend.getName());
            } catch (Exception e) {
                MessageAlert.showErrorMessage(null, e.getMessage());
            }
        }
    }

    public void handleRejectFriendship() {
        User friend = requestsTable.getSelectionModel().getSelectedItem();
        if (friend != null) {
            try {
                service.removeFriendship(friend.getName(), user.getName());
            } catch (Exception e) {
                MessageAlert.showErrorMessage(null, e.getMessage());
            }
        }
    }
}