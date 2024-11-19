package org.example.sem8.Controller;

import javafx.beans.property.SimpleDoubleProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.ComboBox;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;
import javafx.scene.control.cell.PropertyValueFactory;
import org.example.sem8.Domain.Nota;
import org.example.sem8.Domain.Tema;
import org.example.sem8.Service.ServiceManager;

public class MainController {

    @FXML
    private TableView<Nota> tableView;
    @FXML
    private TableColumn<Nota, String> colStudent;
    @FXML
    private TableColumn<Nota, String> colTema;
    @FXML
    private TableColumn<Nota, Double> colNota;
    @FXML
    private TextField txtStudentName;
    @FXML
    private TextField txtMinGrade;
    @FXML
    private TextField txtTema;
    @FXML
    private ComboBox<String> comboTema;

    private ServiceManager serviceManager;
    private ObservableList<Nota> grades;

    public void initialize() {
        serviceManager = new ServiceManager();
        grades = FXCollections.observableArrayList(serviceManager.findAllGrades());

        // Set up table columns
        colStudent.setCellValueFactory(data -> new SimpleStringProperty(data.getValue().getStudent().getName()));
        colTema.setCellValueFactory(data -> new SimpleStringProperty(data.getValue().getTema().getId()));
        colNota.setCellValueFactory(data -> new SimpleDoubleProperty(data.getValue().getValue()).asObject());

        // Load data into the table
        tableView.setItems(grades);

        // Load homework into ComboBox
        comboTema.setItems(FXCollections.observableArrayList(
                serviceManager.findAllHomeWorks().stream()
                        .map(Tema::getId)
                        .toList()
        ));
    }

    @FXML
    private void onFilter() {
        String studentName = txtStudentName.getText().trim().toLowerCase();
        String minGradeStr = txtMinGrade.getText().trim();
        String tema = txtTema.getText().trim().toLowerCase();
        String selectedTema = comboTema.getValue();

        ObservableList<Nota> filtered = grades.filtered(grade -> {
            boolean matchesName = studentName.isEmpty() || grade.getStudent().getName().toLowerCase().contains(studentName);
            boolean matchesGrade = true;
            if (!minGradeStr.isEmpty()) {
                try {
                    double minGrade = Double.parseDouble(minGradeStr);
                    matchesGrade = grade.getValue() >= minGrade;
                } catch (NumberFormatException e) {
                    return false; // Invalid number, exclude
                }
            }
            boolean matchesTema = tema.isEmpty() || grade.getTema().getId().toLowerCase().contains(tema);
            boolean matchesSelectedTema = selectedTema == null || grade.getTema().getId().equals(selectedTema);
            return matchesName && matchesGrade && matchesTema && matchesSelectedTema;
        });

        tableView.setItems(filtered);
    }
}