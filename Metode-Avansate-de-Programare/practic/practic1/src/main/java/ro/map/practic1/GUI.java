package ro.map.practic1;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;
import ro.map.practic1.controller.GenericController;
import ro.map.practic1.service.Service;

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
        staffView();

        service.getTables().forEach(t -> tableView(t.getId()));

        stage.setResizable(false);
        stage.show();
    }

    public static void staffView() {
        stage.setScene(createScene("staff.fxml", Optional.empty()));
        stage.setTitle("Staff");
        stage.show();
    }

    public static void tableView(Integer Id) {
        Stage stage = new Stage();
        stage.setScene(createScene("table.fxml", Optional.of(Id)));
        stage.setTitle("Table " + Id);
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