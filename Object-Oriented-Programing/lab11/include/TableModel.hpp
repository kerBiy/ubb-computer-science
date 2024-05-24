//
// Created by Alex Balta on 23.05.2024.
//

#pragma once

#include <QAbstractTableModel>
#include "Service.hpp"

class TableModel : public QAbstractTableModel {
  private:
    Service &service;
    std::vector<Book> records;

  public:
    explicit TableModel(Service &service, QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    void updateModel();
    void setRecords(std::vector<Book> rec);
    void refreshModel();
};

