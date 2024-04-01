// Created by Alex Balta on 27.03.2024.
//

#pragma once

#include "Service.hpp"
#include <iostream>

class Console {
private:
    Service &service; // the referece for a service

    /*!
     * Prints the menu options to the console.
     */
    static void printMenu();

    /*!
     * Retrieves user input from the console.
     * @return Character representing user input
     */
    static char getUserInput();

    /*!
     * Displays all books in the library to the console.
     */
    void uiPrintBooks();

    /*!
     * Adds a new book to the library based on user input.
     */
    void uiAddBook();

    /*!
     * Updates information of an existing book based on user input.
     */
    void uiUpdateBook();

    /*!
     * Deletes a book from the library based on user input.
     */
    void uiDeleteBook();

public:
    /*!
     * Constructor for the Console class.
     * @param service Reference to a Service object
     */
    explicit Console(Service &service);

    /*!
     * Destructor for the Console class.
     */
    ~Console() = default;

    /*!
     * Runs the console application, displaying the menu and handling user input.
     */
    void run();
};
