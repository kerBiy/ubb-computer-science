package ubb.map.practic2023v1;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;
import ubb.map.practic2023v1.controller.GenericController;
import ubb.map.practic2023v1.domain.Hotel;
import ubb.map.practic2023v1.service.Service;

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
        mainView();
        stage.show();
    }

    public static void mainView() {
        stage.setScene(createScene("main-view.fxml", Optional.empty()));
        stage.setTitle("Main Window");
        stage.show();
    }

    public static void showOffersView(Hotel hotel) {
        Stage stage = new Stage();
        stage.setScene(createScene("offers-view.fxml", Optional.of(hotel)));
        stage.setTitle("Offers for " + hotel.getHotelName());
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