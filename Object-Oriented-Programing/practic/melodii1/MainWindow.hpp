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
#include "Model.hpp"

class MainWindow : public QMainWindow, public Observer {
  Q_OBJECT
  private:
    Service &service;
    Model *model;

    QTableView *tableView;

    QLineEdit *inputTitle;
    QSlider *sliderRank;

    QPushButton *updateButton;
    QPushButton *deleteButton;
    QVBoxLayout *chartLayout;

    QHBoxLayout *formLayout;

    QWidget *mainWidget;
    QVBoxLayout *mainLayout;

    void initLayout();
    void initSignals();
    void updateChart();

  public:
    explicit MainWindow(Service &service, QWidget *parent = nullptr);

    void update() override;

    ~MainWindow() override;
};
