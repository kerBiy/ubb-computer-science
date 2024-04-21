// Created by Alex Balta on 27.03.2024.
//

#pragma once

#include "Undo.hpp"
#include "Validator.hpp"

#include <functional>
#include <unordered_map>

class ServiceError : public std::runtime_error {
  public:
    explicit ServiceError(const std::string &message) : std::runtime_error(message) {}
};

class Service {
  private:
    Library &library; // Reference to a Repository object
    ShoppingCart &shopping_cart; // Reference to a Shopping Cart object

    std::vector<std::unique_ptr<AbstractUndo>> history; // Vector containing all modifications of library

  public:
    /**
     * Constructor for the Service class.
     * @param repo Reference to a Repository object
     */
    Service(Library &lib, ShoppingCart &cart);

    /**
     * Retrieves all books from the library.
     * @return std::vector containing all books in the repository
     */
    std::vector<Book> &getAllLib();

    /**
   * Retrieves all books from the shopping cart.
   * @return std::vector containing all books in the repository
   */
    std::vector<Book> &getShoppingCart();

    /**
     * Adds a new book to the repository.
     * @param title Title of the book to be added
     * @param author Author of the book to be added
     * @param genre Genre of the book to be added
     * @param year Year of the book to be added
     * @throws ServiceError if the new book created is not valid or if the book is already in the list.
     */
    void addBookLib(const std::string &title, const std::string &author,
                    const std::string &genre, int year);

    /**
     * Updates information of an existing book in the repository.
     * @param title Title of the book to be updated
     * @param new_author New author of the book
     * @param new_genre New genre of the book
     * @param new_year New year of the book
     * @throws ServiceError if the new book created is not valid or if the book in not in the list.
     */
    void updateBookLib(const std::string &title, const std::string &new_author,
                       const std::string &new_genre, int new_year);

    /**
     * Deletes a book from the repository.
     * @param title Title of the book to be deleted
     * @throws ServiceError if the book is not on the list.
     */
    void deleteBookLib(const std::string &title);

    /**
     * Finds a book from the repository.
     * @param title Title of the book to be deleted
     * @return array of books whose name fits
     */
    std::vector<Book> findBooksLib(const std::string &title);

    /**
     * Filters all books from the repository by year.
     * @param min_year the year you want to filter by
     * @return array of books whose year is greater than min_year
     */
    std::vector<Book> filterBooksLib(int min_year);

    /**
     * Sorts all books from the repository.
     * @param title Title of the book to be deleted
     * @return array of books whose name fits
     */
    std::vector<Book> sortBooksLib(const std::function<bool(const Book &, const Book &)> &compare);

    /**
     * Adds a new book to the shopping cart.
     * @param title Title of the book to be added.
     * @throws ServiceError if the book is not in the library with this title.
     */
    void addBookCart(const std::string &title);

    /**
    * Deletes the entire shopping cart.
    * @throws ServiceError if there are not books in the cart.
    */
    void deleteCart();

    /**
     * Populates the repository with random books.
     * @param book_count the number of random books to add.
     * @throws ServiceError if there are not books in the library.
     */
    void populateRandomCart(size_t book_count);

    void exportHTML(const std::string &file_name);

    /**
    * Generates a report containing the number of books per genre.
    * @return An unordered map with genre as key and count as value.
    */
    std::unordered_map<std::string, int> getRaport();

    /**
     * Undo the last action performed.
     * @throws ServiceError if there are no actions to undo.
     */
    void undo();
};
