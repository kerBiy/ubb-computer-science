//
// Created by Alex Balta on 15.06.2024.
//

#pragma once

#include <QAbstractTableModel>
#include <QColor>
#include "Service.hpp"

class Model : public QAbstractTableModel {
  Q_OBJECT
  private:
    Service &service;
    std::string type;
  public:
    Model(Service &service, QObject *parent = nullptr)
        : QAbstractTableModel(parent), service(service) {}

    int rowCount(const QModelIndex &parent = QModelIndex()) const override {
        return service.getLen();
    }

    int columnCount(const QModelIndex &parent = QModelIndex()) const override {
        return 5;
    }

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    void setCurrentType(const std::string &new_type) { this->type = new_type; }
    void updateModel();

};
