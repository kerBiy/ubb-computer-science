// Created by Alex Balta on 27.03.2024.
//

#pragma once

#include "Service.hpp"

class Console {
  private:
    Service &service; // Reference to a Service object

    /**
     * Prints the menu options to the console.
     */
    static void printMenu();

    /**
    * Prints the shopping cart menu options to the console.
    */
    static void printShoppingCartMenu();

    /**
     * Retrieves user input from the console.
     * @return Character representing user input
     */
    static char getUserInput();

    /**
     * Displays all books in the library to the console.
     */
    void uiPrintBooks();

    /**
     * Adds a new book to the library based on user input.
     */
    void uiAddBook();

    /**
     * Updates information of an existing book based on user input.
     */
    void uiUpdateBook();

    /**
     * Deletes a book from the library based on user input.
     */
    void uiDeleteBook();

    /**
   * Finds a book from the library based on user input.
   */
    void uiFindBooks();

    /**
     * Filters books from the library based on user input.
     */
    void uiFilterBooks();

    /**
     * Sorts books from the library based on user input.
     */
    void uiSortBooks();

    /*
     * Shopping Cart ui
     */

    /*
     * Main menu for shopping cart actions .
     */
    void uiShoppingCartMenu();

    /*
     * Prints all the books in the shopping cart based on user input.
     */
    void uiPrintShoppingCart();

    /*
     * Adds book to shopping cart based on user input.
     */
    void uiAddToShoppingCart();

    /*
     * Deletes a book from the shopping cart based on user input.
     */
    void uiDeleteShoppingCart();

    /*
     * Populates the shopping cart with random books based on user input.
     */
    void uiPopulateShoppingCart();

  public:
    /**
     * Constructor for the Console class.
     * @param service Reference to a Service object
     */
    explicit Console(Service &service);

    /**
     * Runs the console application, displaying the menu and handling user input.
     */
    void run();

};
