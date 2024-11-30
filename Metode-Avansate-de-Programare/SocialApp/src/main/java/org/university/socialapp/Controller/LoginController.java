package org.university.socialapp.Controller;

import javafx.fxml.FXML;
import javafx.scene.control.TextField;
import javafx.stage.Stage;
//import org.university.socialapp.Controller.RegisterController;
import org.university.socialapp.Domain.User;
import org.university.socialapp.Service.Service;
import org.university.socialapp.GUI;

import java.util.Optional;


public class LoginController {

    private Service service;
    private Stage stage;
    private GUI main;

    @FXML
    private TextField textUsername;
    @FXML
    private TextField textPassword;

    public void setService(Service service, Stage stage) {
        this.service = service;
        this.stage = stage;
    }

    public void handleLogin() {
        if (textUsername.getText().isEmpty()) {
            MessageAlert.showErrorMessage(null, "Enter the username");
        } else if (textPassword.getText().isEmpty()) {
            MessageAlert.showErrorMessage(null, "Enter the password");
        } else {
            if (service.verifyLogin(textUsername.getText(), textPassword.getText())) {
                try {
                    Optional<User> user = service.findUser(textUsername.getText());
                    main.openUserStage(user.get());
                } catch (Exception e) {
                    e.printStackTrace();
                    MessageAlert.showErrorMessage(null, "Eroare: " + e.getMessage());
                }
            } else {
                MessageAlert.showErrorMessage(null, "Datele de logare sunt incorecte");
            }
        }
    }

    public void setMain(GUI main) {
        this.main = main;
    }
}
