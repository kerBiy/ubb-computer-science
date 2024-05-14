//
// Created by Alex Balta on 07.05.2024.
//

#pragma once

#include "Service.hpp"

#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QFormLayout>
#include <QListWidget>
#include <QMessageBox>
#include <QDialog>
#include <QTableWidget>

class GUI : public QWidget {
  private:
    Service &service;

    // Buttons

    QPushButton *add_btn;
    QPushButton *delete_btn;
    QPushButton *update_btn;
    QPushButton *search_btn;

    QPushButton *filter_year_btn;
    QPushButton *sort_title_btn;
    QPushButton *sort_year_btn;

    QPushButton *refresh_btn;
    QPushButton *undo_btn;
    QPushButton *close_btn;

    std::unordered_map<std::string, QPushButton *> genreButtons;

    // Labels

    QLabel *title_text;
    QLabel *author_text;
    QLabel *genre_text;
    QLabel *year_text;

    // Input Boxes

    QLineEdit *title_input_box;
    QLineEdit *author_input_box;
    QLineEdit *genre_input_box;
    QLineEdit *year_input_box;

    // Layout and Widget

    QFormLayout *form_layout;
    QListWidget *item_list;

    /**
     * Allocates the components and constructs the layout of the GUI.
     */
    void componentsInit();

    /**
     * Gives functionality to the buttons.
     */
    void signalsInit();

    /**
     * Refreshes the list of books.
     */
    void refreshItemList();

    /**
     * Converts from a book to a QString.
     * @param book the book you want to convert.
     * @return the QString containing all of the books information.
     */
    static QString toQString(const Book &book);

    /*
     * Add method to create genre buttons
     */
    void updateGenreButtons();
  public:
    /**
     * The constructor for the GUI class.
     * @param service the service reference that the class is gonna use.
     */
    explicit GUI(Service &service);

    ~GUI() override;
};
