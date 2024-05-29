//
// Created by Alex Balta on 27.05.2024.
//

#pragma once

#include <QAbstractListModel>
#include "Service.hpp"

class ListModel : public QAbstractListModel {
  private:
    Service &service;
    std::vector<Book> records;

  public:
    explicit ListModel(Service &service, QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    void updateModel();
    void setRecords(std::vector<Book> rec);
    void refreshModel();
};

