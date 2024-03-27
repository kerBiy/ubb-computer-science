//
// Created by Alex Balta on 26.03.2024.
//

#include "Book.hpp"
#include <sstream>

Book::Book(std::string title, std::string author, std::string genre, int year)
        : title(std::move(title)), author(std::move(author)), genre(std::move(genre)), year(year) {}

std::string Book::intoString() const {
    std::stringstream string_stream;
    string_stream << title << ", " << author << ", " << genre << ", " << year;
    return string_stream.str();
}

// Getters

std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

std::string Book::getGenre() const {
    return genre;
}

int Book::getYear() const {
    return year;
}

// Setters

void Book::setTitle(const std::string &new_title) {
    this->title = new_title;
}

void Book::setAuthor(const std::string &new_author) {
    this->author = new_author;
}

void Book::setGenre(const std::string &new_genre) {
    this->genre = new_genre;
}

void Book::setYear(int new_year) {
    this->year = new_year;
}