//
// Created by Alex Balta on 21.05.2024.
//

#pragma once

#include <QMainWindow>
#include <QListWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include "Service.hpp"

class GUI : public QMainWindow {
  Q_OBJECT
  private:
    Service &service;
    QListWidget *list;

    QPushButton *rentBtn;
    QPushButton *sortedBySizeBtn;
    QPushButton *sortedByPriceBtn;
    QPushButton *unsortedBtn;

    QWidget *centralWidget;
    QHBoxLayout *mainLayout;
    QVBoxLayout *buttonLayout;

    /**
     * Inits the layout
     */
    void initLayout();
    /**
     * Inits the signals
     */
    void initSignals();
    /**
     * refreshes the list
     */
    void refreshList();
    /**
     * updates the list
     * @param items the new itmes
     */
    void updateList(const std::vector<Dress> &items);
    /**
     * Dress to qstring
     * @param dress the dress you want
     * @return a QString with the name, size and price
     */
    static QString toQString(const Dress &dress);
  public:
    GUI(Service &service, QWidget *parent = nullptr)
        : QMainWindow(parent), service(service) {
        initLayout();
        initSignals();
        refreshList();
    }
};
