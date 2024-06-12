//
// Created by Alex Balta on 12.06.2024.
//

#pragma once

#include <QMainWindow>
#include <QTableView>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include "Model.hpp"

class MainWindow : public QMainWindow {
  Q_OBJECT
  private:
    Service &serv;
    Model *model;
    QTableView *tableView;

    QHBoxLayout *formLayout;

    QLineEdit *inputId;
    QLineEdit *inputName;
    QLineEdit *inputType;
    QLineEdit *inputPrice;

    QSlider *inputSliderPrice;
    QPushButton *addBtn;

    QVBoxLayout *mainLayout;
    QWidget *mainWidget;

    void initLayout();
    void initSignals();
    void initSideWindows();

  public:
    explicit MainWindow(Service &service, QWidget *parent = nullptr)
        : QMainWindow(parent), serv(service) {
        initLayout();
        initSignals();
        initSideWindows();
    }
};
