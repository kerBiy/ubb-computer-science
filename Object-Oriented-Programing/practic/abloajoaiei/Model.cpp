//
// Created by Alex Balta on 12.06.2024.
//

#include "Model.hpp"
#include <QColor>

QVariant Model::data(const QModelIndex &index, int role) const {
    if (!index.isValid()) {
        return {};
    }

    const auto &tasks = records;
    const auto &task = tasks[index.row()];

    int count = 0;
    for (const auto &chr : task.getName()) {
        if (chr == 'a' || chr == 'e' || chr == 'i' || chr == 'o' || chr == 'u') {
            count++;
        }
    }

    if (role == Qt::DisplayRole || role == Qt::EditRole) {
        switch (index.column()) {
            case 0:return task.getId();
            case 1:return QString::fromStdString(task.getName());
            case 2:return QString::fromStdString(task.getType());
            case 3:return task.getPrice();
            case 4:return count;
            default:return {};
        }
    } else if (role == Qt::BackgroundRole && index.column() == 3) {
        if (task.getPrice() <= maxPrice) {
            return QColor(Qt::red);
        }
    }

    return {};
}

QVariant Model::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole) {
        return {};
    }

    if (orientation == Qt::Horizontal) {
        switch (section) {
            case 0:return "ID";
            case 1:return "NAME";
            case 2:return "TYPE";
            case 3:return "PRICE";
            case 4:return "VOCALE";
            default:return {};
        }
    }

    return {};
}

void Model::updateModel() {
    beginResetModel();
    endResetModel();
}

void Model::setRecords(std::vector<Product> rec) {
    records = std::move(rec);
    updateModel();
}

void Model::refreshModel() {
    records = service.getAll();
    updateModel();
}
