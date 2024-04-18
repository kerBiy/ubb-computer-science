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

Book Library::deleteBook(std::vector<Book>::iterator &position) {
    auto previous_book = *position;
    items.erase(position);
    return previous_book;
}

Book Library::updateBook(std::vector<Book>::iterator &position, const Book &new_book) {
    auto previous_book = *position;
    *position = new_book;
    return previous_book;
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
