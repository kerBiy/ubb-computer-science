//
// Created by Alex Balta on 27.03.2024.
//

#include "Service.hpp"

Service::Service(Repository &repo) : repo(repo) {}

std::vector<Book> Service::getAll() {
    return repo.getBooks();
}

void Service::addBook(const std::string &title, const std::string &author,
                      const std::string &genre, int year) {
    auto position = repo.findBook(title);
    if (repo.isPositionValid(position)) {
        return;
    }

    Book new_book(title, author, genre, year);
    repo.addBook(new_book);

}

void Service::updateBook(const std::string &title, const std::string &new_author,
                         const std::string &new_genre, int new_year) {
    auto position = repo.findBook(title);

    if (!repo.isPositionValid(position)) {
        return;
    }

    Book new_book(title, new_author, new_genre, new_year);
    repo.updateBook(position, new_book);
}

void Service::deleteBook(const std::string &title) {
    auto position = repo.findBook(title);

    if (!repo.isPositionValid(position)) {
        return;
    }

    repo.deleteBook(position);
}
