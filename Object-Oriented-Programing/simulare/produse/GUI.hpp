//
// Created by Alex Balta on 19.05.2024.
//

#pragma once

#include <QMainWindow>
#include <QVBoxLayout>
#include <QTableView>
#include <QPushButton>
#include <QLineEdit>
#include <QHeaderView>
#include <QLabel>
#include <QSlider>
#include <QMessageBox>
#include <map>
#include <QScreen>
#include "Model.hpp"

class GUI : public QMainWindow {
  Q_OBJECT
  private:
    Service &service;
    Model *model;

    QTableView *tableView;

    QLineEdit *inputId;
    QLineEdit *inputName;
    QLineEdit *inputType;
    QLineEdit *inputPrice;

    QPushButton *btnAdd;
    QSlider *sliderPrice;

    QWidget *centralWidget;
    QVBoxLayout *layoutMain;

    std::map<QString, QWidget *> typeWindows;

    void initLayout();
    void initSignals();
    void openTypeWindows();
    void updateTypeWindows();

  public:
    explicit GUI(Service &service, QWidget *parent = nullptr)
        : QMainWindow(parent), service(service) {
        initLayout();
        initSignals();
        openTypeWindows();
    }

  public slots:
    void handleNewProduct();
    void closeTypeWindows();
};
