//
// Created by Alex Balta on 17.05.2024.
//

#pragma once

#include <QAbstractTableModel>
#include "Service.hpp"

class SongModel : public QAbstractTableModel {
  Q_OBJECT

  private:
    Service &service;

  public:
    /**
     * The main constructor
     * @param service a reference to the service
     * @param parent a ptr to the Qt parent
     */
    explicit SongModel(Service &service, QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
};

