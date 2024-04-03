//
// Created by Alex Balta on 27.03.2024.
//

#include "Service.hpp"

Service::Service(Repository &repo) : repo(repo) {}

List<Book> &Service::getAll() {
    return repo.getBooks();
}

void Service::addBook(const std::string &title, const std::string &author,
                      const std::string &genre, int year) {
    auto position = repo.findBook(title);

    if (repo.isPositionValid(position)) {
        throw std::runtime_error("There already exist a book with this title.");
    }

    Book new_book(title, author, genre, year);
    repo.addBook(new_book);

}

void Service::updateBook(const std::string &title, const std::string &new_author,
                         const std::string &new_genre, int new_year) {
    auto position = repo.findBook(title);

    if (!repo.isPositionValid(position)) {
        throw std::runtime_error("There are no books with this title.");
    }

    Book new_book(title, new_author, new_genre, new_year);
    repo.updateBook(position, new_book);
}

void Service::deleteBook(const std::string &title) {
    auto position = repo.findBook(title);

    if (!repo.isPositionValid(position)) {
        throw std::runtime_error("There are no books with this title.");
    }

    repo.deleteBook(position);
}

List<Book> Service::findBooks(const std::string &title) {
    List<Book> output;

    for (auto &x: repo.getBooks()) {
        if (x.getTitle().find(title) == 0) {
            output.push_back(x);
        }
    }

    return output;
}

List<Book> Service::filterBooks(int min_year) {
    List<Book> filteredBooks;
    List<Book> allBooks = repo.getBooks();

    for (const auto &book: allBooks) {
        if (book.getYear() >= min_year) {
            filteredBooks.push_back(book);
        }
    }

    return filteredBooks;
}


List<Book> Service::sortBooks(const std::function<bool(Book, Book)> &compare) {
    List<Book> sortedBooks = repo.getBooks();
    size_t len = sortedBooks.size();

    for (size_t i = 0; i < len; ++i) {
        for (size_t j = i + 1; j < len; ++j) {
            if (compare(sortedBooks.get(i), sortedBooks.get(j))) {
                Book temp = sortedBooks.get(i);
                sortedBooks.set(i, sortedBooks.get(j));
                sortedBooks.set(j, temp);
            }
        }
    }

    return sortedBooks;
}
