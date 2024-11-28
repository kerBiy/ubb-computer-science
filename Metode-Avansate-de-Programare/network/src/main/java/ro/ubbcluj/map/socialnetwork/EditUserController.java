package ro.ubbcluj.map.socialnetwork;

import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.TextField;
import javafx.stage.Stage;
import ro.ubbcluj.map.socialnetwork.controller.MessageAlert;
import ro.ubbcluj.map.socialnetwork.domain.Utilizator;
import ro.ubbcluj.map.socialnetwork.service.UtilizatorService;

public class EditUserController {

    private UtilizatorService utilizatorService;
    private Stage stage;

    @FXML
    private TextField textFieldUsername;
    @FXML
    private TextField textFieldPrenume;
    @FXML
    private TextField textFieldNume;

    public void setUtilizatorService(UtilizatorService utilizatorService, Stage stage, Utilizator utilizator) {
        this.utilizatorService = utilizatorService;
        this.stage = stage;

        textFieldUsername.setText(utilizator.getUsername());
        textFieldPrenume.setText(utilizator.getFirstName());
        textFieldNume.setText(utilizator.getLastName());

        textFieldUsername.setEditable(false);
    }

    public void handleSave() {
        String username = textFieldUsername.getText();
        String firstName = textFieldPrenume.getText();
        String lastName = textFieldNume.getText();
        try{
            utilizatorService.updateUtilizator(username, firstName, lastName);
            MessageAlert.showMessage(stage, Alert.AlertType.INFORMATION,"Update","Ti-ai actualizat profilul cu succes");
            stage.close();
        }catch (Exception e){
            MessageAlert.showErrorMessage(null, "Eroare: " + e.getMessage());
        }

    }

    public void handleCancel() {
        stage.close();
    }
}
