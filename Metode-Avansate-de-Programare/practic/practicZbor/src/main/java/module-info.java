module ubb.map.practiczbor {
    requires javafx.controls;
    requires javafx.fxml;
    requires java.sql;


    opens ubb.map.practiczbor to javafx.fxml;
    exports ubb.map.practiczbor;
    opens ubb.map.practiczbor.controller to javafx.fxml;
    exports ubb.map.practiczbor.controller;
    exports ubb.map.practiczbor.service;
    exports ubb.map.practiczbor.domain;
}