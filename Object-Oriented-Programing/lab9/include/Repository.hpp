// Created by Alex Balta on 27.03.2024.
//

#pragma once

#include "Book.hpp"
#include <vector>

class RepositoryError : public std::runtime_error {
  public:
    explicit RepositoryError(const std::string &message) : std::runtime_error(message) {}
};

/*
 * GENERIC REPOSITORY
 */

class GenericRepository {
  protected:
    std::vector<Book> items; // std::vector to store books

  public:
    virtual ~GenericRepository() = default;
    /**
     * The default constructor.
     */
    GenericRepository() = default;

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
};

/*
 * LIBRARY REPOSITORY
 */

class Library : public GenericRepository {
  public:
    /**
    * Adds a new book to the repository.
    * @param book The book to be added.
    */
    virtual void addBook(const Book &book);

    /**
     * Deletes a book from the repository.
     * @param position Iterator pointing to the position of the book to be deleted.
     */
    virtual Book deleteBook(std::vector<Book>::iterator &position);

    /**
     * Updates information of an existing book in the repository.
     * @param position Iterator pointing to the position of the book to be updated.
     * @param new_book The new book information.
     */
    virtual Book updateBook(std::vector<Book>::iterator &position, const Book &new_book);

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
 * LIBRARY FILE REPOSITORY
 */

class LibraryFile : public Library {
  private:
    std::string file_name; // The file where the data is being stored.

    /**
     * Load books from file into the library.
     * @throws RepositoryError if unable to open the file.
     */
    void loadFromFile();

    /**
     * Write library data to file.
     * @throws RepositoryError if unable to open the file.
     */
    void writeToFile();

  public:
    /**
     * Constructor for LibraryFile.
     * @param file_name Name of the file where library data is stored.
     */
    explicit LibraryFile(std::string file_name);

    /**
     * Add a book to the library and write to file.
     * @param book The book to add.
     */
    void addBook(const Book &book) override;

    /**
     * Delete a book from the library and write to file.
     * @param position Iterator pointing to the book to delete.
     * @return The deleted book.
     */
    Book deleteBook(std::vector<Book>::iterator &position) override;

    /**
     * Update a book in the library and write to file.
     * @param position Iterator pointing to the book to update.
     * @param new_book New book information.
     * @return The previous book information.
     */
    Book updateBook(std::vector<Book>::iterator &position, const Book &new_book) override;
};

/*
 * SHOPING CARD REPOSITORY
 */

class ShoppingCart : public GenericRepository {
  public:
    /**
    * Adds a new book to the repository.
    * @param book The book to be added.
    */
    void addBook(const Book &book);

    /**
     * Deletes all books from the repository.
     */
    void deleteAllBooks();
};
