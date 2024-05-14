//
// Created by Alex Balta on 14.05.2024.
//

#pragma once

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

class GUIShoppingCart : public QWidget {
  private:
    QPushButton *add_btn;
    QPushButton *delete_btn;
    QPushButton *populate_btn;
    QPushButton *export_html_btn;
    QPushButton *export_csv_btn;

    QLabel *title_text;
    QLabel *count_text;

    QLineEdit *title_input_box;
    QLineEdit *count_input_box;

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

  public:
    /**
     * The constructor for the GUI class.
     * @param service the service reference that the class is gonna use.
     */
    explicit GUIShoppingCart();
};
