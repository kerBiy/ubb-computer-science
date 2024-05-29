//
// Created by Alex Balta on 27.05.2024.
//

#include "ShoppingCartDrawing.hpp"

ShoppingCartDrawing::ShoppingCartDrawing(Service &service, QWidget *parent)
    : QDialog(parent), service(service) {
    service.addListener(this);
    main_layout = new QVBoxLayout(this);
    count_label = new QLabel("Number of circles: 0");
    main_layout->addWidget(count_label);
}

void ShoppingCartDrawing::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    auto const &cart = service.getShoppingCart();

    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> distributionX(CIRCLE_SIZE, width() - CIRCLE_SIZE);
    std::uniform_int_distribution<int> distributionY(CIRCLE_SIZE, height() - CIRCLE_SIZE);

    for (const auto &_ : cart) {
        painter.setPen(QPen(Qt::blue, PENCIL_WIDTH));
//        painter.setBrush(QBrush{Qt::blue, Qt::SolidPattern});

        int x = distributionX(gen);
        int y = distributionY(gen);

        painter.drawEllipse(x, y, CIRCLE_SIZE, CIRCLE_SIZE);
    }

    count_label->setText("Number of circles: " + QString::number(cart.size()));
}

void ShoppingCartDrawing::update() {
    repaint();
}