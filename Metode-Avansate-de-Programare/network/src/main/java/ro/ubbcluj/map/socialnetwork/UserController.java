package ro.ubbcluj.map.socialnetwork;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.layout.AnchorPane;
import javafx.stage.Modality;
import javafx.stage.Stage;
import ro.ubbcluj.map.socialnetwork.controller.MessageAlert;
import ro.ubbcluj.map.socialnetwork.domain.Tuple;
import ro.ubbcluj.map.socialnetwork.domain.Utilizator;
import ro.ubbcluj.map.socialnetwork.observer.Observer;
import ro.ubbcluj.map.socialnetwork.repository.paging.Page;
import ro.ubbcluj.map.socialnetwork.repository.paging.Pageable;
import ro.ubbcluj.map.socialnetwork.service.CerereService;
import ro.ubbcluj.map.socialnetwork.service.ConversationService;
import ro.ubbcluj.map.socialnetwork.service.PrietenieService;
import ro.ubbcluj.map.socialnetwork.service.UtilizatorService;

import java.sql.SQLException;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.StreamSupport;


public class UserController implements Observer {

    @FXML
    private TableView<Utilizator> tableViewFriends;
    @FXML
    private TableView<Utilizator> tableViewRequests;
    UtilizatorService userService;
    CerereService cerereService;
    PrietenieService prietenieService;
    ConversationService conversationService;
    Utilizator utilizator;
    private final ObservableList<Utilizator> modelFriends = FXCollections.observableArrayList();
    private final ObservableList<Utilizator> modelRequests = FXCollections.observableArrayList();

    private Stage stage;
    @FXML
    private TableColumn<Utilizator, String> UsernameRequestColumn;
    @FXML
    private TableColumn<Utilizator, String> PrenumeRequestColumn;
    @FXML
    private TableColumn<Utilizator, String> NumeRequestColumn;
    @FXML
    private TableColumn<Utilizator, String> PrenumeFriendColumn;
    @FXML
    private TableColumn<Utilizator, String> NumeFriendColumn;

    @FXML
    Button prevBttnFriends;
    @FXML
    Button prevBttnCereri;
    @FXML
    Button nextBttnFriends;
    @FXML
    Button nextBttnCereri;
    @FXML
    TextField lblPageFriends;
    @FXML
    TextField lblPageCereri;

    private int pageSizeFriends = 2;
    private int pageSizeCereri= 2;

    private int currentPageFriends = 0;
    private int currentPageCereri = 0;
    private int totalNrOfElemsFriends = 0;
    private int totalNrOfElemsRequests = 0;


    public void setService(Utilizator utilizator, UtilizatorService utilizatorService, CerereService cerereService, PrietenieService prietenieService, ConversationService conversationService, Stage stage) {
        this.utilizator = utilizator;
        this.cerereService = cerereService;
        this.userService = utilizatorService;
        this.prietenieService = prietenieService;
        this.conversationService = conversationService;
        this.stage = stage;

        prietenieService.registerObserver(this);
        cerereService.registerObserver(this);

        initializeFriends();
        initializeRequests();

        initModelFriends();
        initModelRequests();

    }

    public void handleDelete() {
        try {
            userService.stergeUtilizator(utilizator.getUsername());
            MessageAlert.showMessage(null, Alert.AlertType.INFORMATION, "Sterge utilizator", "Utilizator sters cu succes!");
            stage.close();
        } catch (Exception e){
            MessageAlert.showErrorMessage(null, "Eroare: " + e.getMessage());
        }
    }

    public void handleUpdate() {
        showUserEditDialog();
    }

    private void showUserEditDialog() {
        try {
            FXMLLoader loader = new FXMLLoader();
            loader.setLocation(getClass().getResource("edit-user-view.fxml"));

            AnchorPane root1 = loader.load();

            Stage dialogStage1 = new Stage();
            dialogStage1.setTitle("Editeaza utilizatorul");
            dialogStage1.initModality(Modality.WINDOW_MODAL);

            dialogStage1.setResizable(true);
            Scene scene = new Scene(root1, 600, 300);
            dialogStage1.setScene(scene);

            EditUserController editUserController = loader.getController();
            editUserController.setUtilizatorService(userService, dialogStage1, utilizator);

            dialogStage1.show();

        } catch (Exception e){
            MessageAlert.showErrorMessage(null, "Eroare: " + e.getMessage());
        }
    }

