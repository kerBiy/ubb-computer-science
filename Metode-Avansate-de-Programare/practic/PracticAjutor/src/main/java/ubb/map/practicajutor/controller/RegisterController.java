package ubb.map.practicajutor.controller;

import javafx.fxml.FXML;
import javafx.scene.control.ComboBox;
import javafx.scene.control.TextField;
import javafx.scene.control.Label;
import ubb.map.practicajutor.GUI;
import ubb.map.practicajutor.domain.Persoana;

import java.util.Optional;

public class RegisterController extends GenericController {

    @FXML
    private TextField numeField;

    @FXML
    private TextField prenumeField;

    @FXML
    private TextField usernameField;

    @FXML
    private TextField parolaField;

    @FXML
    private ComboBox<String> orasComboBox;

    @FXML
    private Label switchToLoginLabel;

    @Override
    public void setSomething(Optional<Object> parameter) {
        // Setări suplimentare dacă sunt necesare
        orasComboBox.getItems().addAll("Cluj-Napoca", "București", "Iași", "Timișoara");

        switchToLoginLabel.setOnMouseClicked(event -> {
            GUI.loginView();
        });
    }

    @FXML
    public void handleRegister() {
        String nume = numeField.getText();
        String prenume = prenumeField.getText();
        String username = usernameField.getText();
        String parola = parolaField.getText();
        String oras = orasComboBox.getValue();

        if (nume.isEmpty() || prenume.isEmpty() || username.isEmpty() || parola.isEmpty() || oras == null) {
            System.out.println("Toate câmpurile trebuie completate!");
            return;
        }

        Persoana persoana = new Persoana(null, nume, prenume, username, parola, oras, null, null, null);
        service.savePersoana(persoana);

        System.out.println("Utilizator înregistrat cu succes!");
    }
}