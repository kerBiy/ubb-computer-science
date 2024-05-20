#include "Model.hpp"

QVariant Model::data(const QModelIndex &index, int role) const {
    if (!index.isValid()) {
        return {};
    }

    const auto &products = service.getAll();
    const auto &product = products[index.row()];

    if (role == Qt::DisplayRole || role == Qt::EditRole) {
        switch (index.column()) {
            case 0:return product.getId();
            case 1:return QString::fromStdString(product.getName());
            case 2:return QString::fromStdString(product.getType());
            case 3:return product.getPrice();
            case 4:return 5;
            default:return {};
        }
    } else if (role == Qt::BackgroundRole && index.column() == 3) {
        if (product.getPrice() <= maxPrice) {
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
            case 4:return "VOWELS";
            default:return {};
        }
    }

    return {};
}

void Model::updateModel() {
    beginResetModel();
    endResetModel();
}