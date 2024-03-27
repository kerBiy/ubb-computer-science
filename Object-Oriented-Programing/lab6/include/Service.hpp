//
// Created by Alex Balta on 27.03.2024.
//

#pragma once

#include "Repository.hpp"


class Service {
private:
    Repository repo;

public:
    Service(Repository &repo);

    ~Service() = default;

    std::vector<Book> getAll();

    void addBook(const std::string &title, const std::string &author,
                 const std::string &genre, int year);

    void updateBook(const std::string &title, const std::string &new_author,
                    const std::string &new_genre, int new_year);

    void deleteBook(const std::string &title);
};
