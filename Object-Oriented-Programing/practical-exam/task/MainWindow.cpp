//
// Created by Alex Balta on 12.06.2024.
//

#include <QLabel>
#include <QMessageBox>
#include "MainWindow.hpp"

void MainWindow::initLayout() {
    centralWidget = new QWidget(this);
    mainLayout = new QVBoxLayout(centralWidget);

    tableView = new QTableView(this);
    model = new Model(service, this);
    tableView->setModel(model);

    layoutForm = new QFormLayout;

    inputId = new QLineEdit(this);
    layoutForm->addRow(new QLabel("Id:"), inputId);

    inputDescription = new QLineEdit(this);
    layoutForm->addRow(new QLabel("Description:"), inputDescription);

    inputProgrammer1 = new QLineEdit(this);
    layoutForm->addRow(new QLabel("Programmer1:"), inputProgrammer1);

    inputProgrammer2 = new QLineEdit(this);
    layoutForm->addRow(new QLabel("Programmer2:"), inputProgrammer2);

    inputProgrammer3 = new QLineEdit(this);
    layoutForm->addRow(new QLabel("Programmer3:"), inputProgrammer3);

    inputProgrammer4 = new QLineEdit(this);
    layoutForm->addRow(new QLabel("Programmer4:"), inputProgrammer4);

    inputStatus = new QLineEdit(this);
    layoutForm->addRow(new QLabel("Status:"), inputStatus);

    auto *btnLayout = new QVBoxLayout;
    btnAdd = new QPushButton("Add", this);
    btnSearch = new QPushButton("Search", this);

    inputName = new QLineEdit(this);
    inputName->setPlaceholderText("Name:");

    btnLayout->addWidget(btnAdd);
    btnLayout->addWidget(inputName);
    btnLayout->addWidget(btnSearch);

    auto *sideLayout = new QHBoxLayout;
    sideLayout->addLayout(layoutForm);
    sideLayout->addLayout(btnLayout);

    mainLayout->addWidget(tableView);
    mainLayout->addLayout(sideLayout);

    setCentralWidget(centralWidget);
}

void MainWindow::initSignals() {
    connect(btnAdd, &QPushButton::clicked, this, [this]() {
        int id = inputId->text().toInt();
        std::string description = inputDescription->text().toStdString();
        std::vector<std::string> programmers;
        if (!inputProgrammer1->text().isEmpty()) programmers.push_back(inputProgrammer1->text().toStdString());
        if (!inputProgrammer2->text().isEmpty()) programmers.push_back(inputProgrammer2->text().toStdString());
        if (!inputProgrammer3->text().isEmpty()) programmers.push_back(inputProgrammer3->text().toStdString());
        if (!inputProgrammer4->text().isEmpty()) programmers.push_back(inputProgrammer4->text().toStdString());
        std::string status = inputStatus->text().toStdString();

        try {
            service.addTask(id, description, programmers, status);
            model->refreshModel();
        } catch (const ServiceException &e) {
            QMessageBox::warning(this, "Warning", e.what());
        }
    });

    connect(btnSearch, &QPushButton::clicked, this, [this]() {
        try {
            auto records = service.searchByProgrammer(inputName->text().toStdString());
            model->setRecords(records);
        } catch (const ServiceException &e) {
            QMessageBox::warning(this, "Warning", e.what());
        }
    });

    connect(tableView->selectionModel(), &QItemSelectionModel::selectionChanged, this, [this]() {
        const auto selected = tableView->selectionModel()->selectedRows();

        if (selected.isEmpty()) return;

        const auto index = selected.first();
        inputId->setText(model->data(model->index(index.row(), 0)).toString());
        inputDescription->setText(model->data(model->index(index.row(), 1)).toString());
        inputStatus->setText(model->data(model->index(index.row(), 3)).toString());
    });
}
