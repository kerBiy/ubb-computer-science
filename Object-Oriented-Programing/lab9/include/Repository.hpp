// Created by Alex Balta on 27.03.2024.
//

#pragma once

#include "Book.hpp"

#include <vector>
#include <unordered_map>

class RepositoryError : public std::runtime_error {
  public:
    explicit RepositoryError(const std::string &message) : std::runtime_error(message) {}
};

/*
 * ABSTRACT REPOSITORY
 */

class AbstractLibrary {
  public:
    /**
    * The default constructor.
    */
    AbstractLibrary() = default;

    /**
     * The default destructor.
     */
    virtual ~AbstractLibrary() = default;

    /**
     * Retrieves all books stored in the repository.
     * @return std::vector containing all books.
     */
    virtual std::vector<Book> getBooks() = 0;
    /**
     * Retrieves the number of books in the repository.
     * @return number of books in the repository.
     */
    [[nodiscard]] virtual size_t getLen() const = 0;

    /**
    * Adds a new book to the repository.
    * @param book The book to be added.
    */
    virtual void addBook(const Book &book) = 0;

    /**
     * Deletes a book from the repository.
     * @param position Iterator pointing to the position of the book to be deleted.
     */
    virtual Book deleteBook(const std::string &title) = 0;

    /**
     * Updates information of an existing book in the repository.
     * @param position Iterator pointing to the position of the book to be updated.
     * @param new_book The new book information.
     */
    virtual Book updateBook(const std::string &title, const Book &new_book) = 0;

    /**
     * Finds a book by its title.
     * @param title The title of the book to find.
     * @return Iterator pointing to the found book or end iterator if not found.
     */
    virtual bool findBook(const std::string &title) = 0;
};

/*
 * LIBRARY REPOSITORY
 */

class LibraryVector : public AbstractLibrary {
  protected:
    std::vector<Book> items; // std::vector to store books

  public:
    ~LibraryVector() override = default;
    /**
     * Retrieves all books stored in the repository.
     * @return std::vector containing all books.
     */
    std::vector<Book> getBooks() override;
    /**
     * Retrieves the number of books in the repository.
     * @return number of books in the repository.
     */
    [[nodiscard]] size_t getLen() const override;

    /**
    * Adds a new book to the repository.
    * @param book The book to be added.
    */
    void addBook(const Book &book) override;

    /**
     * Deletes a book from the repository.
     * @param position Iterator pointing to the position of the book to be deleted.
     */
    Book deleteBook(const std::string &title) override;

    /**
     * Updates information of an existing book in the repository.
     * @param position Iterator pointing to the position of the book to be updated.
     * @param new_book The new book information.
     */
    Book updateBook(const std::string &title, const Book &new_book) override;

    /**
     * Finds a book by its title.
     * @param title The title of the book to find.
     * @return Iterator pointing to the found book or end iterator if not found.
     */
    bool findBook(const std::string &title) override;
};

/*
 * LIBRARY DICT
 */

class LibraryDict : public AbstractLibrary {
  private:
    std::unordered_map<std::string, Book> items; // std::map to store books
    double probability;

  public:
    LibraryDict();
    ~LibraryDict() override = default;
    /**
     * Retrieves all books stored in the repository.
     * @return std::vector containing all books.
     */
    std::vector<Book> getBooks() override;
    /**
     * Retrieves the number of books in the repository.
     * @return number of books in the repository.
     */
    [[nodiscard]] size_t getLen() const override;

    /**
    * Adds a new book to the repository.
    * @param book The book to be added.
    */
    void addBook(const Book &book) override;

    /**
     * Deletes a book from the repository.
     * @param position Iterator pointing to the position of the book to be deleted.
     */
    Book deleteBook(const std::string &title) override;

    /**
     * Updates information of an existing book in the repository.
     * @param position Iterator pointing to the position of the book to be updated.
     * @param new_book The new book information.
     */
    Book updateBook(const std::string &title, const Book &new_book) override;

    /**
     * Finds a book by its title.
     * @param title The title of the book to find.
     * @return Iterator pointing to the found book or end iterator if not found.
     */
    bool findBook(const std::string &title) override;
};

/*
 * LIBRARY FILE REPOSITORY
 */

class LibraryFile : public LibraryVector {
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
    Book deleteBook(const std::string &title) override;

    /**
     * Update a book in the library and write to file.
     * @param position Iterator pointing to the book to update.
     * @param new_book New book information.
     * @return The previous book information.
     */
    Book updateBook(const std::string &title, const Book &new_book) override;
};

/*
 * SHOPING CARD REPOSITORY
 */

class ShoppingCart {
  private:
    std::vector<Book> items; // std::vector to store books

  public:
    /**
     * The default constructor.
     */
    ShoppingCart() = default;

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

    /**
     * Deletes all books from the repository.
     */
    void deleteAllBooks();
};
