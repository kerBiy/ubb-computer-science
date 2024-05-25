//
// Created by Alex Balta on 07.05.2024.
//

#include "GUI.hpp"

GUI::GUI(Service &service, QWidget *parent) : QMainWindow(parent), service{service} {
    initLayout();
    connectSignals();
    generateGenreButtons();
}

void GUI::initLayout() {
    main_widget = new QWidget(this);
    main_layout = new QHBoxLayout(main_widget);

    form_layout = new QFormLayout;

    input_title = new QLineEdit(this);
    input_author = new QLineEdit(this);
    input_genre = new QLineEdit(this);
    input_year = new QLineEdit(this);

    form_layout->addRow(new QLabel("The title is:"), input_title);
    form_layout->addRow(new QLabel("The author is:"), input_author);
    form_layout->addRow(new QLabel("The genre is:"), input_genre);
    form_layout->addRow(new QLabel("The year is:"), input_year);

    add_btn = new QPushButton{"Add"};
    delete_btn = new QPushButton{"Delete"};
    update_btn = new QPushButton{"Update"};

    search_btn = new QPushButton{"Search by title"};
    filter_year_btn = new QPushButton{"Filter by year"};

    sort_title_btn = new QPushButton{"Sort by title"};
    sort_year_btn = new QPushButton{"Sort by year"};

    undo_btn = new QPushButton{"Undo"};
    refresh_btn = new QPushButton{"Refresh"};
    close_btn = new QPushButton{"Shopping Cart"};

    auto *button_widget_crud = new QHBoxLayout;
    button_widget_crud->addWidget(add_btn);
    button_widget_crud->addWidget(delete_btn);
    button_widget_crud->addWidget(update_btn);

    auto *button_widget_filter = new QHBoxLayout;
    button_widget_filter->addWidget(search_btn);
    button_widget_filter->addWidget(filter_year_btn);

    auto *button_widget_sort = new QHBoxLayout;
    button_widget_sort->addWidget(sort_title_btn);
    button_widget_sort->addWidget(sort_year_btn);

    auto *button_widget_options = new QHBoxLayout;
    button_widget_options->addWidget(close_btn);
    button_widget_options->addWidget(refresh_btn);
    button_widget_options->addWidget(undo_btn);

    form_layout->addRow(button_widget_crud);
    form_layout->addRow(button_widget_filter);
    form_layout->addRow(button_widget_sort);

    table_view = new QTableView(this);
    model = new TableModel(service, this);
    table_view->setModel(model);
    table_view->setMinimumWidth(400);
    table_view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    auto *table_layout = new QVBoxLayout;
    table_layout->addWidget(table_view);
    table_layout->addLayout(button_widget_options);

    main_layout->addLayout(form_layout);
    main_layout->addLayout(table_layout);

    this->setCentralWidget(main_widget);
}

void GUI::connectSignals() {
    connect(table_view->selectionModel(), &QItemSelectionModel::selectionChanged, this, [this]() {
        const auto selected = table_view->selectionModel()->selectedRows();

        if (selected.isEmpty()) return;

        const auto index = selected.first();
        input_title->setText(model->data(model->index(index.row(), 0)).toString());
        input_author->setText(model->data(model->index(index.row(), 1)).toString());
        input_genre->setText(model->data(model->index(index.row(), 2)).toString());
        input_year->setText(model->data(model->index(index.row(), 3)).toString());
    });

    QObject::connect(add_btn, &QPushButton::clicked, [this]() {
        try {
            service.addBookLib(input_title->text().toStdString(), input_author->text().toStdString(),
                               input_genre->text().toStdString(), input_year->text().toInt());
            model->refreshModel();

            QMessageBox::information(this, "Succes", "The element was added");
        } catch (const std::exception &error) {
            QMessageBox::warning(this, "Error", error.what());
        }
    });

    QObject::connect(delete_btn, &QPushButton::clicked, [this]() {
        const auto selected = table_view->selectionModel()->selectedRows();

        if (selected.isEmpty()) return;

        const auto index = selected.first();
        const auto Qname = model->data(model->index(index.row(), 0)).toString();

        try {
            service.deleteBookLib(Qname.toStdString());
            model->refreshModel();

            QMessageBox::information(this, "Succes", "The element was deleted");
        } catch (const std::exception &error) {
            QMessageBox::warning(this, "Error", error.what());
        }
    });

    QObject::connect(update_btn, &QPushButton::clicked, [this]() {
        try {
            service.updateBookLib(input_title->text().toStdString(), input_author->text().toStdString(),
                                  input_genre->text().toStdString(), input_year->text().toInt());
            model->refreshModel();

            QMessageBox::information(this, "Succes", "The element was updated");
        } catch (const std::exception &error) {
            QMessageBox::warning(this, "Error", error.what());
        }
    });

    QObject::connect(search_btn, &QPushButton::clicked, [this]() {
        try {
            auto books = service.findBooksLib(input_title->text().toStdString());
            model->setRecords(books);
        } catch (const std::exception &error) {
            QMessageBox::warning(this, "Error", error.what());
        }
    });

    QObject::connect(filter_year_btn, &QPushButton::clicked, [this]() {
        try {
            auto filter_year = service.filterBooksLib(input_year->text().toInt());
            model->setRecords(filter_year);
        } catch (const std::exception &error) {
            QMessageBox::warning(this, "Error", error.what());
        }
    });

    QObject::connect(sort_title_btn, &QPushButton::clicked, [this]() {
        auto sorted_title = service.sortBooksLib(
            [&](const Book &a, const Book &b) {
                return a.getTitle() <= b.getTitle();
            });

        model->setRecords(sorted_title);
    });

    QObject::connect(sort_year_btn, &QPushButton::clicked, [this]() {
        auto sorted_year = service.sortBooksLib(
            [&](const Book &a, const Book &b) {
                return a.getYear() <= b.getYear();
            });

        model->setRecords(sorted_year);
    });

    QObject::connect(close_btn, &QPushButton::clicked, [this]() {
        auto *window = new ShoppingCartWindow(service);
        window->show();
    });

    QObject::connect(refresh_btn, &QPushButton::clicked, [this]() {
        model->refreshModel();
    });

    QObject::connect(undo_btn, &QPushButton::clicked, [this]() {
        try {
            service.undo();
            model->refreshModel();

            QMessageBox::information(this, "Succes", "The last operation was undone");
        } catch (const std::exception &error) {
            QMessageBox::warning(this, "Error", error.what());
        }
    });
}

void GUI::generateGenreButtons() {
    std::unordered_map<std::string, int> raport = service.getRaport();

    for (const auto &entry : raport) {
        const std::string &genre = entry.first;

        auto it = genreButtons.find(genre);

        if (it != genreButtons.end()) {
            it->second->setText(QString::fromStdString(genre));
        } else {
            auto *genreButton = new QPushButton(QString::fromStdString(genre));
            form_layout->addRow(genreButton);

            QObject::connect(genreButton, &QPushButton::clicked, [&, genre]() {
                int count = service.getRaport()[genre];
                QMessageBox::information(this, "Report", QString("%1 books of genre %2").arg(count).arg(genre.c_str()));
            });

            genreButtons[genre] = genreButton;
        }
    }
}