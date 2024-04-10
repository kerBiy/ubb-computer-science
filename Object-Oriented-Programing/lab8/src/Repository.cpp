//
// Created by Alex Balta on 27.03.2024.
//

#include "Repository.hpp"
#include <iostream>

/*
 * LIBRARY REPOSITORY
 */

std::vector<Book> &Library::getBooks() {
    return items;
}

size_t Library::getLen() const {
    return items.size();
}

void Library::addBook(const Book &book) {
    items.push_back(book);
}

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

ShoppingCart::ShoppingCart(Library &lib) : library{lib} {}

std::vector<std::vector<Book>::iterator> &ShoppingCart::getBooks() {
    return items;
}

size_t ShoppingCart::getLen() const {
    return items.size();
}

void ShoppingCart::addBook(std::vector<Book>::iterator iter) {
    items.push_back(iter);
}

void ShoppingCart::deleteAllBooks() {
    items.clear();
}

//void ShoppingCart::populateRandom(int book_count) {
//
//}
//
//void ShoppingCart::exportAll(const std::string &file_name) {
//
//}
