module ubb.map.practicajutor {
    requires javafx.controls;
    requires javafx.fxml;
    requires java.sql;

    opens ubb.map.practicajutor to javafx.fxml;
    exports ubb.map.practicajutor;

    opens ubb.map.practicajutor.controller to javafx.fxml;
    exports ubb.map.practicajutor.controller;

    exports ubb.map.practicajutor.service;
    exports ubb.map.practicajutor.domain;
}