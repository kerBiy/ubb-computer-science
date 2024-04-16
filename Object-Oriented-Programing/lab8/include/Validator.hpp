//
// Created by Alex Balta on 05.04.2024.
//

#pragma once

#include <string>
#include "Book.hpp"

#include <stdexcept>

class ValidatorError : public std::runtime_error {
  public:
    explicit ValidatorError(const std::string &message) : std::runtime_error(message) {}
};

class Validator {
  private:
    /**
     * Checks if a given name is valid.
     * @param name The name to be validated.
     * @return True if the name is valid, otherwise false.
     */
    static bool isValidName(const std::string &name);

    /**
     * Checks if a given genre is valid.
     * @param genre The genre to be validated.
     * @return True if the genre is valid, otherwise false.
     */
    static bool isValidGenre(const std::string &genre);

    /**
     * Checks if a given year is valid.
     * @param year The year to be validated.
     * @return True if the year is valid, otherwise false.
     */
    static bool isValidYear(int year);

  public:
    /**
     * Validates a book object.
     * @param book The book object to be validated.
     * @throws ValidatorError if the book object is not valid.
     */
    static void validateBook(const Book &book);
};
