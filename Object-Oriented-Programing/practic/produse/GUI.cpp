//
// Created by Alex Balta on 19.05.2024.
//

#include "GUI.hpp"

void GUI::initLayout() {
    centralWidget = new QWidget(this);
    layoutMain = new QVBoxLayout(centralWidget);

    model = new Model(service, this);
    tableView = new QTableView(this);
    tableView->setModel(model);
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    auto *layoutForm = new QHBoxLayout;

    inputId = new QLineEdit(this);
    inputName = new QLineEdit(this);
    inputType = new QLineEdit(this);
    inputPrice = new QLineEdit(this);

    layoutForm->addWidget(new QLabel("Id:"));
    layoutForm->addWidget(inputId);
    layoutForm->addWidget(new QLabel("Name:"));
    layoutForm->addWidget(inputName);
    layoutForm->addWidget(new QLabel("Type:"));
    layoutForm->addWidget(inputType);
    layoutForm->addWidget(new QLabel("Price:"));
    layoutForm->addWidget(inputPrice);

    btnAdd = new QPushButton("Add", this);
    layoutForm->addWidget(btnAdd);

    sliderPrice = new QSlider(Qt::Horizontal, this);
    sliderPrice->setRange(1, 100);
    layoutForm->addWidget(new QLabel("Filter Price:"));
    layoutForm->addWidget(sliderPrice);

    layoutMain->addWidget(tableView);
    layoutMain->addLayout(layoutForm);

    setCentralWidget(centralWidget);
}

void GUI::initSignals() {
    connect(btnAdd, &QPushButton::clicked, this, [this]() {
        int id = inputId->text().toInt();
        std::string name = inputName->text().toStdString();
        std::string type = inputType->text().toStdString();
        double price = inputPrice->text().toDouble();

        try {
            service.addProduct(id, name, type, price);
            model->updateModel();
            handleNewProduct();
        } catch (const ServiceException &e) {
            QMessageBox::warning(this, "Warning", e.what());
        }
    });

    connect(sliderPrice, &QSlider::valueChanged, this, [this](int value) {
        model->setMaxPrice(value);
        model->updateModel();
    });

//    connect(this, &QMainWindow::destroyed, this, [this]() { closeTypeWindows(); });
}

void GUI::openTypeWindows() {
    auto products = service.getAll();
    std::map<QString, int> typeCounts;

    for (const auto &product : products) {
        typeCounts[QString::fromStdString(product.getType())]++;
    }

    QScreen * screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int offset = 50;
    int currentX = this->x() + this->width() + offset;
    int currentY = this->y();

    for (const auto &pair : typeCounts) {
        QWidget * window = new QWidget;
        QVBoxLayout * layout = new QVBoxLayout(window);
        QLabel * label = new QLabel("Number of products: " + QString::number(pair.second), window);
        layout->addWidget(label);
        window->setWindowTitle(pair.first);
        typeWindows[pair.first] = window;

        window->setGeometry(currentX, currentY, 100, 100);
        window->show();

        currentX += window->width() + offset;
        if (currentX + window->width() > screenGeometry.width()) {
            currentX = this->x() + this->width() + offset;
            currentY += window->height() + offset;
        }
    }
}

void GUI::handleNewProduct() {
    updateTypeWindows();
}

void GUI::updateTypeWindows() {
    auto typeCounts = service.raportType();

    for (const auto &pair : typeCounts) {
        QString type = QString::fromStdString(pair.first);
        int count = pair.second;

        if (typeWindows.find(type) != typeWindows.end()) {
            QLabel * label = qobject_cast<QLabel *>(typeWindows[type]->layout()->itemAt(0)->widget());
            if (label) {
                label->setText("Number of products: " + QString::number(count));
            }
        } else {
            QWidget * window = new QWidget;
            QVBoxLayout * layout = new QVBoxLayout(window);
            QLabel * label = new QLabel("Number of products: " + QString::number(count), window);
            layout->addWidget(label);
            window->setWindowTitle(type);
            typeWindows[type] = window;

            int offset = 50;
            int currentX = this->x() + this->width() + offset;
            int currentY = this->y();
            window->setGeometry(currentX, currentY, 200, 100);
            window->show();
        }
    }
}

void GUI::closeTypeWindows() {
    for (auto &pair : typeWindows) {
        pair.second->close();
        delete pair.second;
    }
    typeWindows.clear();
}
