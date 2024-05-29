//
// Created by Alex Balta on 24.05.2024.
//

#include "ShoppingCartWindow.hpp"

void ShoppingCartWindow::initLayout() {
    main_layout = new QVBoxLayout(this);

    list_model = new ListModel(service, this);
    list_view = new QListView(this);
    list_view->setModel(list_model);

    form_layout = new QFormLayout;
    input_name = new QLineEdit(this);
    input_count = new QSlider(Qt::Horizontal, this);
    input_count->setRange(1, 10);

    form_layout->addRow(new QLabel("Enter the name:", this), input_name);
    form_layout->addRow(new QLabel("Enter the count:", this), input_count);

    btn_add = new QPushButton("Add", this);
    btn_delete = new QPushButton("Delete All", this);
    btn_populate = new QPushButton("Populate Random", this);
    btn_export_html = new QPushButton("Export HTML", this);
    btn_export_csv = new QPushButton("Export CSV", this);

    form_layout->addRow(btn_add);
    form_layout->addRow(btn_delete);
    form_layout->addRow(btn_populate);
    form_layout->addRow(btn_export_html);
    form_layout->addRow(btn_export_csv);

    main_layout->addWidget(list_view);
    main_layout->addLayout(form_layout);
}

void ShoppingCartWindow::connectSignals() {
    service.addListener(this);

    connect(btn_add, &QPushButton::clicked, [this]() {
        std::string title = input_name->text().toStdString();

        try {
            service.addBookCart(title);
            refreshList();
            QMessageBox::information(this, "Succes", "The element was added in the cart");
        } catch (const std::exception &error) {
            QMessageBox::warning(this, "Error", error.what());
        }
    });

    connect(btn_delete, &QPushButton::clicked, [this]() {
        try {
            service.deleteCart();
            refreshList();
            QMessageBox::information(this, "Succes", "All items were deleted from the cart");
        } catch (const std::exception &error) {
            QMessageBox::warning(this, "Error", error.what());
        }
    });

    connect(btn_populate, &QPushButton::clicked, [this]() {
        int count = input_count->value();

        try {
            service.populateRandomCart(count);
            refreshList();
            QMessageBox::information(this, "Succes", "The items were added to the cart");
        } catch (const std::exception &error) {
            QMessageBox::warning(this, "Error", error.what());
        }
    });

    connect(btn_export_html, &QPushButton::clicked, [this]() {
        try {
            service.exportHTML("../database/export.html");
            QMessageBox::information(this, "Succes", "The shopping cart was exported");
        } catch (const std::exception &error) {
            QMessageBox::warning(this, "Error", error.what());
        }
    });

    connect(btn_export_csv, &QPushButton::clicked, [this]() {
        try {
            service.exportCSV("../database/export.csv");
            QMessageBox::information(this, "Succes", "The shopping cart was exported");
        } catch (const std::exception &error) {
            QMessageBox::warning(this, "Error", error.what());
        }
    });
}

void ShoppingCartWindow::refreshList() {
    list_model->setRecords(service.getShoppingCart());
}
