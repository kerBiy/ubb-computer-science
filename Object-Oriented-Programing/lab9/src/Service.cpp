//
// Created by Alex Balta on 27.03.2024.
//

#include "Service.hpp"

#include <fstream>
#include <algorithm>
#include <random>

Service::Service(Library &lib, ShoppingCart &cart) : library{lib}, shopping_cart{cart} {
    std::ofstream html("../database/export.html");
    html.close();

    std::ofstream csv("../database/export.csv");
    csv.close();
}

std::vector<Book> &Service::getAllLib() {
    return library.getBooks();
}

void Service::addBookLib(const std::string &title, const std::string &author,
                         const std::string &genre, int year) {
    auto position = library.findBook(title);

    if (library.isValid(position)) {
        throw ServiceError("There already exist a book with this title.");
    }

    Book new_book(title, author, genre, year);
    Validator::validateBook(new_book);

    library.addBook(new_book);
    history.push_back(std::make_unique<UndoAdd>(library, new_book));
}

void Service::updateBookLib(const std::string &title, const std::string &new_author,
                            const std::string &new_genre, int new_year) {
    auto position = library.findBook(title);

    if (!library.isValid(position)) {
        throw ServiceError("There are no books with this title.");
    }

    Book new_book(title, new_author, new_genre, new_year);
    Validator::validateBook(new_book);

    auto updated_book = library.updateBook(position, new_book);
    history.push_back(std::make_unique<UndoUpdate>(library, updated_book));
}

void Service::deleteBookLib(const std::string &title) {
    auto position = library.findBook(title);

    if (!library.isValid(position)) {
        throw ServiceError("There are no books with this title.");
    }

    auto deleted_book = library.deleteBook(position);
    history.push_back(std::make_unique<UndoDelete>(library, deleted_book));
}

std::vector<Book> Service::findBooksLib(const std::string &title) {
    std::vector<Book> found_books;
    std::vector<Book> all_books = library.getBooks();

    std::copy_if(all_books.begin(), all_books.end(), std::back_inserter(found_books),
                 [&title](const Book &book) { return book.getTitle().find(title) == 0; });

    return found_books;
}

std::vector<Book> Service::filterBooksLib(int min_year) {
    std::vector<Book> filtered_books;
    std::vector<Book> all_books = library.getBooks();

    std::copy_if(all_books.begin(),
                 all_books.end(),
                 std::back_inserter(filtered_books),
                 [min_year](const Book &book) { return book.getYear() >= min_year; });

    return filtered_books;
}

std::vector<Book> Service::sortBooksLib(const std::function<bool(const Book &, const Book &)> &compare) {
    std::vector<Book> sorted_books = library.getBooks();
    std::sort(sorted_books.begin(), sorted_books.end(), compare);
    return sorted_books;
}

/*
 * SHOPPING CART
 */

std::vector<Book> &Service::getShoppingCart() {
    return shopping_cart.getBooks();
}

void Service::addBookCart(const std::string &title) {
    auto position = library.findBook(title);

    if (!library.isValid(position)) {
        throw ServiceError("There is not book with this title to add in the shopping cart.");
    }

    shopping_cart.addBook(*position);
}

void Service::deleteCart() {
    if (shopping_cart.getLen() == 0) {
        throw ServiceError("There are already no books in the shopping cart.");
    }

    shopping_cart.deleteAllBooks();
}

void Service::populateRandomCart(size_t book_count) {
    if (library.getLen() == 0) {
        throw ServiceError("There are no books in the library");
    }

    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> distribution(0, static_cast<int>(library.getLen() - 1));

    for (size_t i = 0; i < book_count; ++i) {
        int random_number = distribution(gen);
        shopping_cart.addBook(library.getBooks()[random_number]);
    }
}

void Service::exportHTML(const std::string &filename) {
    std::ofstream output_file(filename);

    output_file << "<!DOCTYPE html>\n<html lang=\"en\">\n"
                << "<head>\n<title>Book List</title>\n"
                << "<link rel=\"stylesheet\" href=\"style.css\">\n"
                << "\n</head>\n<body>\n";
    output_file << "<h1>Book List</h1>\n<ul>\n";

    for (const auto &book : getShoppingCart()) {
        output_file << "<li>\n";
        output_file << "<strong>Title:</strong> " << book.getTitle() << "<br>\n";
        output_file << "<strong>Author:</strong> " << book.getAuthor() << "<br>\n";
        output_file << "<strong>Genre:</strong> " << book.getGenre() << "<br>\n";
        output_file << "<strong>Year:</strong> " << book.getYear() << "<br>\n";
        output_file << "</li>\n";
    }

    output_file << "</ul>\n</body>\n</html>\n";
}

void Service::exportCSV(const std::string &filename) {
    std::ofstream output_file(filename);

    output_file << "Title,Author,Genre,Year\n";

    for (const auto &book : getShoppingCart()) {
        output_file << "\"" << book.getTitle() << "\",";
        output_file << "\"" << book.getAuthor() << "\",";
        output_file << "\"" << book.getGenre() << "\",";
        output_file << "\"" << book.getYear() << "\"\n";
    }

    output_file.close();
}

/*
 * Undo and Raport
 */

std::unordered_map<std::string, int> Service::getRaport() {
    std::unordered_map<std::string, int> raport;

    for (const Book &book : library.getBooks()) {
        raport[book.getGenre()] += 1;
    }

    return raport;
}

void Service::undo() {
    if (history.empty()) {
        throw ServiceError{"You can't undo any further."};
    }

    auto last_action = std::move(history.back());
    history.pop_back();

    last_action->doUndo();
}