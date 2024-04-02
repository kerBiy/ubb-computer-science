//
// Created by Alex Balta on 27.03.2024.
//

#include "Repository.hpp"

#include <iostream>

const std::vector<Book> &Repository::getBooks() {
    return items;
}

size_t Repository::getLen() {
    return items.size();
}

void Repository::addBook(const Book &book) {
    items.push_back(book);
}

void Repository::updateBook(const std::vector<Book>::iterator &position, const Book &new_book) {
    *position = new_book;
}

void Repository::deleteBook(const std::vector<Book>::iterator &position) {
    items.erase(position);
}

std::vector<Book>::iterator Repository::findBook(const std::string &title) {
    return std::find_if(items.begin(), items.end(), [&](const Book &book) {
        return book.getTitle() == title;
    });
}

bool Repository::isPositionValid(const std::vector<Book>::iterator &position) {
    return position != items.end();
}