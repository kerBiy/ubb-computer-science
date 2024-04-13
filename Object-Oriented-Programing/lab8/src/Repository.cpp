//
// Created by Alex Balta on 27.03.2024.
//

#include "Repository.hpp"
#include <iostream>

/*
 * ABSTRACT REPOSITORY
 */

std::vector<Book> &AbstractRepository::getBooks() {
    return items;
}

size_t AbstractRepository::getLen() const {
    return items.size();
}

void AbstractRepository::addBook(const Book &book) {
    items.push_back(book);
}

/*
 * LIBRARY REPOSITORY
 */

void Library::deleteBook(std::vector<Book>::iterator &position) {
    items.erase(position);
}

void Library::updateBook(std::vector<Book>::iterator &position, const Book &new_book) {
    *position = new_book;
}

std::vector<Book>::iterator Library::findBook(const std::string &title) {
    return std::find_if(items.begin(), items.end(), [&title](const Book &book) {
        return book.getTitle() == title;
    });
}

bool Library::isValid(const std::vector<Book>::iterator &iter) const {
    return iter != items.end();
}

/*
 * SHOPING CART REPOSITORY
 */

void ShoppingCart::deleteAllBooks() {
    items.clear();
}
