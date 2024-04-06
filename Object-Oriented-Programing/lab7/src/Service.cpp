//
// Created by Alex Balta on 27.03.2024.
//

#include "Service.hpp"
#include "Validator.hpp"

Service::Service(Repository &repo) : repo{repo} {}

Vector<Book> &Service::getAll() {
    return repo.getBooks();
}

void Service::addBook(const std::string &title, const std::string &author,
                      const std::string &genre, int year) {
    auto position = repo.findBook(title);

    if (position.valid()) {
        throw std::runtime_error("There already exist a book with this title.");
    }

    Book new_book(title, author, genre, year);
    Validator::validateBook(new_book);
    repo.addBook(new_book);

}

void Service::updateBook(const std::string &title, const std::string &new_author,
                         const std::string &new_genre, int new_year) {
    auto position = repo.findBook(title);

    if (!position.valid()) {
        throw std::runtime_error("There are no books with this title.");
    }

    Book new_book(title, new_author, new_genre, new_year);
    Validator::validateBook(new_book);
    repo.updateBook(position, new_book);
}

void Service::deleteBook(const std::string &title) {
    auto position = repo.findBook(title);

    if (!position.valid()) {
        throw std::runtime_error("There are no books with this title.");
    }

    repo.deleteBook(position);
}

Vector<Book> Service::findBooks(const std::string &title) {
    Vector<Book> foundBooks;

    for (const auto &book: repo.getBooks()) {
        if (book.getTitle().find(title) == 0) {
            foundBooks.push_back(book);
        }
    }

    return foundBooks;
}

Vector<Book> Service::filterBooks(int min_year) {
    Vector<Book> filteredBooks;
    Vector<Book> allBooks = repo.getBooks();

    for (const auto &book: allBooks) {
        if (book.getYear() >= min_year) {
            filteredBooks.push_back(book);
        }
    }

    return filteredBooks;
}


Vector<Book> Service::sortBooks(const std::function<bool(const Book &, const Book &)> &compare) {
    Vector<Book> sortedBooks = repo.getBooks();
    size_t len = sortedBooks.size();

    for (size_t i = 0; i < len; ++i) {
        for (size_t j = i + 1; j < len; ++j) {
            Book &iBook = sortedBooks[i];
            Book &jBook = sortedBooks[j];

            if (compare(iBook, jBook)) {
                Book &temp = iBook;
                sortedBooks[i] = jBook;
                sortedBooks[j] = temp;
            }
        }
    }

    return sortedBooks;
}
