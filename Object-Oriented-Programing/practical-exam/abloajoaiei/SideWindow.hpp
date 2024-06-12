//
// Created by Alex Balta on 12.06.2024.
//

#pragma once
#include <QWidget>
#include <QTableView>
#include <QLabel>
#include <utility>

#include "Model.hpp"
#include "Observer.hpp"

class SideWindow : public QWidget, public Observer {
  Q_OBJECT
  private:
    std::string type;
    QLabel *label;
    Service &service;
    int value;
    QHBoxLayout *mainLayout;

  public:
    SideWindow(const std::string &type, Service &service, int value, QWidget *parent = nullptr)
        : QWidget(parent), type(type), service(service), value(value) {
        service.addListener(this);
        this->setWindowTitle(QString::fromStdString(type));
        label = new QLabel(QString::fromStdString(type + " " + std::to_string(value)), this);
        mainLayout = new QHBoxLayout(this);
        mainLayout->addWidget(label);
    }

    void update() override {
        auto items = service.getRaport();
        value = items[type];
        label->setText(QString::fromStdString(type + " " + std::to_string(value)));
    }

    ~SideWindow() override { service.deleteListener(this); }

};
