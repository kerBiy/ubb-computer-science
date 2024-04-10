//
// Created by Alex Balta on 05.04.2024.
//

#include "Validator.hpp"
#include "Vector.hpp"

const int CURRENT_YEAR = 2024;

bool Validator::isValidName(const std::string &name) {
    return isupper(name[0]);
}

bool Validator::isValidGenre(const std::string &genre) {
    Vector<std::string> valid_genres;
    valid_genres.push_back("crime");
    valid_genres.push_back("self-help");
    valid_genres.push_back("literature");
    valid_genres.push_back("roman");

    bool found{false};
    for (const std::string &valid_genre : valid_genres) {
        if (genre == valid_genre) {
            found = true;
        }
    }

    return found;
}

bool Validator::isValidYear(int year) {
    return 0 <= year && year <= CURRENT_YEAR;
}

void Validator::validateBook(const Book &book) {
    std::string error;

    if (!isValidName(book.getTitle())) {
        error.append("\nThe title is not valid.");
    }
    if (!isValidName(book.getAuthor())) {
        error.append("\nThe author is not valid.");
    }
    if (!isValidGenre(book.getGenre())) {
        error.append("\nThe genre is not valid.");
    }
    if (!isValidYear(book.getYear())) {
        error.append("\nThe year is not valid.");
    }

    if (!error.empty()) {
        throw std::runtime_error(error);
    }
}


