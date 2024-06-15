//
// Created by Alex Balta on 17.05.2024.
//

#include "MainWindow.hpp"

MainWindow::MainWindow(Service &service, QWidget *parent) : QMainWindow(parent), service(service) {
    initLayout();
    initSignals();
    updateChart();
}

void MainWindow::initLayout() {
    mainWidget = new QWidget(this);
    mainLayout = new QVBoxLayout(mainWidget);

    tableView = new QTableView(this);
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    model = new Model(service, this);
    tableView->setModel(model);

    formLayout = new QHBoxLayout();

    inputTitle = new QLineEdit(this);
    formLayout->addWidget(new QLabel("Title:", this));
    formLayout->addWidget(inputTitle);

    sliderRank = new QSlider(Qt::Horizontal, this);
    sliderRank->setRange(0, 10);
    formLayout->addWidget(new QLabel("Rank:", this));
    formLayout->addWidget(sliderRank);

    updateButton = new QPushButton("Update", this);
    formLayout->addWidget(updateButton);

    deleteButton = new QPushButton("Delete", this);
    formLayout->addWidget(deleteButton);

    mainLayout->addWidget(tableView);
    mainLayout->addLayout(formLayout);

    chartLayout = new QVBoxLayout();
    mainLayout->addLayout(chartLayout);

    setCentralWidget(mainWidget);
}

void MainWindow::initSignals() {
    service.addListener(this);

    connect(tableView->selectionModel(), &QItemSelectionModel::selectionChanged, [this]() {
        auto selected = tableView->selectionModel()->selectedRows();

        if (selected.isEmpty()) return;

        auto index = selected.first();
        inputTitle->setText(model->data(index.siblingAtColumn(1)).toString());
        sliderRank->setValue(model->data(index.siblingAtColumn(3)).toInt());
    });

    connect(updateButton, &QPushButton::clicked, [this]() {
        auto selected = tableView->selectionModel()->selectedRows();

        if (selected.isEmpty()) return;

        auto index = selected.first();

        auto id = model->data(index.siblingAtColumn(0)).toInt();
        auto newTitle = inputTitle->text().toStdString();
        auto newRank = sliderRank->value();

        try {
            service.updateSong(id, newTitle, newRank);
        } catch (const ServiceException &e) {
            QMessageBox::warning(this, "Warning", e.what());
        }
    });

    connect(deleteButton, &QPushButton::clicked, [this]() {
        auto selected = tableView->selectionModel()->selectedRows();

        if (selected.isEmpty()) return;

        auto index = selected.first();
        auto id = model->data(index.siblingAtColumn(0)).toInt();

        try {
            service.deleteSong(id);
        } catch (const ServiceException &e) {
            QMessageBox::warning(this, "Warning", e.what());
        }
    });
}

void MainWindow::updateChart() {
    QLayoutItem *child = chartLayout->takeAt(0);

    while (child != nullptr) {
        delete child->widget();
        delete child;
        child = chartLayout->takeAt(0);
    }

    auto counts = service.raportRanks();
    for (size_t i = 0; i < counts.size(); ++i) {
        auto *bar = new QLabel(QString::number(i), this);
        bar->setFixedHeight(counts[i] * 20);
        bar->setStyleSheet("background-color: blue; color: white;");
        chartLayout->addWidget(bar);
    }
}

void MainWindow::update() {
    model->updateModel();
    updateChart();
}

MainWindow::~MainWindow() {
    service.deleteListener(this);
}
