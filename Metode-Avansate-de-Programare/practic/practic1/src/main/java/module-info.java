module ro.map.practic1 {
    requires javafx.controls;
    requires javafx.fxml;
    requires java.desktop;
    requires java.sql;
    requires jdk.jfr;


    opens ro.map.practic1 to javafx.fxml;
    exports ro.map.practic1.controller;
    exports ro.map.practic1.service;
    exports ro.map.practic1.domain;
    exports ro.map.practic1;

    opens ro.map.practic1.controller to javafx.fxml;
}