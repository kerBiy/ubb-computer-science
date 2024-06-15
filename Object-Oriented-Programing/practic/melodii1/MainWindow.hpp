//
// Created by Alex Balta on 17.05.2024.
//

#pragma once

#include <QMainWindow>
#include <QTableView>
#include <QPushButton>
#include <QLineEdit>
#include <QSlider>
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QHeaderView>
#include "Service.hpp"
#include "SongModel.hpp"

class MainWindow : public QMainWindow {
  Q_OBJECT
  private:
    Service &service;
    SongModel *model;

    QTableView *tableView;

    QLineEdit *titleEdit;
    QSlider *rankSlider;

    QPushButton *updateButton;
    QPushButton *deleteButton;
    QVBoxLayout *chartLayout;

    void setupUI();
    void setupConnections();
    void updateChart();

  public:
    explicit MainWindow(Service &service, QWidget *parent = nullptr);
};
