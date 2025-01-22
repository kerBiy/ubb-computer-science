package ubb.map.examenpractic.controller;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import ubb.map.examenpractic.GUI;

import java.util.Optional;

public class NewClientController extends GenericController {

    @FXML
    private void handleOpenNewClientWindow(ActionEvent event) {
        GUI.clientView();
    }

    @Override
    public void setSomething(Optional<Object> parameter) {
    }
}