package ro.ubbcluj.map.socialnetwork;

import javafx.beans.property.SimpleStringProperty;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.stage.Stage;
import ro.ubbcluj.map.socialnetwork.controller.MessageAlert;
import ro.ubbcluj.map.socialnetwork.domain.CererePrietenie;
import ro.ubbcluj.map.socialnetwork.domain.Tuple;
import ro.ubbcluj.map.socialnetwork.domain.Utilizator;
import ro.ubbcluj.map.socialnetwork.observer.Observer;
import ro.ubbcluj.map.socialnetwork.repository.paging.Page;
import ro.ubbcluj.map.socialnetwork.repository.paging.Pageable;
import ro.ubbcluj.map.socialnetwork.service.CerereService;
import ro.ubbcluj.map.socialnetwork.service.PrietenieService;
import ro.ubbcluj.map.socialnetwork.service.UtilizatorService;

import java.sql.SQLException;
import java.util.stream.Collectors;
import java.util.stream.StreamSupport;

public class RequestFriendController implements Observer {

    private int pageSizeUser = 2;
    private int currentPageUser = 0;
    private int totalNrOfElemsUser = 0;

    @FXML
    Button prevButtonUser;
    @FXML
    Button nextButtonUser;
    @FXML
    TextField lblPgUser;



    private CerereService cerereService;
    private UtilizatorService userService;
    private ObservableList<Utilizator> observableList = FXCollections.observableArrayList();
    private Utilizator utilizator;
    private Stage stage;

    @FXML
    TableView<Utilizator> tableViewUser;
    @FXML
    TableColumn<Utilizator, String> tableColumnPrenume;
    @FXML
    TableColumn<Utilizator, String> tableColumnUsername;
    @FXML
    TableColumn<Utilizator, String> tableColumnNume;

    @FXML
    public void handleNextUser(ActionEvent ev) {
        currentPageUser++;
        initModel();
    }

    @FXML
    public void handlePrevUser() {
        currentPageUser--;
        initModel();
    }

    @FXML
    public void initialize() {
        tableColumnUsername.setCellValueFactory(new PropertyValueFactory<>("username"));
        tableColumnNume.setCellValueFactory(new PropertyValueFactory<>("firstName"));
        tableColumnPrenume.setCellValueFactory(new PropertyValueFactory<>("lastName"));

        tableViewUser.setItems(observableList);
        lblPgUser.textProperty().addListener(o -> updatePageUser());
    }


    public void setRequestService(UtilizatorService userService, CerereService cerereService, Stage stage, Utilizator utilizator) {
        this.userService = userService;
        this.cerereService = cerereService;
        this.stage = stage;
        this.utilizator = utilizator;
        cerereService.registerObserver(this);
        initModel();
    }

    private void initModel() {

        Page<Utilizator> pageUsers = userService.findAllOnPage(new Pageable(currentPageUser, pageSizeUser));

        int maxPageUser = (int) Math.ceil((double) pageUsers.getTotalNrOfElems() / pageSizeUser) - 1;


        if (currentPageUser > maxPageUser) {
            currentPageUser = maxPageUser;

            pageUsers = userService.findAllOnPage(new Pageable(currentPageUser, pageSizeUser));
        }

        observableList.setAll(StreamSupport.stream(pageUsers.getElementsOnPage().spliterator(), false).collect(Collectors.toList()));
        totalNrOfElemsUser = pageUsers.getTotalNrOfElems();
        prevButtonUser.setDisable(currentPageUser == 0);
        nextButtonUser.setDisable((currentPageUser + 1) * pageSizeUser >= totalNrOfElemsUser);

    }


    public void handleAdd() {
        Utilizator user = tableViewUser.getSelectionModel().getSelectedItem();
        if (user != null) {
            CererePrietenie cererePrietenie = new CererePrietenie();
            cererePrietenie.setId(new Tuple<>(utilizator.getId(), user.getId()));
            cererePrietenie.setStatus("PENDING");
            try {
                cerereService.addCerere(cererePrietenie);
                MessageAlert.showMessage(stage, Alert.AlertType.INFORMATION, "Cerere prietenie", "Cererea a fost trimisă cu succes.");
                stage.close();
            } catch (Exception e) {
                MessageAlert.showErrorMessage(null, "Eroare: " + e.getMessage());
            }
        } else {
            MessageAlert.showErrorMessage(null, "Niciun utilizator selectat.");
        }
    }

    private void updatePageUser() {
        if (lblPgUser.getText().isEmpty() || Integer.parseInt(lblPgUser.getText()) == 0) {
            initModel();
        } else {
            this.pageSizeUser = Integer.parseInt(lblPgUser.getText());
            this.currentPageUser = 0;
            initModel();
        }
    }

    @Override
    public void update() throws SQLException {
        initModel();
    }
}
