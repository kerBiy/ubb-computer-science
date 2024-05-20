//
// Created by Alex Balta on 20.05.2024.
//

#pragma once

#include <QAbstractTableModel>

#include "Service.hpp"

class Model : public QAbstractTableModel {
  Q_OBJECT
  private:
    Service &service;
    std::vector<Task> records;

  public:
    explicit Model(Service &service, QObject *parent = nullptr)
        : QAbstractTableModel(parent), service(service) {
        records = service.getAll();
    }

    int rowCount(const QModelIndex &parent = QModelIndex()) const override {
        return (int) records.size();
    }

    int columnCount(const QModelIndex &parent = QModelIndex()) const override {
        return 4;
    }

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    void updateModel();
    void setRecords(std::vector<Task> rec);
    void refreshModel();
};

