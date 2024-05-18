//
// Created by Alex Balta on 17.05.2024.
//

#include "SongModel.hpp"

SongModel::SongModel(Service &service, QObject *parent) : QAbstractTableModel(parent), service(service) {}

int SongModel::rowCount(const QModelIndex &parent) const {
    return service.getLen();
}

int SongModel::columnCount(const QModelIndex &parent) const {
    return 5; // id, title, author, rank, count of same rank
}

QVariant SongModel::data(const QModelIndex &index, int role) const {
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

QVariant SongModel::headerData(int section, Qt::Orientation orientation, int role) const {
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

bool SongModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (role != Qt::EditRole) {
        return false;
    }

    auto song = service.getSongs()[index.row()];

    std::string new_title = song.getTitle();
    int new_rank = song.getRank();

    switch (index.column()) {
        case 1: {
            new_title = value.toString().toStdString();
            break;
        }
        case 3: {
            new_rank = value.toInt();
            break;
        }
        default: return false;
    }

    service.updateSong(song.getId(), new_title, new_rank);

    emit dataChanged(index, index, {role});
    return true;
}

Qt::ItemFlags SongModel::flags(const QModelIndex &index) const {
    if (!index.isValid()) {
        return Qt::NoItemFlags;
    }

    Qt::ItemFlags flags = QAbstractTableModel::flags(index);

    if (index.column() == 1 || index.column() == 3) { // Title and Rank columns
        flags |= Qt::ItemIsEditable;
    }

    return flags;
}
