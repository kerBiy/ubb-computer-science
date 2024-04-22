//
// Created by Alex Balta on 27.03.2024.
//

#include "Repository.hpp"

#include <fstream>
#include <utility>
#include <sstream>

/*
 * ABSTRACT REPOSITORY
 */

std::vector<Book> &GenericRepository::getBooks() {
    return items;
}

size_t GenericRepository::getLen() const {
    return items.size();
}

/*
 * LIBRARY REPOSITORY
 */

void Library::addBook(const Book &book) {
    items.push_back(book);
}

Book Library::deleteBook(std::vector<Book>::iterator &position) {
    auto previous_book = *position;
    items.erase(position);
    return previous_book;
}

Book Library::updateBook(std::vector<Book>::iterator &position, const Book &new_book) {
    auto previous_book = *position;
    *position = new_book;
    return previous_book;
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
 * LIBRARY FILE REPOSITORY
 */

void LibraryFile::loadFromFile() {
    std::ifstream in(file_name);
    if (!in.is_open()) {
        throw RepositoryError("Can't open file: " + file_name);
    }

    std::string line;
    while (std::getline(in, line)) {
        std::stringstream stream(line);

        std::string token;
        std::vector<std::string> split;

        while (getline(stream, token, ',')) {
            split.push_back(token);
        }

        if (split.size() == 4) {
            std::string title = split[0];
            std::string author = split[1];
            std::string genre = split[2];
            int year = stoi(split[3]);

            Library::addBook({title, author, genre, year});
        }
    }

    in.close();
}

void LibraryFile::writeToFile() {
    std::ofstream out(file_name);

    for (const Book &book : items) {
        out << book.getTitle() << ','
            << book.getAuthor() << ','
            << book.getGenre() << ','
            << book.getYear() << '\n';
    }

    out.close();
}

LibraryFile::LibraryFile(std::string file_name) : Library(), file_name{std::move(file_name)} {
    loadFromFile();
}

void LibraryFile::addBook(const Book &book) {
    Library::addBook(book);
    writeToFile();
}

Book LibraryFile::deleteBook(std::vector<Book>::iterator &position) {
    auto deleted_book = Library::deleteBook(position);
    writeToFile();
    return deleted_book;
}

Book LibraryFile::updateBook(std::vector<Book>::iterator &position, const Book &new_book) {
    auto updated_book = Library::updateBook(position, new_book);
    writeToFile();
    return updated_book;
}

/*
 * SHOPING CART REPOSITORY
 */

void ShoppingCart::addBook(const Book &book) {
    items.push_back(book);
}

void ShoppingCart::deleteAllBooks() {
    items.clear();
}
