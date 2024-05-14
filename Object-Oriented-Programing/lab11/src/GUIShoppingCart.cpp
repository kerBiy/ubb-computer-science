//
// Created by Alex Balta on 14.05.2024.
//

#include "GUIShoppingCart.hpp"

GUIShoppingCart::GUIShoppingCart() {
    componentsInit();
    signalsInit();
    refreshItemList();
}

void GUIShoppingCart::componentsInit() {
    auto *forms_widget = new QWidget{this};
    form_layout = new QFormLayout;

    title_text = new QLabel("The title is:");
    title_input_box = new QLineEdit(forms_widget);

    count_text = new QLabel("The count is:");
    count_input_box = new QLineEdit(forms_widget);

    form_layout->addRow(title_text, title_input_box);
    form_layout->addRow(count_text, count_input_box);

    add_btn = new QPushButton{"Add"};
    delete_btn = new QPushButton{"Delete"};
    populate_btn = new QPushButton{"Populate"};

    export_html_btn = new QPushButton{"HTML by title"};
    export_csv_btn = new QPushButton{"CSV by year"};

    auto *button_widget = new QVBoxLayout;
    button_widget->addWidget(add_btn);
    button_widget->addWidget(delete_btn);
    button_widget->addWidget(populate_btn);
    button_widget->addWidget(export_html_btn);
    button_widget->addWidget(export_csv_btn);

    form_layout->addRow(button_widget);

    forms_widget->setLayout(form_layout);

    auto *list_widget = new QWidget;
    item_list = new QListWidget;

    auto *layoutList = new QVBoxLayout;
    layoutList->addWidget(item_list);

    list_widget->setLayout(layoutList);

    auto *main_layout = new QHBoxLayout;
    main_layout->addWidget(forms_widget);
    main_layout->addWidget(list_widget);

    this->setLayout(main_layout);
}

void GUIShoppingCart::signalsInit() {

}
void GUIShoppingCart::refreshItemList() {

}
QString GUIShoppingCart::toQString(const Book &book) {
    return QString();
}
