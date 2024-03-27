//
// Created by Alex Balta on 27.03.2024.
//

#pragma once

#include "Book.hpp"
#include <vector>


class Repository {
private:
    std::vector<Book> items;

public:
    Repository() = default;

    ~Repository() = default;

    std::vector<Book> getBooks();

    size_t getLen();

    void addBook(const Book &book);

    void updateBook(const std::vector<Book>::iterator &position, const Book &new_book);

    void deleteBook(const std::vector<Book>::iterator &position);

    std::vector<Book>::iterator findBook(const std::string &title);

    bool isPositionValid(const std::vector<Book>::iterator &position);
};
