module ubb.map.practic2023v1 {
    requires javafx.controls;
    requires javafx.fxml;
    requires java.sql;
    requires java.desktop;


    opens ubb.map.practic2023v1 to javafx.fxml;
    exports ubb.map.practic2023v1;

    opens ubb.map.practic2023v1.controller to javafx.fxml;
    exports ubb.map.practic2023v1.controller;
    exports ubb.map.practic2023v1.service;
    exports ubb.map.practic2023v1.domain;
}