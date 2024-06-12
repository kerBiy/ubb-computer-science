//
// Created by Alex Balta on 12.06.2024.
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
    QPushButton *btnSearch;

    QLineEdit *inputName;

    QWidget *centralWidget;
    QVBoxLayout *mainLayout;

    void initLayout();
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
