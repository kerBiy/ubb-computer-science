// Created by Alex Balta on 27.03.2024.
//

#pragma once

#include "Book.hpp"
#include <vector>
#include <algorithm>

class Repository {
private:
    std::vector<Book> items; // Vector to store books

public:
    /*!
     * The default constructor.
     */
    Repository() = default;

    /*!
     * The default destructor.
     */
    ~Repository() = default;

    /*!
     * Retrieves all books stored in the repository.
     * @return vector containing all books
     */
    const std::vector<Book> &getBooks();

    /*!
     * Retrieves the number of books in the repository.
     * @return number of books in the repository
     */
    size_t getLen();

    /*!
     * Adds a new book to the repository.
     * @param book The book to be added
     */
    void addBook(const Book &book);

    /*!
     * Updates information of an existing book in the repository.
     * @param position Iterator pointing to the position of the book to be updated
     * @param new_book The new book information
     */
    void updateBook(const std::vector<Book>::iterator &position, const Book &new_book);

    /*!
     * Deletes a book from the repository.
     * @param position Iterator pointing to the position of the book to be deleted
     */
    void deleteBook(const std::vector<Book>::iterator &position);

    /*!
     * Finds a book by its title.
     * @param title The title of the book to find
     * @return Iterator pointing to the found book or end iterator if not found
     */
    std::vector<Book>::iterator findBook(const std::string &title);

    /*!
     * Checks if the iterator position is valid (not pointing to end()).
     * @param position Iterator to be validated
     * @return true if the position is valid, false otherwise
     */
    bool isPositionValid(const std::vector<Book>::iterator &position);
};
