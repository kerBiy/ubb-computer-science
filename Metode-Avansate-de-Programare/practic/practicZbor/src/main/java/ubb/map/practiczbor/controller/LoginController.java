package ubb.map.practiczbor.controller;

import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.stage.Stage;
import ubb.map.practiczbor.GUI;
import ubb.map.practiczbor.domain.Client;

import java.util.Optional;

public class LoginController extends GenericController {
    @FXML
    private TextField usernameField;

    @FXML
    private Button loginButton;

    @Override
    public void setSomething(Optional<Object> parameter) {
        loginButton.setOnAction(event -> handleLogin());
    }

    private void handleLogin() {
        String username = usernameField.getText();
        if (username != null && !username.trim().isEmpty()) {
            Optional<Client> client = service.findClientByUsername(username);

            if (client.isPresent()) {
                GUI.flightView(client.get());
            } else {
                Alert errorAlert = new Alert(Alert.AlertType.ERROR);
                errorAlert.setTitle("LogIn Error");
                errorAlert.setHeaderText(null);
                errorAlert.setContentText("Username does not exist!");
                errorAlert.showAndWait();
            }

        } else {
            Alert errorAlert = new Alert(Alert.AlertType.ERROR);
            errorAlert.setTitle("LogIn Error");
            errorAlert.setHeaderText(null);
            errorAlert.setContentText("Username cannot be empty!");
            errorAlert.showAndWait();
        }
    }
}
