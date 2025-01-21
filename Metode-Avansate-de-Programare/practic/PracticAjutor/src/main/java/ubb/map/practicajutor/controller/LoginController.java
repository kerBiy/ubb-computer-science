package ubb.map.practicajutor.controller;

import javafx.fxml.FXML;
import javafx.scene.control.ComboBox;
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;
import ubb.map.practicajutor.GUI;
import ubb.map.practicajutor.domain.Persoana;

import java.util.Optional;

public class LoginController extends GenericController {

    @FXML
    private ComboBox<String> usernameComboBox;

    @FXML
    private PasswordField passwordField;

    @FXML
    private Label errorLabel;

    @FXML
    private Label switchToRegisterLabel;

    @Override
    public void setSomething(Optional<Object> parameter) {
        // Setări suplimentare dacă sunt necesare

        // Populăm ComboBox-ul cu utilizatorii existenți
        service.getAllPersoane().forEach(persoana ->
                usernameComboBox.getItems().add(persoana.getUsername())
        );

        // Eveniment pentru a naviga la pagina de înregistrare
        switchToRegisterLabel.setOnMouseClicked(event -> {
            GUI.registerView();
        });
    }

    @FXML
    public void handleLogin() {
        String selectedUsername = usernameComboBox.getValue();
        String password = passwordField.getText();

        if (selectedUsername == null || selectedUsername.isEmpty() || password.isEmpty()) {
            errorLabel.setText("Completați toate câmpurile!");
            return;
        }

        Optional<Persoana> user = service.findPersoanaByUsernameAndPassword(selectedUsername, password);

        if (user.isPresent()) {
            System.out.println("Autentificare reușită pentru: " + selectedUsername);
            GUI.mainView(user.get());
        } else {
            errorLabel.setText("Username sau parolă incorecte!");
        }
    }
}