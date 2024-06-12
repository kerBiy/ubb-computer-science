//
// Created by Alex Balta on 12.06.2024.
//

#include <QLabel>
#include "MainWindow.hpp"
#include "SideWindow.hpp"

void MainWindow::initLayout() {
    mainWidget = new QWidget;
    mainLayout = new QVBoxLayout(mainWidget);

    model = new Model(serv);
    tableView = new QTableView(this);
    tableView->setModel(model);

    formLayout = new QHBoxLayout;

    formLayout->addWidget(new QLabel("Id:"));
    inputId = new QLineEdit(this);
    formLayout->addWidget(inputId);

    formLayout->addWidget(new QLabel("Name:"));
    inputName = new QLineEdit(this);
    formLayout->addWidget(inputName);

    formLayout->addWidget(new QLabel("Type:"));
    inputType = new QLineEdit(this);
    formLayout->addWidget(inputType);

    formLayout->addWidget(new QLabel("Price:"));
    inputPrice = new QLineEdit(this);
    formLayout->addWidget(inputPrice);

    addBtn = new QPushButton("Add", this);
    formLayout->addWidget(addBtn);

    inputSliderPrice = new QSlider(Qt::Horizontal, this);
    inputSliderPrice->setRange(1, 100);
    formLayout->addWidget(inputSliderPrice);

    mainLayout->addWidget(tableView);
    mainLayout->addLayout(formLayout);

    setCentralWidget(mainWidget);
}

void MainWindow::initSignals() {
    connect(addBtn, &QPushButton::clicked, [this]() {
        int id = inputId->text().toInt();
        std::string name = inputName->text().toStdString();
        std::string type = inputType->text().toStdString();
        double price = inputPrice->text().toDouble();

        try {
            serv.addProduct(id, name, type, price);
            model->refreshModel();

        } catch (const std::runtime_error &er) {
            QMessageBox::warning(this, "Error", er.what());
        }
    });

    connect(inputSliderPrice, &QSlider::valueChanged, [this]() {
        double maxPrice = inputSliderPrice->value();
        model->setMaxPrice(maxPrice);
        model->refreshModel();
    });

    connect(tableView->selectionModel(), &QItemSelectionModel::selectionChanged, this, [this]() {
        const auto selected = tableView->selectionModel()->selectedRows();

        if (selected.isEmpty()) return;

        const auto index = selected.first();
        inputId->setText(model->data(model->index(index.row(), 0)).toString());
        inputName->setText(model->data(model->index(index.row(), 1)).toString());
        inputType->setText(model->data(model->index(index.row(), 2)).toString());
        inputPrice->setText(model->data(model->index(index.row(), 3)).toString());
    });
}

void MainWindow::initSideWindows() {
    auto items = serv.getRaport();

    for (const auto &[key, value] : items) {
        auto *sideWindow = new SideWindow(key, serv, value);
        sideWindow->show();
    }
}
