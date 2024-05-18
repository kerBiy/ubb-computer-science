//
// Created by Alex Balta on 18.05.2024.
//

#pragma once

#include "Service.hpp"
#include "SongModel.hpp"

#include <QMainWindow>
#include <QTableView>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QString>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QHeaderView>
#include <QMessageBox>
#include <QPainter>

class MainWindow : public QMainWindow {
  Q_OBJECT
  private:
    Service &service;
    SongModel *model;

    QTableView *tableView;

    QLineEdit *inputTitle;
    QLineEdit *inputArtist;
    QLineEdit *inputGenre;

    QPushButton *btnAdd;
    QPushButton *btnDelete;

    void setupLayout();
    void setupSignals();
  public:
    explicit MainWindow(Service &service, QWidget *parent = nullptr)
        : QMainWindow(parent), service(service) {
        setupLayout();
        setupSignals();
    }
  protected:
    void paintEvent(QPaintEvent *event) override;
};
