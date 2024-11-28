package ro.ubbcluj.map.socialnetwork;

import javafx.beans.property.SimpleStringProperty;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.TextArea;
import javafx.scene.control.cell.PropertyValueFactory;
import ro.ubbcluj.map.socialnetwork.controller.MessageAlert;
import ro.ubbcluj.map.socialnetwork.domain.Conversation;
import ro.ubbcluj.map.socialnetwork.domain.Message;
import ro.ubbcluj.map.socialnetwork.domain.Utilizator;
import ro.ubbcluj.map.socialnetwork.observer.Observer;
import ro.ubbcluj.map.socialnetwork.service.ConversationService;

import java.sql.SQLException;
import java.util.Collection;

public class ConversationController implements Observer {

    @FXML
    private TextArea msgArea;
    @FXML
    TableView<Conversation> tableViewMessages;
    @FXML
    TableColumn<Conversation, String> fromColumn;
    @FXML
    TableColumn<Conversation, String> toColumn;
    @FXML
    TableColumn<Conversation, String> messagesColumn;
    @FXML
    TableColumn<Conversation, String> dateColumn;

    private ConversationService conversationService;
    private final ObservableList<Conversation> model = FXCollections.observableArrayList();
    private Utilizator fromUser;
    private Utilizator toUser;

    public ConversationController() {
    }

    public void setService(ConversationService conversationService, Utilizator fromUser, Utilizator toUser) {
        this.fromUser = fromUser;
        this.toUser = toUser;
        this.conversationService = conversationService;

        conversationService.registerObserver(this);
        initModel();
    }

    public void initialize() {
        fromColumn.setCellValueFactory(cellData -> new SimpleStringProperty(cellData.getValue().getSender().getFirstName()));
        toColumn.setCellValueFactory(cellData -> new SimpleStringProperty(cellData.getValue().getReceiver().getFirstName()));
        messagesColumn.setCellValueFactory(cellData -> new SimpleStringProperty(cellData.getValue().getMessage().getText()));
        dateColumn.setCellValueFactory(new PropertyValueFactory<>("date"));
        tableViewMessages.setItems(model);
    }

    private void initModel() {
        Collection<Conversation> all = conversationService.chat(fromUser.getId(), toUser.getId());
        model.setAll(all);
    }

    public void handleSend() {
        Conversation selectedMessage = tableViewMessages.getSelectionModel().getSelectedItem();
        String msgAreaText = msgArea.getText();
        try {
            Message message = new Message(msgAreaText);
            message.setId(conversationService.generateIdMessage());
            Conversation conversation = new Conversation(fromUser, toUser, message);
            if (selectedMessage != null) {
                conversation.setIdReply(selectedMessage.getId());
            }
            conversationService.addMessage(conversation);
            initModel();
            tableViewMessages.getSelectionModel().clearSelection();
            msgArea.clear();
        } catch (Exception e) {
//            MessageAlert.showErrorMessage(null, "Eroare: " + e.getMessage());
            e.printStackTrace();
        }
    }


    @Override
    public void update() throws SQLException {
        initModel();
    }


}
