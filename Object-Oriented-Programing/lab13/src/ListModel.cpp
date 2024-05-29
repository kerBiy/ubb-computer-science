//
// Created by Alex Balta on 27.05.2024.
//

#include "ListModel.hpp"

ListModel::ListModel(Service &service, QObject *parent) : QAbstractListModel(parent), service(service) {
    records = service.getAllLib();
}

int ListModel::rowCount(const QModelIndex &parent) const {
    return (int) records.size();
}

QVariant ListModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.row() >= records.size()) {
        return {};
    }

    const auto &book = records[index.row()];

    if (role == Qt::DisplayRole) {
        return QString::fromStdString(book.intoString());
    }

    return {};
}

void ListModel::updateModel() {
    beginResetModel();
    endResetModel();
}

void ListModel::setRecords(std::vector<Book> rec) {
    records = std::move(rec);
    updateModel();
}

void ListModel::refreshModel() {
    records = service.getAllLib();
    updateModel();
}
