package ubb.map.practicajutor.controller;

import javafx.beans.property.ReadOnlyStringWrapper;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.*;
import ubb.map.practicajutor.domain.Nevoie;
import ubb.map.practicajutor.domain.Persoana;
import ubb.map.practicajutor.service.Service;
import ubb.map.practicajutor.utils.Observer;

import java.time.LocalDate;
import java.util.List;
import java.util.Optional;

public class MainController extends GenericController implements Observer {
    @FXML
    private TabPane mainTabPane;

    @FXML
    private Tab helpTab;

    @FXML
    private TextField titleField;

    @FXML
    private TextField descriptionField;

    @FXML
    private DatePicker deadlinePicker;

    @FXML
    private Label feedbackLabel;

    @FXML
    private TableView<Nevoie> availableNeedsTable;

    @FXML
    private TableView<Nevoie> myGoodDeedsTable;

    @FXML
    private Button resolveNeedButton;

    private ObservableList<Nevoie> availableNeeds = FXCollections.observableArrayList();
    private ObservableList<Nevoie> myGoodDeeds = FXCollections.observableArrayList();

    private Persoana loggedUser;

    @Override
    public void setService(Service service) {
        super.setService(service);
        service.addObserver(this);
    }

    @Override
    public void update() {
        loadNeeds();
    }

    @Override
    public void setSomething(Optional<Object> parameter) {
        if (parameter.isPresent() && parameter.get() instanceof Persoana) {
            this.loggedUser = (Persoana) parameter.get();
            loadNeeds();
        }

        setupTables();
        resolveNeedButton.setOnAction(event -> handleResolveNeed());
    }

    private void setupTables() {
        TableColumn<Nevoie, String> titleColumn = new TableColumn<>("Titlu");
        titleColumn.setCellValueFactory(data -> new ReadOnlyStringWrapper(data.getValue().getTitlu()));

        TableColumn<Nevoie, String> descriptionColumn = new TableColumn<>("Descriere");
        descriptionColumn.setCellValueFactory(data -> new ReadOnlyStringWrapper(data.getValue().getDescriere()));

        availableNeedsTable.getColumns().addAll(titleColumn, descriptionColumn);
        availableNeedsTable.setItems(availableNeeds);

        TableColumn<Nevoie, String> myDeedsTitleColumn = new TableColumn<>("Titlu");
        myDeedsTitleColumn.setCellValueFactory(data -> new ReadOnlyStringWrapper(data.getValue().getTitlu()));

        myGoodDeedsTable.getColumns().addAll(myDeedsTitleColumn);
        myGoodDeedsTable.setItems(myGoodDeeds);
    }

    private void loadNeeds() {
        List<Nevoie> allNeeds = service.getAllNevoi();
        availableNeeds.setAll(allNeeds.stream()
                .filter(nevoie -> nevoie.getOmSalvator() == null && !nevoie.getOmInNevoie().equals(loggedUser.getId()))
                .toList());
        myGoodDeeds.setAll(allNeeds.stream()
                .filter(nevoie -> loggedUser.getId().equals(nevoie.getOmSalvator()))
                .toList());
    }

    private void handleResolveNeed() {
        Nevoie selectedNeed = availableNeedsTable.getSelectionModel().getSelectedItem();
        if (selectedNeed == null) {
            showAlert("Selectați o nevoie pentru a o rezolva.");
            return;
        }

        selectedNeed.setOmSalvator(loggedUser.getId());
        selectedNeed.setStatus("Erou găsit!");

        service.updateNevoie(selectedNeed);
        showAlert("Nevoia \"" + selectedNeed.getTitlu() + "\" a fost atribuită cu succes.");
    }

    @FXML
    public void handleAddNeed() {
        String title = titleField.getText();
        String description = descriptionField.getText();
        LocalDate deadline = deadlinePicker.getValue();

        if (title.isEmpty() || description.isEmpty() || deadline == null) {
            feedbackLabel.setText("Toate câmpurile trebuie completate!");
            feedbackLabel.setTextFill(javafx.scene.paint.Color.RED);
            return;
        }

        Nevoie newNeed = new Nevoie(null, title, description, deadline.atStartOfDay(), loggedUser.getId(), null, "Caut erou!");
        service.saveNevoie(newNeed);

        titleField.clear();
        descriptionField.clear();
        deadlinePicker.setValue(null);

        feedbackLabel.setText("Nevoia a fost adăugată cu succes!");
        feedbackLabel.setTextFill(javafx.scene.paint.Color.GREEN);
    }

    private void showAlert(String message) {
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setContentText(message);
        alert.showAndWait();
    }
}