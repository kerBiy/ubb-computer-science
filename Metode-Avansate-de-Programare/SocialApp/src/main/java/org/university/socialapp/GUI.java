package org.university.socialapp;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
import org.university.socialapp.Controller.LoginController;
import org.university.socialapp.Domain.User;
import org.university.socialapp.Repository.FriendshipRepository;
import org.university.socialapp.Repository.UserRepository;
import org.university.socialapp.Service.Service;
import org.university.socialapp.Domain.Validation.FriendshipValidator;
import org.university.socialapp.Domain.Validation.UserValidator;

import java.io.IOException;

public class GUI extends Application {
    private final String url = "jdbc:postgresql://localhost:5432/SocialApp";
    private final String user = "postgres";
    private final String password = "nush";

    UserValidator userValidator = new UserValidator();
    FriendshipValidator friendshipValidator = new FriendshipValidator();
    UserRepository userRepo = new UserRepository(userValidator, url, user, password);
    FriendshipRepository friendshipRepo = new FriendshipRepository(friendshipValidator, url, user, password);

    Service service = new Service(userRepo, friendshipRepo);

    public void loginStage(Stage primaryStage) throws Exception {
        FXMLLoader loginLoader = new FXMLLoader();
        loginLoader.setLocation(getClass().getResource("login-view.fxml"));

        VBox loginVBox = loginLoader.load();
        LoginController loginController = loginLoader.getController();
        loginController.setMain(this);

        Scene scene = new Scene(loginVBox);

        primaryStage.setTitle("SocialApp");
        primaryStage.setScene(scene);

        loginController.setService(service, primaryStage);

        primaryStage.show();
    }


    public void openUserStage(User user) {
        try {
            FXMLLoader userLoader = new FXMLLoader();
            userLoader.setLocation(getClass().getResource("user-view.fxml"));


            Stage userStage = new Stage();
            Scene userScene = new Scene(userLoader.load());


            userStage.setTitle("User dashboard");
            userStage.setScene(userScene);

//            UserController userController = userLoader.getController();
//            userController.setService(user, serv, cerereService, prietenieService, conversationService, userStage);

            userStage.show();
        } catch (IOException e) {
            e.printStackTrace();
            throw new RuntimeException(e);
        }
    }


    @Override
    public void start(Stage primaryStage) throws Exception {
        loginStage(primaryStage);
    }

    public static void main(String[] args) {
        launch();
    }
}