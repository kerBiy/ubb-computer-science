package org.university.socialapp.Controller;

import javafx.fxml.FXML;
import javafx.scene.control.TextField;

import org.university.socialapp.GUI;


public class LoginController extends GenericController {
    @FXML
    private TextField usernameTextField;
    @FXML
    private TextField passwordTextField;

    public void handleLogin() {
        if (usernameTextField.getText().isEmpty()) {
            MessageAlert.showErrorMessage(null, "Username cannot be empty");
        } else if (passwordTextField.getText().isEmpty()) {
            MessageAlert.showErrorMessage(null, "Password cannot be empty");
        } else {
            if (service.verifyLogin(usernameTextField.getText(), passwordTextField.getText())) {
                GUI.loggedUserView(usernameTextField.getText());
            } else {
                MessageAlert.showErrorMessage(null, "Invalid username or password");
            }
        }
    }

    public void handleSignUp() {
        GUI.signUpView();
    }

}