    public void handleAcceptRequest() {
        Utilizator user = tableViewRequests.getSelectionModel().getSelectedItem();
        if (user != null) {
            try {
                cerereService.respondRequest(new Tuple<>(Long.valueOf(user.getId().toString()), utilizator.getId()), "APPROVED");
                MessageAlert.showMessage(null, Alert.AlertType.INFORMATION, "Accepta cererea", "Cererea a fost acceptata!");
            } catch (SQLException e) {
                MessageAlert.showErrorMessage(null, e.getMessage());
            }
        } else {
            MessageAlert.showErrorMessage(null, "Niciun utilizator selectat.");
        }
    }


    public void handleAddFriend() {
        showRequestFriendshipDialog();
    }

    private void showRequestFriendshipDialog() {
        try {
            FXMLLoader loader = new FXMLLoader();
            loader.setLocation(getClass().getResource("/view/request-friend.fxml"));

            AnchorPane root = loader.load();

            Stage dialogStage = new Stage();
            dialogStage.setTitle("Adauga prieten");
            dialogStage.initModality(Modality.WINDOW_MODAL);
            dialogStage.setResizable(true);
            Scene scene = new Scene(root, 600, 300);
            dialogStage.setScene(scene);

            RequestFriendController requestFriendController = loader.getController();
            requestFriendController.setRequestService(userService, cerereService, dialogStage, utilizator);

            dialogStage.show();
        } catch (Exception e) {
            e.printStackTrace();
            MessageAlert.showErrorMessage(null, "Eroare: " + e.getMessage());
        }
    }



    public void handleChat() throws Exception {
        Utilizator user = tableViewFriends.getSelectionModel().getSelectedItem();
        if(user!=null)
            showChatDialog(user);
        else{
            MessageAlert.showErrorMessage(null, "Selecteaza un user.");
        }
    }

    private void showChatDialog(Utilizator user) throws Exception {
        try {
            FXMLLoader loader1 = new FXMLLoader();
            loader1.setLocation(getClass().getResource("conversation-view.fxml"));

            AnchorPane root1 = loader1.load();

            Stage dialogStage = new Stage();
            dialogStage.setTitle("Chat");
            dialogStage.initModality(Modality.WINDOW_MODAL);
            dialogStage.setResizable(true);
            Scene scene = new Scene(root1,600,300);
            dialogStage.setScene(scene);

            ConversationController conversationController = loader1.getController();
            conversationController.setService(conversationService, utilizator, user);

            dialogStage.show();

        } catch (Exception e){
            throw new Exception(e);
//            MessageAlert.showErrorMessage(null, "Eroare: " + e.getMessage());
        }
    }

    public void handleRejectRequest() {
        Utilizator user = tableViewRequests.getSelectionModel().getSelectedItem();
        if (user != null) {
            try {
                cerereService.respondRequest(new Tuple<>(Long.valueOf(user.getId().toString()), utilizator.getId()), "");
                MessageAlert.showMessage(null, Alert.AlertType.INFORMATION, "Refuza cererea", "Cererea a fost refuzata!");
            } catch (SQLException e) {
                MessageAlert.showErrorMessage(null, e.getMessage());
            } catch(Exception e){
                MessageAlert.showErrorMessage(null, "Eroare la refuzarea cererii: " + e.getMessage());
            }
        } else {
            MessageAlert.showErrorMessage(null, "Niciun utilizator selectat.");
        }
    }

    public void handleChannel() throws Exception {
        List<Utilizator> selectedUsers = tableViewFriends.getSelectionModel().getSelectedItems();
        if(selectedUsers.size()<2){
            MessageAlert.showErrorMessage(null, "Selecteaza minim 2 useri.");
        } else {
            showChannelDialog(selectedUsers);
        }

    }

    private void showChannelDialog(List<Utilizator> selectedUsers) throws Exception {
        try {
            FXMLLoader loader1 = new FXMLLoader();
            loader1.setLocation(getClass().getResource("channel-view.fxml"));

            AnchorPane root1 = loader1.load();

            Stage dialogStage = new Stage();
            dialogStage.setTitle("Difuzare mesaj");
            dialogStage.initModality(Modality.WINDOW_MODAL);
            dialogStage.setResizable(true);
            Scene scene = new Scene(root1,600,300);
            dialogStage.setScene(scene);

            ChannelController channelController = loader1.getController();
            channelController.setService(conversationService, dialogStage, utilizator, selectedUsers);

            dialogStage.show();

        } catch (Exception e){
            throw new Exception(e);
        }
    }

