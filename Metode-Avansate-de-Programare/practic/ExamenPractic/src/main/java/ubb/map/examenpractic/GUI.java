package ubb.map.examenpractic;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;
import ubb.map.examenpractic.controller.GenericController;
import ubb.map.examenpractic.service.Service;

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
        newClientView();
        stage.show();
    }

    public static void newClientView() {
        stage.setScene(createScene("new-client-view.fxml", Optional.empty()));
        stage.setTitle("New Client Window");
        stage.show();
    }

    public static void clientView() {
        Stage stage = new Stage();
        stage.setScene(createScene("client-view.fxml", Optional.empty()));
        stage.setTitle("client Window");
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