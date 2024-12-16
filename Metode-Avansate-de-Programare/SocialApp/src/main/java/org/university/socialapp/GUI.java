package org.university.socialapp;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.util.Pair;
import org.university.socialapp.Controller.GenericController;
import org.university.socialapp.Domain.User;
import org.university.socialapp.Service.Service;

import java.io.IOException;
import java.net.URL;
import java.util.Optional;

public class GUI extends Application {
    private static Service service;
    private static Stage stage;

    public static void setService(Service service) {
        GUI.service = service;
    }

    @Override
    public void start(Stage primaryStage) {
        GUI.stage = primaryStage;
        loginView();
        stage.setResizable(false);
        stage.show();
    }

    public static void loginView() {
        stage.setScene(createScene("login-view.fxml", "css/login.css", Optional.empty()));
        stage.setTitle("SocialApp - Login View");
        stage.show();
    }

    public static void signUpView() {
        stage.setScene(createScene("signUp-view.fxml", "css/signUp.css", Optional.empty()));
        stage.setTitle("SocialApp - Sign Up");
        stage.show();
    }

    public static void loggedUserView(String username) {
        stage.setScene(createScene("user-view.fxml", "css/user.css", Optional.of(service.getUser(username))));
        stage.setTitle("SocialApp - " + username);
        stage.show();
    }

    public static void chatView(Pair<User, User> users) {
        Stage stage = new Stage();
        stage.setScene(createScene("chat-view.fxml", "css/chat.css", Optional.of(users)));
        stage.setTitle("SocialApp - Chat");
        stage.show();
    }

    public static void friendRequestView(String username) {
        Stage stage = new Stage();
        stage.setScene(createScene("friendRequest-view.fxml", "css/friendRequest.css", Optional.of(username)));
        stage.setTitle("Send a friend Request");
        stage.show();
    }

    public static void friendRequestsView(User user) {
        Stage stage = new Stage();
        stage.setScene(createScene("friendRequests-view.fxml", "css/friendRequests.css", Optional.of(user)));
        stage.setTitle("SocialApp - Friend Requests");
        stage.show();
    }

    private static Scene createScene(String fxml, String css, Optional<Object> parameter) {
        FXMLLoader fxmlLoader = new FXMLLoader();
        fxmlLoader.setLocation(GUI.class.getResource(fxml));

        try {
            Scene scene = new Scene(fxmlLoader.load());

            GenericController controller = fxmlLoader.getController();

            controller.setSomething(parameter);
            controller.setService(service);

            if (css != null && !css.isEmpty()) {
                URL cssUrl = GUI.class.getResource(css);
                if (cssUrl != null) {
                    scene.getStylesheets().add(cssUrl.toExternalForm());
                } else {
                    System.err.println("CSS file not found: " + css);
                }
            }

            return scene;
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static void launch() {
        Application.launch();
    }
}