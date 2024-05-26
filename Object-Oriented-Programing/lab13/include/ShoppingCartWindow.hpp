//
// Created by Alex Balta on 24.05.2024.
//

#pragma once

#include "Service.hpp"

#include <QPushButton>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QFormLayout>
#include <QListWidget>
#include <QMessageBox>
#include <QDialog>
#include <QTableWidget>
#include <QMainWindow>

class ShoppingCartWindow : public QWidget, public Observer {
  private:
    Service &service;

    QListWidget *list_widget;
    QFormLayout *form_layout;
    QVBoxLayout *main_layout;

    QLineEdit *input_name;
    QSlider *input_count;

    QPushButton *btn_add;
    QPushButton *btn_delete;
    QPushButton *btn_populate;
    QPushButton *btn_export_html;
    QPushButton *btn_export_csv;

    void initLayout();
    void connectSignals();
    void refreshList();
  public:
    explicit ShoppingCartWindow(Service &service, QWidget *parent = nullptr)
        : QWidget(parent), service(service) {
        initLayout();
        connectSignals();
        refreshList();
    }

    void update() override {
        refreshList();
    }

  protected:
    void closeEvent(QCloseEvent *event) override {
        service.deleteListener(this);
    }
};
