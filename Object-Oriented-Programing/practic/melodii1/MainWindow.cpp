//
// Created by Alex Balta on 17.05.2024.
//

#include "MainWindow.hpp"

MainWindow::MainWindow(Service &service, QWidget *parent) : QMainWindow(parent), service(service) {
    setupUI();
    setupConnections();
    updateChart();
}

void MainWindow::setupUI() {
    auto *centralWidget = new QWidget(this);
    auto *mainLayout = new QVBoxLayout(centralWidget);

    tableView = new QTableView(this);
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    model = new SongModel(service, this);
    tableView->setModel(model);
    mainLayout->addWidget(tableView);

    auto *formLayout = new QHBoxLayout();

    titleEdit = new QLineEdit(this);
    formLayout->addWidget(new QLabel("Title:", this));
    formLayout->addWidget(titleEdit);

    rankSlider = new QSlider(Qt::Horizontal, this);
    rankSlider->setRange(0, 10);
    formLayout->addWidget(new QLabel("Rank:", this));
    formLayout->addWidget(rankSlider);

    updateButton = new QPushButton("Update", this);
    formLayout->addWidget(updateButton);

    deleteButton = new QPushButton("Delete", this);
    formLayout->addWidget(deleteButton);

    mainLayout->addLayout(formLayout);

    chartLayout = new QVBoxLayout();
    mainLayout->addLayout(chartLayout);

    setCentralWidget(centralWidget);
}

void MainWindow::setupConnections() {
    connect(model, &QAbstractItemModel::dataChanged, this, [this]() {
        updateChart();
    });

    connect(tableView->selectionModel(), &QItemSelectionModel::selectionChanged, this, [this]() {
        const auto selected = tableView->selectionModel()->selectedRows();
        if (selected.isEmpty()) return;

        const auto index = selected.first();
        titleEdit->setText(model->data(model->index(index.row(), 1)).toString());
        rankSlider->setValue(model->data(model->index(index.row(), 3)).toInt());
    });

    connect(updateButton, &QPushButton::clicked, this, [this]() {
        const auto selected = tableView->selectionModel()->selectedRows();
        if (selected.isEmpty()) return;

        const auto index = selected.first();
        const auto id = model->data(model->index(index.row(), 0)).toInt();
        const auto newTitle = titleEdit->text();
        const auto newRank = rankSlider->value();

        service.updateSong(id, newTitle.toStdString(), newRank);
        model->setData(index, newTitle, Qt::EditRole);
        model->setData(model->index(index.row(), 3), newRank, Qt::EditRole);
        updateChart();
    });

    connect(deleteButton, &QPushButton::clicked, this, [this]() {
        const auto selected = tableView->selectionModel()->selectedRows();
        if (selected.isEmpty()) return;

        const auto index = selected.first();
        const auto id = model->data(model->index(index.row(), 0)).toInt();

        if (service.getSongs().size() == 1) {
            QMessageBox::warning(this, "Warning", "Cannot delete the last song of the artist!");
            return;
        }

        service.deleteSong(id);
        model->removeRow(index.row());
        updateChart();
    });
}

void MainWindow::updateChart() {
    QLayoutItem *child;
    while ((child = chartLayout->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }

    const auto counts = service.raportRanks();
    for (auto count : counts) {
        auto *bar = new QLabel(QString::number(count), this);
        bar->setFixedHeight(count * 10);
        bar->setStyleSheet("background-color: blue; color: white; text-align: center;");
        chartLayout->addWidget(bar);
    }
}
