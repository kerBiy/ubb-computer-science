//
// Created by Alex Balta on 18.05.2024.
//

#pragma once

#include <QAbstractTableModel>
#include "Service.hpp"

class Model : public QAbstractTableModel {
  Q_OBJECT
  private:
    Service &service;
  public:
    Model(Service &service, QObject *parent = nullptr)
        : QAbstractTableModel(parent), service(service) {}

    int rowCount(const QModelIndex &parent = QModelIndex()) const override {
        return service.getLen();
    }

    int columnCount(const QModelIndex &parent = QModelIndex()) const override {
        return 6;
    }

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    void updateModel();
};
