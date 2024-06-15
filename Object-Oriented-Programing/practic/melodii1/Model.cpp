//
// Created by Alex Balta on 17.05.2024.
//

#include "Model.hpp"

Model::Model(Service &service, QObject *parent) : QAbstractTableModel(parent), service(service) {}

int Model::rowCount(const QModelIndex &parent) const {
    return service.getLen();
}

int Model::columnCount(const QModelIndex &parent) const {
    return 5; // id, title, author, rank, count of same rank
}

QVariant Model::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || role != Qt::DisplayRole) {
        return {};
    }

    const auto &songs = service.getSongs();
    const auto &song = songs[index.row()];

    switch (index.column()) {
        case 0: return song.getId();
        case 1: return QString::fromStdString(song.getTitle());
        case 2: return QString::fromStdString(song.getAuthor());
        case 3: return song.getRank();
        case 4:return service.raportRanks()[song.getRank()];

        default: return {};
    }
}

QVariant Model::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole) {
        return {};
    }

    if (orientation == Qt::Horizontal) {
        switch (section) {
            case 0: return "ID";
            case 1: return "TITLE";
            case 2: return "AUTHOR";
            case 3: return "RANK";
            case 4: return "COUNT";
            default: return {};
        }
    }

    return {};
}

void Model::updateModel() {
    beginResetModel();
    endResetModel();
}

