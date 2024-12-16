package org.university.socialapp.Controller;

import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;

import java.util.Optional;

public class FriendRequestController extends GenericController {
    private String username;

    @FXML
    TextField usernameTextField;

    @FXML
    Label resultLabel;

    @Override
    public void setSomething(Optional<Object> parameter) {
        username = (String) parameter.get();
    }

    public void handleAdd() {
        if (!usernameTextField.getText().isEmpty()) {
            if (service.userExists(usernameTextField.getText())) {
                try {
                    service.addFriendship(username, usernameTextField.getText());
                    resultLabel.setText("Friend request sent!");
                    resultLabel.setStyle("-fx-text-fill: green");
                } catch (Exception e) {
                    MessageAlert.showErrorMessage(null, e.getMessage());
                }
            } else {
                resultLabel.setText("User does not exist!");
                resultLabel.setStyle("-fx-text-fill: red");
            }
        }
    }

}