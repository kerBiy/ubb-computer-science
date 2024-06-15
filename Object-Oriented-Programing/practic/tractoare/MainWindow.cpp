//
// Created by Alex Balta on 15.06.2024.
//

#include "MainWindow.hpp"

void MainWindow::initLayout() {
    mainWidget = new QWidget(this);
    mainLayout = new QVBoxLayout(mainWidget);

    tableView = new QTableView(this);
    model = new Model(service, this);
    tableView->setModel(model);
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    formLayout = new QHBoxLayout;

    inputId = new QLineEdit(this);
    inputId->setPlaceholderText("Id: ");
    formLayout->addWidget(inputId);

    inputName = new QLineEdit(this);
    inputName->setPlaceholderText("Name: ");
    formLayout->addWidget(inputName);

    inputType = new QLineEdit(this);
    inputType->setPlaceholderText("Type: ");
    formLayout->addWidget(inputType);

    inputWheels = new QLineEdit(this);
    inputWheels->setPlaceholderText("Wheels Count: ");
    formLayout->addWidget(inputWheels);

    addButton = new QPushButton("Add", this);
    formLayout->addWidget(addButton);

    comboBox = new QComboBox(this);

    auto allTypes = service.getAllTypes();
    for (const auto &type : allTypes) {
        comboBox->addItem(QString::fromStdString(type));
    }

    formLayout->addWidget(comboBox);

    chartLayout = new QHBoxLayout;

    mainLayout->addWidget(tableView);
    mainLayout->addLayout(formLayout);
    mainLayout->addLayout(chartLayout);

    setCentralWidget(mainWidget);
}

void MainWindow::initSignals() {
    connect(tableView->selectionModel(), &QItemSelectionModel::selectionChanged, [this]() {
        auto selected = tableView->selectionModel()->selectedRows();

        if (selected.empty()) return;

        auto index = selected.first();
        inputId->setText(model->data(index.siblingAtColumn(0)).toString());
        inputName->setText(model->data(index.siblingAtColumn(1)).toString());
        inputType->setText(model->data(index.siblingAtColumn(2)).toString());
        inputWheels->setText(model->data(index.siblingAtColumn(3)).toString());

        repaint();
    });

    connect(addButton, &QPushButton::clicked, [this]() {
        int id = inputId->text().toInt();
        std::string name = inputName->text().toStdString();
        std::string type = inputType->text().toStdString();
        int wheels_count = inputWheels->text().toInt();

        try {
            service.addTrack(id, name, type, wheels_count);
        } catch (const ServiceException &e) {
            QMessageBox::warning(this, "Warning", e.what());
        }
    });

    connect(comboBox, &QComboBox::activated, [this]() {
        std::string type = comboBox->currentText().toStdString();
        model->setCurrentType(type);
        model->updateModel();
    });

}

void MainWindow::paintEvent(QPaintEvent *event) {
    QMainWindow::paintEvent(event);

    QPainter painter(this);
    int wheelsCount = inputWheels->text().toInt();

    painter.setBrush(Qt::black);
    int circleRadius = 20;
    int circleSpacing = 10;

    for (int i = 0; i < wheelsCount; ++i) {
        int circleX = 50 + (circleRadius * 2 + circleSpacing) * i;
        int circleY = height();

        painter.drawEllipse(circleX - circleRadius, circleY - circleRadius, circleRadius * 2, circleRadius * 2);
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        int wheelsCount = inputWheels->text().toInt();
        QPoint clickPos = event->pos();

        int circleRadius = 20;
        int circleSpacing = 10;

        for (int i = 0; i < wheelsCount; ++i) {
            int circleX = 50 + (circleRadius * 2 + circleSpacing) * i;
            int circleY = height();

            if (std::sqrt(std::pow(clickPos.x() - circleX, 2) + std::pow(clickPos.y() - circleY, 2)) <= circleRadius) {
                inputWheels->setText(QString::number(wheelsCount - 2));
                service.setWheelsCount(inputId->text().toInt(), wheelsCount - 2);
                update();
                break;
            }
        }
    }
}
