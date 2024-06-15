//
// Created by Alex Balta on 20.05.2024.
//

#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFormLayout>
#include <QLineEdit>
#include <QMainWindow>
#include <QTableView>

#include "StatusWindow.hpp"

class GUI : public QMainWindow {
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
    QPushButton *btnRefresh;

    QLineEdit *inputName;

    QWidget *centralWidget;
    QVBoxLayout *mainLayout;

    StatusWindow *openWindow;
    StatusWindow *inProgressWindow;
    StatusWindow *closedWindow;

    void initLayout();
    void initSignals();
    void initStatusWindows();

  public:
    explicit GUI(Service &service) : service(service) {
        initLayout();
        initSignals();
        initStatusWindows();
    }
};
