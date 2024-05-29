//
// Created by Alex Balta on 25.05.2024.
//

#pragma once

#pragma once

#include "Service.hpp"

#include <QDialog>
#include <QPainter>
#include <QVBoxLayout>
#include <QLabel>
#include <QPaintEvent>

class ShoppingCartDrawing : public QDialog, public Observer {
  private:
    Service &service;
    QLabel *count_label;
    QVBoxLayout *main_layout;

    const int CIRCLE_SIZE = 20;
    const int PENCIL_WIDTH = 5;

  public:
    explicit ShoppingCartDrawing(Service &service, QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
    void update() override;

  protected:
    void closeEvent(QCloseEvent *event) override {
        service.deleteListener(this);
    }
};
