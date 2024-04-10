//
// Created by Alex Balta on 27.03.2024.
//

#include "Service.hpp"
#include "Validator.hpp"
#include <algorithm>

Service::Service(Library &lib, ShoppingCart &cart) : library{lib}, shopping_cart{cart} {}

std::vector<Book> &Service::getAllLib() {
    return library.getBooks();
}

void Service::addBookLib(const std::string &title, const std::string &author,
                         const std::string &genre, int year) {
    auto position = library.findBook(title);

    if (library.isValid(position)) {
        throw std::runtime_error("There already exist a book with this title.");
    }

    Book new_book(title, author, genre, year);
    Validator::validateBook(new_book);
    library.addBook(new_book);

}

void Service::updateBookLib(const std::string &title, const std::string &new_author,
                            const std::string &new_genre, int new_year) {
    auto position = library.findBook(title);

    if (!library.isValid(position)) {
        throw std::runtime_error("There are no books with this title.");
    }

    Book new_book(title, new_author, new_genre, new_year);
    Validator::validateBook(new_book);
    library.updateBook(position, new_book);
}

void Service::deleteBookLib(const std::string &title) {
    auto position = library.findBook(title);

    if (!library.isValid(position)) {
        throw std::runtime_error("There are no books with this title.");
    }

    library.deleteBook(position);
}

std::vector<Book> Service::findBooksLib(const std::string &title) {
    std::vector<Book> foundBooks;
    std::vector<Book> allBooks = library.getBooks();

    std::copy_if(allBooks.begin(), allBooks.end(), std::back_inserter(foundBooks),
                 [&title](const Book &book) { return book.getTitle().find(title) == 0; });

    return foundBooks;
}

std::vector<Book> Service::filterBooksLib(int min_year) {
    std::vector<Book> filteredBooks;
    std::vector<Book> allBooks = library.getBooks();

    std::copy_if(allBooks.begin(), allBooks.end(), std::back_inserter(filteredBooks),
                 [min_year](const Book &book) { return book.getYear() >= min_year; });

    return filteredBooks;
}

std::vector<Book> Service::sortBooksLib(const std::function<bool(const Book &, const Book &)> &compare) {
    std::vector<Book> sortedBooks = library.getBooks();
    std::sort(sortedBooks.begin(), sortedBooks.end(), compare);
    return sortedBooks;
}

/*
 * SHOPPING CART
 */

std::vector<std::vector<Book>::iterator> &Service::getShoppingCart() {
    return shopping_cart.getBooks();
}

void Service::addBookCart(const std::string &title) {
    auto position = library.findBook(title);

    if (!library.isValid(position)) {
        throw std::runtime_error("There is not book with this title.");
    }

    shopping_cart.addBook(position);
}

void Service::deleteCart() {
    shopping_cart.deleteAllBooks();
}
