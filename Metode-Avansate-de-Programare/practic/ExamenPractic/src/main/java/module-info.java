module ubb.map.examenpractic {
    requires javafx.controls;
    requires javafx.fxml;
    requires java.sql;


    opens ubb.map.examenpractic to javafx.fxml;
    exports ubb.map.examenpractic;

    opens ubb.map.examenpractic.controller to javafx.fxml;
    exports ubb.map.examenpractic.controller;
    exports ubb.map.examenpractic.service;
    exports ubb.map.examenpractic.domain;
}