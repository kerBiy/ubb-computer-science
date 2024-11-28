package ro.ubbcluj.map.socialnetwork;

import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.TextField;
import javafx.stage.Stage;
import ro.ubbcluj.map.socialnetwork.controller.MessageAlert;
import ro.ubbcluj.map.socialnetwork.domain.Utilizator;
import ro.ubbcluj.map.socialnetwork.service.UtilizatorService;

public class RegisterController {

    private UtilizatorService utilizatorService;
    private Stage stage;

    @FXML
    private TextField textFieldUsername;
    @FXML
    private TextField textFieldPrenume;
    @FXML
    private TextField textFieldNume;
    @FXML
    private TextField textFieldPassword;

    public void setService(UtilizatorService utilizatorService, Stage stage){
        this.utilizatorService = utilizatorService;
        this.stage = stage;

    }

    public void handleCreate() {
        String username = textFieldUsername.getText();
        String firstName = textFieldPrenume.getText();
        String lastName = textFieldNume.getText();
        String password = textFieldPassword.getText();
        String hashedPassword = UtilizatorService.hashPassword(password);
        System.out.println(hashedPassword);
        Utilizator utilizator = new Utilizator(username,firstName,lastName);
        utilizator.setPassword(hashedPassword);
        try {
            utilizatorService.adaugaUtilizator(utilizator);
            MessageAlert.showMessage(stage, Alert.AlertType.INFORMATION,"Creare cont","Cont creat cu succes!");
            stage.close();
        }catch (Exception e){
            e.printStackTrace();
            MessageAlert.showErrorMessage(null, "Eroare: " + e.getMessage());
        }
    }


    public void handleCancel() {
        stage.close();
    }
}
