//
// Created by Alex Balta on 15.06.2024.
//

#pragma once

#include <QMainWindow>
#include <QMessageBox>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QTableView>
#include <QHeaderView>
#include <QPainter>
#include <QMouseEvent>

#include "Observer.hpp"
#include "Model.hpp"

class MainWindow : public QMainWindow, public Observer {
  Q_OBJECT
  private:
    Service &service;
    Model *model;
    QTableView *tableView;

    QLineEdit *inputId;
    QLineEdit *inputName;
    QLineEdit *inputType;
    QLineEdit *inputWheels;

    QPushButton *addButton;

    QComboBox *comboBox;

    QHBoxLayout *formLayout;
    QHBoxLayout *chartLayout;

    QVBoxLayout *mainLayout;
    QWidget *mainWidget;

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
        model->updateModel();
        repaint();
    }

    ~MainWindow() override {
        service.deleteListener(this);
    }

  protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
};
