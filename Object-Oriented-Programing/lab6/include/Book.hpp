//
// Created by Alex Balta on 26.03.2024.
//

#pragma once

#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string genre;
    int year;

public:
    /*!
     * The default constructor.
     * @param title the title of the book
     * @param author the author of the book
     * @param genre the genre of the book
     * @param year the year of the book
     */
    Book(std::string title, std::string author, std::string genre, int year);

    /*!
     * The default destructor.
     */
    ~Book() = default;

    /*!
     * Converts the book into a string
     * @return a string with all the proprieties of a book
     */
    [[nodiscard]] std::string intoString() const;

    /*!
     * Getter for the title
     * @return the title of the book
     */
    [[nodiscard]] std::string getTitle() const;

    /*!
     * Getter for the author
     * @return the author of the book
     */
    [[nodiscard]] std::string getAuthor() const;

    /*!
     * Getter for the genre
     * @return the genre of the book
     */
    [[nodiscard]] std::string getGenre() const;

    /*!
     * Getter for the year
     * @return the year of the book
     */
    [[nodiscard]] int getYear() const;

    /*!
     * Setter for the title
     * @param new_title the new title of the book
     */
    void setTitle(const std::string &new_title);

    /*!
     * Setter for the author
     * @param new_author the new author of the book
     */
    void setAuthor(const std::string &new_author);

    /*!
     * Setter for the genre
     * @param new_genre the new genre of the book
     */
    void setGenre(const std::string &new_genre);

    /*!
     * Setter for the year
     * @param new_year the new year of the book
     */
    void setYear(int new_year);
};

