package ubb.map.practicajutor;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;

import ubb.map.practicajutor.controller.GenericController;
import ubb.map.practicajutor.domain.Persoana;
import ubb.map.practicajutor.service.Service;

import java.io.IOException;
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
        registerView();
        loginView();
        stage.show();
    }

    public static void loginView() {
        stage.setScene(createScene("login-view.fxml", Optional.empty()));
        stage.setTitle("LogIn");
        stage.show();
    }

    public static void registerView() {
        stage.setScene(createScene("register-view.fxml", Optional.empty()));
        stage.setTitle("Register");
        stage.show();
    }

    public static void mainView(Persoana persoana) {
        Stage stage = new Stage();
        stage.setScene(createScene("main-view.fxml", Optional.of(persoana)));
        stage.setTitle("Main Window for " + persoana.getUsername());
        stage.show();
    }

    private static Scene createScene(String fxml, Optional<Object> parameter) {
        FXMLLoader fxmlLoader = new FXMLLoader();
        fxmlLoader.setLocation(GUI.class.getResource(fxml));

        try {
            Scene scene = new Scene(fxmlLoader.load());

            GenericController controller = fxmlLoader.getController();

            controller.setService(service);
            controller.setSomething(parameter);

            return scene;
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static void launch() {
        Application.launch();
    }
}