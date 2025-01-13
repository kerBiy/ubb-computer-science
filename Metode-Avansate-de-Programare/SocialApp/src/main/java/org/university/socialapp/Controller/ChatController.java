package org.university.socialapp.Controller;

import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Hyperlink;
import org.university.socialapp.Domain.User;
import org.university.socialapp.Domain.Conversation;
import org.university.socialapp.GUI;
import org.university.socialapp.Service.Service;
import org.university.socialapp.Utils.Observer;

import javafx.application.Platform;
import javafx.fxml.FXML;
import javafx.geometry.Pos;
import javafx.scene.control.Label;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.TextArea;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
import javafx.util.Pair;

import java.util.Optional;

public class ChatController extends GenericController implements Observer {

    Pair<User, User> users;
    Conversation conversation;

    @FXML
    ScrollPane scrollPane;

    @FXML
    TextArea messageTextArea;

    @FXML
    private Hyperlink userNameLink;

    VBox vbox = new VBox();

    @FXML
    public void initialize() {
        vbox.setSpacing(2);
        vbox.setMaxWidth(Double.MAX_VALUE);
        scrollPane.setContent(vbox);

        Platform.runLater(() -> {
            Stage stage = (Stage) scrollPane.getScene().getWindow();
            stage.setOnCloseRequest(event -> service.removeObserver(this));
        });
    }

    @Override
    public void update() {
        showMessages();
    }

    @Override
    public void setService(Service service) {
        super.setService(service);
        service.addObserver(this);
        Platform.runLater(this::showMessages);
    }

    @Override
    public void setSomething(Optional<Object> parameter) {
        users = (Pair<User, User>) parameter.get();

        userNameLink.setText(users.getValue().getName());
        userNameLink.setOnAction(event -> GUI.showProfileView(users));
    }

    public void showMessages() {
        vbox.getChildren().clear();
        conversation = service.getOrCreateConversation(users.getKey().getName(), users.getValue().getName());
        conversation.getMessages().forEach(message ->
        {
            boolean isSender = message.getSender().equals(service.getUser(users.getKey().getName()).getId());
            HBox bubble = createBubble(message.getText(), isSender);
            vbox.getChildren().add(bubble);
        });
        scrollPane.setContent(vbox);
    }

    public void handleSend() {
        if (!messageTextArea.getText().isEmpty()) {
            service.sendMessage(conversation.getId(), users.getKey().getName(), messageTextArea.getText());
            messageTextArea.clear();
        }
    }

    private HBox createBubble(String messageContent, boolean isSender) {
        Label label = new Label(messageContent);
        label.setWrapText(true); // Ensure text wraps within the bubble
        label.getStyleClass().add(isSender ? "chat-bubble-sender" : "chat-bubble-receiver");
        label.setMaxWidth(scrollPane.getScene().getWindow().getWidth() / 2 - 20);

        HBox hbox = new HBox();
        hbox.getStyleClass().add("chat-bubble-container");

        // Align the bubble based on sender/receiver
        if (isSender) {
            hbox.setAlignment(Pos.CENTER_RIGHT);
        } else {
            hbox.setAlignment(Pos.CENTER_LEFT);
        }

        hbox.getChildren().add(label);
        return hbox;
    }
}
