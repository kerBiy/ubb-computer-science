// Created by Alex Balta on 27.03.2024.
//

#pragma once

#include "Book.hpp"
#include <functional>
#include <vector>

/*
 * GENERIC REPOSITORY
 */

class AbstractRepository {
  protected:
    std::vector<Book> items; // std::vector to store books

  public:
    /**
     * The default constructor.
     */
    AbstractRepository() = default;

    /**
     * Retrieves all books stored in the repository.
     * @return std::vector containing all books.
     */
    std::vector<Book> &getBooks();
    /**
     * Retrieves the number of books in the repository.
     * @return number of books in the repository.
     */
    [[nodiscard]] size_t getLen() const;

    /**
     * Adds a new book to the repository.
     * @param book The book to be added.
     */
    void addBook(const Book &book);
};

/*
 * LIBRARY REPOSITORY
 */

class Library : public AbstractRepository {
  public:
    /**
     * Deletes a book from the repository.
     * @param position Iterator pointing to the position of the book to be deleted.
     */
    Book deleteBook(std::vector<Book>::iterator &position);

    /**
     * Updates information of an existing book in the repository.
     * @param position Iterator pointing to the position of the book to be updated.
     * @param new_book The new book information.
     */
    Book updateBook(std::vector<Book>::iterator &position, const Book &new_book);

    /**
     * Finds a book by its title.
     * @param title The title of the book to find.
     * @return Iterator pointing to the found book or end iterator if not found.
     */
    std::vector<Book>::iterator findBook(const std::string &title);

    /**
     * Finds if the iterator is valid.
     * @param iter the iterator you want to check.
     * @return true if the iterator is currently in the list.
     */
    [[nodiscard]] bool isValid(const std::vector<Book>::iterator &iter) const;

};

/*
 * SHOPING CARD REPOSITORY
 */

class ShoppingCart : public AbstractRepository {
  public:
    /**
     * Deletes all books from the repository.
     */
    void deleteAllBooks();
};
