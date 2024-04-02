// Created by Alex Balta on 27.03.2024.
//

#pragma once

#include "Repository.hpp"

class Service {
private:
    Repository &repo; // Reference to a Repository object

public:
    /*!
     * Constructor for the Service class.
     * @param repo Reference to a Repository object
     */
    explicit Service(Repository &repo);

    /*!
     * The default destructor.
     */
    ~Service() = default;

    /*!
     * Retrieves all books from the repository.
     * @return vector containing all books in the repository
     */
    const std::vector<Book> &getAll();

    /*!
     * Adds a new book to the repository.
     * @param title Title of the book to be added
     * @param author Author of the book to be added
     * @param genre Genre of the book to be added
     * @param year Year of the book to be added
     */
    void addBook(const std::string &title, const std::string &author,
                 const std::string &genre, int year);

    /*!
     * Updates information of an existing book in the repository.
     * @param title Title of the book to be updated
     * @param new_author New author of the book
     * @param new_genre New genre of the book
     * @param new_year New year of the book
     */
    void updateBook(const std::string &title, const std::string &new_author,
                    const std::string &new_genre, int new_year);

    /*!
     * Deletes a book from the repository.
     * @param title Title of the book to be deleted
     */
    void deleteBook(const std::string &title);

    /*!
     * Finds a book from the repository.
     * @param title Title of the book to be deleted
     * @return array of books whose name fits
     */
    std::vector<Book> findBook(const std::string &title);
};
