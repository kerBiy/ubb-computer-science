//
// Created by Alex Balta on 15.06.2024.
//

#include "Model.hpp"

QVariant Model::data(const QModelIndex &index, int role) const {
    if (!index.isValid()) {
        return {};
    }

    const auto &items = service.getAll();
    const auto &item = items[index.row()];

    if (role == Qt::DisplayRole) {

        switch (index.column()) {
            case 0: return item.getId();
            case 1: return QString::fromStdString(item.getName());
            case 2: return QString::fromStdString(item.getType());
            case 3: return item.getWheelsCount();
            case 4: return service.raportType()[item.getType()];

            default: return {};
        }
    } else if (role == Qt::BackgroundRole) {
        if (item.getType() == type) {
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
            case 0: return "ID";
            case 1: return "NAME";
            case 2: return "TYPE";
            case 3: return "WHEELS COUNT";
            case 4: return "SAME COUNT";
            default: return {};
        }
    }

    return {};
}

void Model::updateModel() {
    beginResetModel();
    endResetModel();
}