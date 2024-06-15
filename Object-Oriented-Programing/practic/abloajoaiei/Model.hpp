//
// Created by Alex Balta on 12.06.2024.
//
#pragma once

#include <QAbstractTableModel>
#include "Service.hpp"

class Model : public QAbstractTableModel {
  Q_OBJECT
  private:
    Service &service;
    std::vector<Product> records;
    double maxPrice;

  public:
    explicit Model(Service &service, QObject *parent = nullptr)
        : QAbstractTableModel(parent), service(service) {
        records = service.getAll();
    }

    int rowCount(const QModelIndex &parent = QModelIndex()) const override {
        return (int) records.size();
    }

    int columnCount(const QModelIndex &parent = QModelIndex()) const override {
        return 5;
    }

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    void updateModel();
    void setRecords(std::vector<Product> rec);
    void refreshModel();
    void setMaxPrice(double new_value) { this->maxPrice = new_value; }
};



