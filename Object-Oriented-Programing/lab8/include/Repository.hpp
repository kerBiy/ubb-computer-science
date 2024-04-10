// Created by Alex Balta on 27.03.2024.
//

#pragma once

#include "Vector.hpp"
#include "Book.hpp"
#include <functional>

class Repository {
  private:
    Vector<Book> items; // Vector to store books

  public:
    /**
     * The default constructor.
     */
    Repository() = default;

    /**
     * Retrieves all books stored in the repository.
     * @return vector containing all books
     */
    Vector<Book> &getBooks();

    /**
     * Retrieves the number of books in the repository.
     * @return number of books in the repository
     */
    [[nodiscard]] size_t getLen() const;

    /**
     * Adds a new book to the repository.
     * @param book The book to be added
     */
    void addBook(const Book &book);

    /**
     * Updates information of an existing book in the repository.
     * @param position Iterator pointing to the position of the book to be updated
     * @param new_book The new book information
     */
    void updateBook(Iterator<Book> &position, const Book &new_book);

    /**
     * Deletes a book from the repository.
     * @param position Iterator pointing to the position of the book to be deleted
     */
    void deleteBook(Iterator<Book> &position);

    /**
     * Finds a book by its title.
     * @param title The title of the book to find
     * @return Iterator pointing to the found book or end iterator if not found
     */
    Iterator<Book> findBook(const std::string &title);
};
