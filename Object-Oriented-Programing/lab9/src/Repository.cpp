//
// Created by Alex Balta on 27.03.2024.
//

#include "Repository.hpp"

#include <fstream>
#include <utility>
#include <sstream>
#include <algorithm>
#include <random>

/*
 * LIBRARY REPOSITORY
 */

std::vector<Book> LibraryVector::getBooks() {
    return items;
}

size_t LibraryVector::getLen() const {
    return items.size();
}

void LibraryVector::addBook(const Book &book) {
    items.push_back(book);
}

Book LibraryVector::deleteBook(const std::string &title) {
    auto it = std::find_if(items.begin(), items.end(), [&title](const Book &book) {
        return book.getTitle() == title;
    });

    Book deleted_book = *it;
    items.erase(it);
    return deleted_book;
}

Book LibraryVector::updateBook(const std::string &title, const Book &new_book) {
    auto it = std::find_if(items.begin(), items.end(), [&title](const Book &book) {
        return book.getTitle() == title;
    });

    Book previous_book = *it;
    *it = new_book;
    return previous_book;
}

bool LibraryVector::findBook(const std::string &title) {
    auto it = std::find_if(items.begin(), items.end(), [&title](const Book &book) {
        return book.getTitle() == title;
    });

    return it != items.end();
}

/*
 * LIBRARY DICT
 */

LibraryDict::LibraryDict() : probability{0.2} {
}

std::vector<Book> LibraryDict::getBooks() {
    std::mt19937 gen(std::random_device{}());
    std::uniform_real_distribution<> distribution(0, 1);

    double random_number = distribution(gen);
    if (random_number < probability) {
        throw RepositoryError("The random prob is " + std::to_string(random_number));
    }

    std::vector<Book> output;

    for (const auto &book : items) {
        output.push_back(book.second);
    }

    return output;
}

size_t LibraryDict::getLen() const {
    std::mt19937 gen(std::random_device{}());
    std::uniform_real_distribution<> distribution(0, 1);

    double random_number = distribution(gen);
    if (random_number < probability) {
        throw RepositoryError("The random prob is " + std::to_string(random_number));
    }
    return items.size();
}

void LibraryDict::addBook(const Book &book) {
    std::mt19937 gen(std::random_device{}());
    std::uniform_real_distribution<> distribution(0, 1);

    double random_number = distribution(gen);
    if (random_number < probability) {
        throw RepositoryError("The random prob is " + std::to_string(random_number));
    }
    items[book.getTitle()] = book;
}

Book LibraryDict::deleteBook(const std::string &title) {
    std::mt19937 gen(std::random_device{}());
    std::uniform_real_distribution<> distribution(0, 1);

    double random_number = distribution(gen);
    if (random_number < probability) {
        throw RepositoryError("The random prob is " + std::to_string(random_number));
    }
    auto it = items.find(title);

    Book deleted_book = it->second;
    items.erase(it);
    return deleted_book;
}

Book LibraryDict::updateBook(const std::string &title, const Book &new_book) {
    std::mt19937 gen(std::random_device{}());
    std::uniform_real_distribution<> distribution(0, 1);

    double random_number = distribution(gen);
    if (random_number < probability) {
        throw RepositoryError("The random prob is " + std::to_string(random_number));
    }
    auto it = items.find(title);

    Book previous_book = it->second;
    it->second = new_book;
    return previous_book;
}

bool LibraryDict::findBook(const std::string &title) {
    std::mt19937 gen(std::random_device{}());
    std::uniform_real_distribution<> distribution(0, 1);

    double random_number = distribution(gen);
    if (random_number < probability) {
        throw RepositoryError("The random prob is " + std::to_string(random_number));
    }
    return items.find(title) != items.end();
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

            LibraryVector::addBook({title, author, genre, year});
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

LibraryFile::LibraryFile(std::string file_name) : LibraryVector(), file_name{std::move(file_name)} {
    loadFromFile();
}

void LibraryFile::addBook(const Book &book) {
    LibraryVector::addBook(book);
    writeToFile();
}

Book LibraryFile::deleteBook(const std::string &title) {
    auto deleted_book = LibraryVector::deleteBook(title);
    writeToFile();
    return deleted_book;
}

Book LibraryFile::updateBook(const std::string &title, const Book &new_book) {
    auto updated_book = LibraryVector::updateBook(title, new_book);
    writeToFile();
    return updated_book;
}

/*
 * SHOPING CART REPOSITORY
 */

std::vector<Book> &ShoppingCart::getBooks() {
    return items;
}

size_t ShoppingCart::getLen() const {
    return items.size();
}

void ShoppingCart::addBook(const Book &book) {
    items.push_back(book);
}

void ShoppingCart::deleteAllBooks() {
    items.clear();
}
