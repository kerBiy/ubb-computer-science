module org.example.sem8 {
    requires javafx.controls;
    requires javafx.fxml;


    opens org.example.sem8 to javafx.fxml;
    exports org.example.sem8;
    exports org.example.sem8.Controller;
    opens org.example.sem8.Controller to javafx.fxml;
}