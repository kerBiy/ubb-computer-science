//
// Created by Alex Balta on 16.06.2024.
//

#include "StatusWindow.hpp"

void StatusWindow::initLayout() {
    mainLayout = new QVBoxLayout(this);
    tableView = new QTableView(this);
    model = new Model(service, this);
    model->setRecords(service.getTasksByStatus(status));
    tableView->setModel(model);
    mainLayout->addWidget(tableView);
    this->setWindowTitle(QString::fromStdString(status + " tasks"));
}

void StatusWindow::addButtons() {
    btnOpen = new QPushButton("Open", this);
    btnInProgress = new QPushButton("InProgress", this);
    btnClosed = new QPushButton("Close", this);

    buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(btnOpen);
    buttonLayout->addWidget(btnInProgress);
    buttonLayout->addWidget(btnClosed);

    mainLayout->addLayout(buttonLayout);

    connect(btnOpen, &QPushButton::clicked, this, [this]() {
        auto selected = tableView->selectionModel()->selectedRows();

        if (selected.isEmpty()) return;

        auto index = selected.first();
        int taskId = model->data(index.siblingAtColumn(0), Qt::DisplayRole).toInt();
        service.setTaskStatus(taskId, "open");
        model->setRecords(service.getTasksByStatus(status));
    });

    connect(btnInProgress, &QPushButton::clicked, this, [this]() {
        auto selected = tableView->selectionModel()->selectedRows();

        if (selected.isEmpty()) return;

        auto index = selected.first();
        int taskId = model->data(index.siblingAtColumn(0)).toInt();
        service.setTaskStatus(taskId, "inprogress");
        model->setRecords(service.getTasksByStatus(status));
    });

    connect(btnClosed, &QPushButton::clicked, this, [this]() {
        auto selected = tableView->selectionModel()->selectedRows();

        if (selected.isEmpty()) return;

        auto index = selected.first();
        int taskId = model->data(index.siblingAtColumn(0)).toInt();
        service.setTaskStatus(taskId, "closed");
        model->setRecords(service.getTasksByStatus(status));
    });
}


