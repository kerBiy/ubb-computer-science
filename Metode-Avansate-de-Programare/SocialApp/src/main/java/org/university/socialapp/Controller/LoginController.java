package org.university.socialapp.Controller;

import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.TextField;
import javafx.scene.layout.AnchorPane;
import javafx.stage.Modality;
import javafx.stage.Stage;
import org.example.network.controller.MessageAlert;
import org.example.network.controller.RegisterController;
import org.example.network.domain.Utilizator;
import org.example.network.service.UtilizatorService;

import java.sql.SQLException;

public class LoginController {

    private UtilizatorService utilizatorService;
    private Stage stage;
    private Main main;

    @FXML
    private TextField textUsername;
    @FXML
    private TextField textPassword;

    public void setService(UtilizatorService utilizatorService, Stage stage) {
        this.utilizatorService = utilizatorService;
        this.stage = stage;
    }

    public void handleLogin() throws SQLException {
        if (textUsername.getText().isEmpty()) {
            MessageAlert.showErrorMessage(null, "Introdu un username");
        } else if (textPassword.getText().isEmpty()) {
            MessageAlert.showErrorMessage(null, "Introdu parola");
        } else {
            if (utilizatorService.verifyLogin(textUsername.getText(), textPassword.getText())) {
                try {
                    Utilizator user = utilizatorService.findUser(textUsername.getText());
                    main.openUserStage(user);
                    //stage.close();
                } catch (Exception e) {
                    e.printStackTrace();
                    MessageAlert.showErrorMessage(null, "Eroare: " + e.getMessage());
                }
            } else {
                MessageAlert.showErrorMessage(null, "Datele de logare sunt incorecte");
            }
        }
    }


    public void handleNewAcc() {
        showCreateAccDialog();
    }

    private void showCreateAccDialog() {
        try {
            FXMLLoader loader1 = new FXMLLoader();
            loader1.setLocation(getClass().getResource("register-view.fxml"));

            AnchorPane root1 = loader1.load();

            Stage dialogStage = new Stage();
            dialogStage.setTitle("Create an Account");
            dialogStage.initModality(Modality.WINDOW_MODAL);
            dialogStage.setResizable(true);
            Scene scene = new Scene(root1, 600, 300);
            dialogStage.setScene(scene);

            RegisterController registerController = loader1.getController();
            registerController.setService(utilizatorService, dialogStage);

            dialogStage.show();

        } catch (Exception e) {
            MessageAlert.showErrorMessage(null, "Eroare: " + e.getMessage());
        }
    }

    public void setMain(Main main) {
        this.main = main;
    }
}
