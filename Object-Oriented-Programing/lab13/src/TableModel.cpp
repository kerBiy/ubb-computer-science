//
// Created by Alex Balta on 23.05.2024.
//

#include "TableModel.hpp"

TableModel::TableModel(Service &service, QObject *parent) : QAbstractTableModel(parent), service(service) {
    records = service.getAllLib();
}

int TableModel::rowCount(const QModelIndex &parent) const {
    return (int) records.size();
}

int TableModel::columnCount(const QModelIndex &parent) const {
    return 4;
}

QVariant TableModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid()) {
        return {};
    }

    const auto &books = records;
    const auto &book = books[index.row()];

    if (role == Qt::DisplayRole || role == Qt::EditRole) {
        switch (index.column()) {
            case 0:return QString::fromStdString(book.getTitle());
            case 1:return QString::fromStdString(book.getAuthor());
            case 2:return QString::fromStdString(book.getGenre());
            case 3:return book.getYear();
            default:return {};
        }
    }

    return {};
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole) {
        return {};
    }

    if (orientation == Qt::Horizontal) {
        switch (section) {
            case 0:return "TITLE";
            case 1:return "AUTHOR";
            case 2:return "GENRE";
            case 3:return "YEAR";
            default:return {};
        }
    }

    return {};
}

void TableModel::updateModel() {
    beginResetModel();
    endResetModel();
}

void TableModel::setRecords(std::vector<Book> rec) {
    records = std::move(rec);
    updateModel();
}

void TableModel::refreshModel() {
    records = service.getAllLib();
    updateModel();
}
