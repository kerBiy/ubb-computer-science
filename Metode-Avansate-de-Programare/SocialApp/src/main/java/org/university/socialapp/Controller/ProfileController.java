package org.university.socialapp.Controller;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
import javafx.util.Pair;
import org.university.socialapp.Domain.User;
import org.university.socialapp.Service.Service;
import org.university.socialapp.Service.ServiceException;

import java.util.List;
import java.util.Optional;

public class ProfileController extends GenericController {

    @FXML
    private Label usernameLabel;

    @FXML
    private Label friendsCountLabel;

    private Pair<User, User> user;

    @Override
    public void setSomething(Optional<Object> parameter) {
        this.user = (Pair<User, User>) parameter.get();
    }

    @Override
    public void setService(Service service) {
        super.service = service;
        loadProfile();
    }

    private void loadProfile() {
        if (user != null) {
            usernameLabel.setText(user.getValue().getName());
            friendsCountLabel.setText(String.valueOf(service.getFriendships(user.getValue().getName(), "accepted").size()));
        }
    }

    @FXML
    private void handleRemoveFriend() {
        try {
            service.removeFriendship(user.getKey().getName(), user.getValue().getName());
            service.removeFriendship(user.getValue().getName(), user.getKey().getName());
            friendsCountLabel.setText("Removed as a friend");
        } catch (ServiceException e) {
            friendsCountLabel.setText("Error: Unable to remove friend");
        }
    }


    @FXML
    private void handleClose() {
        Stage stage = (Stage) usernameLabel.getScene().getWindow();
        stage.close();
    }
}