//
// Created by Alex Balta on 27.03.2024.
//
#include "Console.hpp"
#include <iostream>

Console::Console(Service &service) : service(service) {}

void Console::printMenu() {
    std::cout << "\nOPTION MENU\n"
              << "Enter 1 for adding a book.\n"
              << "Enter 2 for updating a book.\n"
              << "Enter 3 for deleting a book.\n"
              << "Enter 4 for finding books.\n"
              << "Enter 5 for filtering books.\n"
              << "Enter 6 for sorting books.\n"
              << "Enter c for the shopping cart menu.\n"
              << "Enter p for printing the book list.\n"
              << "Enter q for exiting the app.\n";
}

void Console::uiPrintBooks() {
    auto &all_books = service.getAllLib();

    if (all_books.empty()) {
        std::cout << "There are no books in the library.\n";
        return;
    }

    std::cout << "The books are:\n";
    for (const Book &book : all_books) {
        std::cout << book.intoString() << "\n";
    }
}

void Console::uiAddBook() {
    std::string title, author, genre;
    int year{0};

    try {
        std::cout << "Enter the title: ";
        std::getline(std::cin, title);

        std::cout << "Enter the author: ";
        std::getline(std::cin, author);

        std::cout << "Enter the genre: ";
        std::getline(std::cin, genre);

        std::cout << "Enter the year: ";
        std::cin >> year;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw std::runtime_error("Invalid input for year.");
        }

        service.addBookLib(title, author, genre, year);
        std::cout << "The book was added.\n";
    } catch (const std::exception &e) {
        throw std::runtime_error("Error adding book: " + std::string(e.what()));
    }
}

void Console::uiUpdateBook() {
    std::string title, newTitle, author, genre;
    int year{0};

    try {
        std::cout << "Enter the title of the book you want to update: ";
        std::getline(std::cin, title);

        std::cout << "\nEnter the new information:\n";

        std::cout << "Enter the author: ";
        std::getline(std::cin, author);

        std::cout << "Enter the genre: ";
        std::getline(std::cin, genre);

        std::cout << "Enter the year: ";
        std::cin >> year;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw std::runtime_error("Invalid input for year.");
        }

        service.updateBookLib(title, author, genre, year);
        std::cout << "The book was updated.\n";
    } catch (const std::exception &e) {
        throw std::runtime_error("Error updating book: " + std::string(e.what()));
    }
}

void Console::uiDeleteBook() {
    std::string title;

    try {
        std::cout << "Enter the title of the book you want to delete: ";
        std::getline(std::cin, title);

        service.deleteBookLib(title);
        std::cout << "The book was deleted\n";
    } catch (const std::exception &e) {
        throw std::runtime_error("Error deleting book: " + std::string(e.what()));
    }
}

void Console::uiFindBooks() {
    std::string title;

    try {
        std::cout << "Enter the title of the book you want to find: ";
        std::getline(std::cin, title);

        auto found_books = service.findBooksLib(title);

        if (found_books.empty()) {
            std::cout << "There are no books that fit the description.\n";
            return;
        }

        std::cout << "The found books are:\n";
        for (const Book &book : found_books) {
            std::cout << book.intoString() << "\n";
        }
    } catch (const std::exception &e) {
        throw std::runtime_error("Error finding book: " + std::string(e.what()));
    }
}

void Console::uiFilterBooks() {
    int year{0};

    try {
        std::cout << "Enter the year: ";
        std::cin >> year;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw std::runtime_error("Invalid input for year.");
        }

        auto filtered_books = service.filterBooksLib(year);

        if (filtered_books.empty()) {
            std::cout << "There are no books published after " << year << ".\n";
            return;
        }

        std::cout << "The filtered books are:\n";
        for (const Book &book : filtered_books) {
            std::cout << book.intoString() << "\n";
        }
    } catch (const std::exception &e) {
        throw std::runtime_error("Error filtering books: " + std::string(e.what()));
    }
}

void Console::uiSortBooks() {
    try {
        auto sorted_books = service.sortBooksLib([&](const Book &b1, const Book &b2) {
            return b1.getYear() < b2.getYear();
        });

        if (sorted_books.empty()) {
            std::cout << "There are no books to sort.\n";
            return;
        }

        std::cout << "The sorted books are:\n";
        for (const Book &book : sorted_books) {
            std::cout << book.intoString() << "\n";
        }
    } catch (const std::exception &e) {
        throw std::runtime_error("Error sorting books: " + std::string(e.what()));
    }
}

char Console::getUserInput() {
    char option{};

    while (true) {
        std::cout << "\n>>> ";
        std::cin >> option;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Invalid input. Please enter a single character.\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return option;
        }
    }
}

void Console::run() {
    while (true) {
        printMenu();

        try {
            char option = getUserInput();

            switch (option) {
                case '1': {
                    uiAddBook();
                    break;
                }
                case '2': {
                    uiUpdateBook();
                    break;
                }
                case '3': {
                    uiDeleteBook();
                    break;
                }
                case '4': {
                    uiFindBooks();
                    break;
                }
                case '5': {
                    uiFilterBooks();
                    break;
                }
                case '6': {
                    uiSortBooks();
                    break;
                }
                case 'c': {
                    uiShoppingCartMenu();
                    break;
                }
                case 'p': {
                    uiPrintBooks();
                    break;
                }
                case 'q': {
                    std::cout << "Exiting the app...";
                    return;
                }
                default: {
                    std::cout << "The option was not yet implemented.\n";
                }
            }

        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
}

/**
 * SHOPPING CART
 */

void Console::printShoppingCartMenu() {
    std::cout << "\nSHOPPING CART MENU\n"
              << "Enter 1 for adding an book to your shopping cart.\n"
              << "Enter 2 for deleting all the items in your shopping cart\n"
              << "Enter 3 for populating shopping cart with random books\n"
              << "Enter p for viewing your shopping cart.\n"
              << "Enter q to exit this menu.\n";
}

void Console::uiPrintShoppingCart() {
    auto &all_cart = service.getShoppingCart();

    if (all_cart.empty()) {
        std::cout << "There are no books in the shopping cart.\n";
        return;
    }

    std::cout << "The books are:\n";
    for (const Book &book : all_cart) {
        std::cout << book.intoString() << "\n";
    }
}

void Console::uiAddToShoppingCart() {
    std::string title;

    try {
        std::cout << "Enter the title of the book you want to add in the shopping cart: ";
        std::getline(std::cin, title);

        service.addBookCart(title);
        std::cout << "The book was added in the shopping cart\n";
    } catch (const std::exception &e) {
        throw std::runtime_error("Error adding shopping cart: " + std::string(e.what()));
    }
}

void Console::uiDeleteShoppingCart() {
    try {
        service.deleteCart();
        std::cout << "The books from the shopping cart were deleted.\n";
    } catch (const std::exception &e) {
        throw std::runtime_error("Error adding shopping cart: " + std::string(e.what()));
    }
}

void Console::uiPopulateShoppingCart() {
    size_t book_count{0};

    try {
        std::cout << "Enter the number of books you want to add random: ";
        std::cin >> book_count;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw std::runtime_error("Invalid input for year.");
        }

        service.populateRandomCart(book_count);
        std::cout << "The book was added in the shopping cart\n";
    } catch (const std::exception &e) {
        throw std::runtime_error("Error adding shopping cart: " + std::string(e.what()));
    }
}

void Console::uiShoppingCartMenu() {
    printShoppingCartMenu();

    try {
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

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

}
