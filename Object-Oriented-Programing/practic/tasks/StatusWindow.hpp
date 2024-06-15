//
// Created by Alex Balta on 20.05.2024.
//

#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QTableView>
#include <QPushButton>
#include <QHBoxLayout>
#include "Model.hpp"
#include "Service.hpp"

class StatusWindow : public QWidget {
  Q_OBJECT
  private:
    std::string name;
    Service &service;
    QVBoxLayout *mainLayout;
    QTableView *tableView;
    Model *model;

    QPushButton *btnOpen;
    QPushButton *btnInProgress;
    QPushButton *btnClosed;

    QHBoxLayout *buttonLayout;

    void initLayout();
    void addButtons();

  public:
    explicit StatusWindow(std::string name, Service &service, QWidget *parent = nullptr);
};
