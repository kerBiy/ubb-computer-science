//
// Created by Alex Balta on 27.03.2024.
//

#include "Repository.hpp"
#include <iostream>

Vector<Book> &Repository::getBooks() {
    return items;
}

size_t Repository::getLen() const {
    return items.size();
}

void Repository::addBook(const Book &book) {
    items.push_back(book);
}

void Repository::updateBook(Iterator<Book> &position, const Book &new_book) {
    items.set(position, new_book);
}

void Repository::deleteBook(Iterator<Book> &position) {
    items.erase(position);
}

Iterator<Book> Repository::findBook(const std::string &title) {
    return std::find_if(items.begin(), items.end(), [=](const Book &book) {
        return book.getTitle() == title;
    });
}