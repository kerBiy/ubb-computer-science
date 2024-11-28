module org.university.demo {
    requires javafx.controls;
    requires javafx.fxml;


    opens org.university.demo to javafx.fxml;
    exports org.university.demo;
}