package ubb.map.practiczbor;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;
import ubb.map.practiczbor.controller.GenericController;
import ubb.map.practiczbor.domain.Client;
import ubb.map.practiczbor.service.Service;

import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
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
        logInView();
        stage.show();
    }

    public static void logInView() {
        stage.setScene(createScene("login-view.fxml", Optional.empty()));
        stage.setTitle("LogIn");
        stage.show();
    }

    public static void flightView(Client client) {
        Stage stage = new Stage();
        stage.setScene(createScene("flight-view.fxml", Optional.of(client)));
        stage.setTitle(client.getUsername());
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