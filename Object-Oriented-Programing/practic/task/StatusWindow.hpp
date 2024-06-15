//
// Created by Alex Balta on 12.06.2024.
//

#pragma once

#include "Model.hpp"
#include <QWidget>
#include <utility>
#include <QVBoxLayout>
#include <QTableView>
#include <QPushButton>

#include "Observer.hpp"

class StatusWindow : public QWidget, public Observer {
  Q_OBJECT
  private:
    std::string status;
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
    explicit StatusWindow(std::string status, Service &service, QWidget *parent = nullptr)
        : QWidget(parent), status(std::move(status)), service(service) {
        service.addListener(this);
        initLayout();
        addButtons();
    }

    void update() override {
        model->setRecords(service.getTasksByStatus(status));
    }

    ~StatusWindow() override {
        service.deleteListener(this);
    }
};
