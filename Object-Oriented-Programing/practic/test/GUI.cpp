//
// Created by Alex Balta on 21.05.2024.
//

#include "GUI.hpp"
#include <QColor>
#include <iostream>

void GUI::initLayout() {
    centralWidget = new QWidget(this);
    mainLayout = new QHBoxLayout(centralWidget);

    list = new QListWidget(this);

    buttonLayout = new QVBoxLayout;

    rentBtn = new QPushButton("Rent", this);
    sortedBySizeBtn = new QPushButton("Sort By Size", this);
    sortedByPriceBtn = new QPushButton("Sort By Price", this);
    unsortedBtn = new QPushButton("Unsort", this);

    buttonLayout->addWidget(rentBtn);
    buttonLayout->addWidget(sortedBySizeBtn);
    buttonLayout->addWidget(sortedByPriceBtn);
    buttonLayout->addWidget(unsortedBtn);

    mainLayout->addWidget(list);
    mainLayout->addLayout(buttonLayout);

    setCentralWidget(centralWidget);
}

void GUI::initSignals() {
    connect(sortedBySizeBtn, &QPushButton::clicked, this, [this]() {
        updateList(service.sortBySize());
    });

    connect(sortedByPriceBtn, &QPushButton::clicked, this, [this]() {
        updateList(service.sortByPrice());
    });

    connect(unsortedBtn, &QPushButton::clicked, this, [this]() {
        refreshList();
    });

    connect(rentBtn, &QPushButton::clicked, this, [this]() {
        auto selected_items = list->selectedItems();

        if (selected_items.empty()) return;

        auto index = selected_items.first();
//        index->setBackground(Qt::green);

        refreshList();
    });
}

QString GUI::toQString(const Dress &dress) {
    return QString::fromStdString(
        dress.getName() + " " + dress.getSize() + " " + std::to_string(dress.getPrice()));
}

void GUI::refreshList() {
    list->clear();

    int index = 0;
    for (const auto &dress : service.getAll()) {
        auto dress_string = toQString(dress);
        list->addItem(dress_string);
        if (!dress.getValid()) {
            list->item(index)->setBackground(Qt::red);
        }
        index++;
    }
}

void GUI::updateList(const std::vector<Dress> &items) {
    list->clear();

    int index = 0;
    for (const auto &dress : items) {
        auto dress_string = toQString(dress);
        list->addItem(dress_string);
        if (!dress.getValid()) {
            list->item(index)->setBackground(Qt::red);
        }
        index++;
    }
}
