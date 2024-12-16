package org.university.socialapp.Controller;

import javafx.fxml.FXML;
import javafx.scene.control.TextField;
import org.university.socialapp.GUI;

import java.util.Optional;

public class SignUpController extends GenericController {
    @FXML
    private TextField usernameTextField;
    @FXML
    private TextField passwordTextField;

    public void handleLogin() {
        GUI.loginView();
    }

    public void handleSignUp() {
        if (usernameTextField.getText().isEmpty()) {
            MessageAlert.showErrorMessage(null, "Username cannot be empty");
        } else if (passwordTextField.getText().isEmpty()) {
            MessageAlert.showErrorMessage(null, "Password cannot be empty");
        } else {
            try {
                service.addUser(usernameTextField.getText(), passwordTextField.getText());
                GUI.loggedUserView(usernameTextField.getText());
            } catch (Exception e) {
                MessageAlert.showErrorMessage(null, e.getMessage());
            }
        }
    }

    @Override
    public void setSomething(Optional<Object> parameter) {
        
    }
}
