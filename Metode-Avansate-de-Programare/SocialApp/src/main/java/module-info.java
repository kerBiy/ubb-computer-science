module org.university.socialapp {
    requires javafx.controls;
    requires javafx.fxml;
    requires java.sql;
    requires java.desktop;


    opens org.university.socialapp to javafx.fxml;

    exports org.university.socialapp;
    exports org.university.socialapp.Repository;
    exports org.university.socialapp.Service;
    exports org.university.socialapp.Controller;

    opens org.university.socialapp.Controller to javafx.fxml;
}