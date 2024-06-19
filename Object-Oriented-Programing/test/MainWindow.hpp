//
// Created by Alex Balta on 16.06.2024.
//
#pragma once

#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFormLayout>
#include <QLineEdit>
#include <QTableView>

#include "Model.hpp"
#include "Observer.hpp"

class MainWindow : public QMainWindow, public Observer {
  Q_OBJECT
  private:
    Service &service;
    Model *model;
    QTableView *tableView;

    QFormLayout *layoutForm;

    QLineEdit *inputId;
    QLineEdit *inputDescription;
    QLineEdit *inputProgrammer1;
    QLineEdit *inputProgrammer2;
    QLineEdit *inputProgrammer3;
    QLineEdit *inputProgrammer4;
    QLineEdit *inputStatus;

    QPushButton *btnAdd;
    QLineEdit *inputName;

    QWidget *centralWidget;
    QVBoxLayout *mainLayout;

    // creates the layout
    void initLayout();

    // creates the connections
    void initSignals();

  public:
    explicit MainWindow(Service &service, QWidget *parent = nullptr)
        : QMainWindow(parent), service(service) {
        service.addListener(this);
        initLayout();
        initSignals();
    }

    void update() override {
        model->refreshModel();
    }

    ~MainWindow() override {
        service.deleteListener(this);
    }
};
