//
// Created by Alex Balta on 07.05.2024.
//

#pragma once

#include "TableModel.hpp"
#include "ShoppingCartWindow.hpp"
#include "ShoppingCartDrawing.hpp"

#include <QApplication>
#include <QHeaderView>
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

class GUI : public QMainWindow {
  private:
    Service &service;
    TableModel *model;

    // Buttons

    QPushButton *add_btn;
    QPushButton *delete_btn;
    QPushButton *update_btn;
    QPushButton *search_btn;

    QPushButton *filter_year_btn;
    QPushButton *sort_title_btn;
    QPushButton *sort_year_btn;

    QPushButton *add_cart_btn;
    QPushButton *delete_cart_btn;
    QPushButton *populate_cart_btn;

    QPushButton *refresh_btn;
    QPushButton *undo_btn;
    QPushButton *cart_window_btn;
    QPushButton *cart_drawing_btn;

    std::unordered_map<std::string, QPushButton *> genre_buttons;

    // Input Boxes

    QLineEdit *input_title;
    QLineEdit *input_author;
    QLineEdit *input_genre;
    QLineEdit *input_year;
    QSlider *input_count;

    // Layout and Widget

    QFormLayout *form_layout;
    QTableView *table_view;

    // Main shit

    QWidget *main_widget;
    QHBoxLayout *main_layout;

    /**
     * Allocates the components and constructs the layout of the GUI.
     */
    void initLayout();

    /**
     * Gives functionality to the buttons.
     */
    void connectSignals();

    /*
     * Add method to create genre buttons
     */
    void generateGenreButtons();
  public:
    /**
     * The constructor for the GUI class.
     * @param service the service reference that the class is gonna use.
     */
    explicit GUI(Service &service, QWidget *parent = nullptr);
};
