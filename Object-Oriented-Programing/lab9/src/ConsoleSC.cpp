//
// Created by Alex Balta on 20.04.2024.
//

#include "Console.hpp"
#include <iostream>

void Console::printShoppingCartMenu() {
    std::cout << "\nSHOPPING CART MENU\n"
              << "Enter 1 for adding an book to your shopping cart.\n"
              << "Enter 2 for deleting all the items in your shopping cart\n"
              << "Enter 3 for populating shopping cart with random books\n"
              << "Enter 4 for exporting all the books in a html page\n"
              << "Enter p for viewing your shopping cart.\n"
              << "Enter q to exit this menu.\n";
}

void Console::uiPrintShoppingCart() {
    auto &all_cart = service.getShoppingCart();

    if (all_cart.empty()) {
        throw UiError("There are no books in the shopping cart.");
    }

    std::cout << "The books are:\n";
    for (const Book &book : all_cart) {
        std::cout << book.intoString() << "\n";
    }
}

void Console::uiAddToShoppingCart() {
    std::string title;

    std::cout << "Enter the title of the book you want to add in the shopping cart: ";
    std::getline(std::cin, title);

    service.addBookCart(title);
    std::cout << "The book was added in the shopping cart\n";
}

void Console::uiDeleteShoppingCart() {
    service.deleteCart();
    std::cout << "The books from the shopping cart were deleted.\n";
}

void Console::uiPopulateShoppingCart() {
    size_t book_count{0};

    std::cout << "Enter the number of books you want to add random: ";
    std::cin >> book_count;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw UiError("Invalid input for year.");
    }

    service.populateRandomCart(book_count);
    std::cout << "The book was added in the shopping cart\n";
}

void Console::uiExportToHTML() {
    service.exportHTML("../database/export.html");
    std::cout << "The shopping cart was exported successfully.\n";
}

void Console::uiShoppingCartMenu() {
    printShoppingCartMenu();

    char option = getUserInput();

    switch (option) {
        case '1': {
            uiAddToShoppingCart();
            break;
        }
        case '2': {
            uiDeleteShoppingCart();
            break;
        }
        case '3': {
            uiPopulateShoppingCart();
            break;
        }
        case '4': {
            uiExportToHTML();
            break;
        }
        case 'p': {
            uiPrintShoppingCart();
            break;
        }
        case 'q': {
            return;
        }
        default: {
            std::cout << "The option was not yet implemented.\n";
        }
    }
}