    @FXML
    public void initializeFriends() {
        tableViewFriends.getSelectionModel().setSelectionMode(SelectionMode.MULTIPLE);
        PrenumeFriendColumn.setCellValueFactory(new PropertyValueFactory<>("firstName"));
        NumeFriendColumn.setCellValueFactory(new PropertyValueFactory<>("lastName"));
        tableViewFriends.setItems(modelFriends);
        lblPageFriends.textProperty().addListener(o -> updatePageFriends());
    }

    @FXML
    public void initializeRequests() {
        UsernameRequestColumn.setCellValueFactory(new PropertyValueFactory<>("username"));
        PrenumeRequestColumn.setCellValueFactory(new PropertyValueFactory<>("firstName"));
        NumeRequestColumn.setCellValueFactory(new PropertyValueFactory<>("lastName"));
        tableViewRequests.setItems(modelRequests);
        lblPageCereri.textProperty().addListener(o -> updatePageCereri());
    }


    private void initModelFriends() {
        Page<Utilizator> pageUsers = prietenieService.findAllOnPage(new Pageable(currentPageFriends, pageSizeFriends), utilizator.getId());

        int maxPageUser = (int) Math.ceil((double) pageUsers.getTotalNrOfElems() / pageSizeFriends) - 1;
        if(maxPageUser > 0) {
            if (currentPageFriends > maxPageUser) {
                currentPageFriends = maxPageUser;

                pageUsers = prietenieService.findAllOnPage(new Pageable(currentPageFriends, pageSizeFriends), utilizator.getId());
            }
        }

        modelFriends.setAll(StreamSupport.stream(pageUsers.getElementsOnPage().spliterator(), false).collect(Collectors.toList()));
        totalNrOfElemsFriends = pageUsers.getTotalNrOfElems();
        prevBttnFriends.setDisable(currentPageFriends == 0);
        nextBttnFriends.setDisable((currentPageFriends + 1) * pageSizeFriends >= totalNrOfElemsFriends);

    }


    private void initModelRequests() {
        Page<Utilizator> pageUsers = cerereService.findAllOnPage(new Pageable(currentPageCereri, pageSizeCereri), utilizator.getId());

        int maxPageUser = (int) Math.ceil((double) pageUsers.getTotalNrOfElems() / pageSizeCereri) - 1;
        if(maxPageUser > 0) {

            if (currentPageCereri > maxPageUser) {
                currentPageCereri = maxPageUser;

                pageUsers = cerereService.findAllOnPage(new Pageable(currentPageCereri, pageSizeCereri), utilizator.getId());
            }
        }
        modelRequests.setAll(StreamSupport.stream(pageUsers.getElementsOnPage().spliterator(), false).collect(Collectors.toList()));
        totalNrOfElemsRequests = pageUsers.getTotalNrOfElems();
        prevBttnCereri.setDisable(currentPageCereri == 0);
        nextBttnCereri.setDisable((currentPageCereri + 1) * pageSizeCereri >= totalNrOfElemsRequests);
    }

    @Override
    public void update() throws SQLException {
        initModelRequests();
        initModelFriends();
    }

    private void updatePageFriends()  {
        if (lblPageFriends.getText().isEmpty() || Integer.parseInt(lblPageFriends.getText()) == 0) {
            initModelFriends();
        } else {
            this.pageSizeFriends = Integer.parseInt(lblPageFriends.getText());
            this.currentPageFriends = 0;
            initModelFriends();
        }
    }

    private void updatePageCereri() {

        if (lblPageCereri.getText().isEmpty() || Integer.parseInt(lblPageCereri.getText()) == 0) {
            initModelRequests();
        } else {
            this.pageSizeCereri = Integer.parseInt(lblPageCereri.getText());
            this.currentPageCereri = 0;
           initModelRequests();
        }
    }

    public void handlePrevFriend(ActionEvent ev) {
            this.currentPageFriends --;
            initModelFriends();

    }

    public void handleNextFriend(ActionEvent ev) {
        this.currentPageFriends++;
        initModelFriends();
    }

    public void handleNextCerere(ActionEvent ev) {
        this.currentPageCereri++;
        initModelRequests();
    }

    public void handlePrevCerere(ActionEvent ev) {
            this.currentPageCereri--;
            initModelRequests();
    }
}
