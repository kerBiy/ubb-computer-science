package org.university.socialapp.Controller;

import org.university.socialapp.Domain.User;
import org.university.socialapp.Service.Service;
import org.university.socialapp.Utils.Observer;
import org.university.socialapp.GUI;

import javafx.application.Platform;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.value.ObservableValue;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.stage.Stage;
import javafx.util.Callback;
import javafx.util.Pair;

import java.time.format.DateTimeFormatter;
import java.util.Optional;


public class UserController extends GenericController implements Observer {
    private User user;

    @FXML
    TableView<User> friendsTable;

    private static final ObservableList<User> friendsTableData = FXCollections.observableArrayList();

    @FXML
    TableColumn<User, String> friendsUsernameColumn;

    @FXML
    TableColumn<User, String> friendsSinceColumn;

    @FXML
    TableColumn<User, Void> friendsDeleteColumn;

    @FXML
    Button friendshipsRequestsButton;

    @Override
    public void update() {
        populateTables();
    }

    private class FriendshipSinceFactory implements Callback<TableColumn.CellDataFeatures<User, String>, ObservableValue<String>> {
        @Override
        public ObservableValue<String> call(TableColumn.CellDataFeatures<User, String> param) {
            DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd-MM-yyyy");
            User user = param.getValue();
            return new SimpleStringProperty(service.getFriendship(UserController.this.user.getName(),
                    user.getName()).getDate().format(formatter));
        }
    }

    private class DeleteButtonFactory implements Callback<TableColumn<User, Void>, TableCell<User, Void>> {
        @Override
        public TableCell<User, Void> call(TableColumn<User, Void> param) {
            return new TableCell<>() {
                private final Button deleteButton = new Button("Delete");

                {
                    deleteButton.setOnAction(event -> {
                        User user = getTableView().getItems().get(getIndex());
                        if (user != null)
                            try {
                                service.removeFriendship(UserController.this.user.getName(), user.getName());
                                service.removeFriendship(user.getName(), UserController.this.user.getName());
                            } catch (Exception e) {
                                MessageAlert.showErrorMessage(null, e.getMessage());
                            }
                    });
                }

                @Override
                protected void updateItem(Void item, boolean empty) {
                    super.updateItem(item, empty);
                    if (empty)
                        setGraphic(null);
                    else
                        setGraphic(deleteButton);
                }
            };

        }
    }

    @FXML
    public void initialize() {
        friendsUsernameColumn.setCellValueFactory(new PropertyValueFactory<>("name"));
        friendsSinceColumn.setCellValueFactory(new FriendshipSinceFactory());
        friendsDeleteColumn.setCellFactory(new DeleteButtonFactory());
        friendsDeleteColumn.setStyle("-fx-alignment: CENTER;");

        friendsTable.setItems(friendsTableData);

        Platform.runLater(() -> {
            Stage stage = (Stage) friendsTable.getScene().getWindow();
            stage.setOnCloseRequest(event -> service.removeObserver(this));
        });

        friendsTable.setRowFactory(tv -> {
            TableRow<User> row = new TableRow<>();
            row.setOnMouseClicked(event -> {
                if (event.getClickCount() == 2 && (!row.isEmpty())) {
                    User rowData = row.getItem();
                    GUI.chatView(new Pair<>(user, rowData));
                }
            });
            return row;
        });
    }

    @Override
    public void setService(Service service) {
        super.setService(service);
        service.addObserver(this);
        populateTables();
    }

    public void populateTables() {
        friendsTableData.setAll(service.getFriendships(user.getName(), "accepted"));
        friendshipsRequestsButton.setVisible(!service.getReceivedFriendRequests(user.getName()).isEmpty());
    }

    @Override
    public void setSomething(Optional<Object> parameter) {
        user = (User) parameter.get();
    }

    public void handleLogout() {
        service.removeObserver(this);
        GUI.loginView();
    }

    public void handleAddFriendship() {
        GUI.friendRequestView(user.getName());
    }

    public void handleUpdateUser() {
//        GUI.updateUserView(user);
    }

    public void handleFriendRequests() {
        GUI.friendRequestsView(user);
    }

}