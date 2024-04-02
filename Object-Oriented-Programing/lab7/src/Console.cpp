//
// Created by Alex Balta on 27.03.2024.
//

#include "Console.hpp"
#include <iostream>

Console::Console(Service &service) : service(service) {}

void Console::printMenu() {
    std::cout << "\nOPTION MENU\n";
    std::cout << "Enter 1 for adding a book.\n";
    std::cout << "Enter 2 for updating a book.\n";
    std::cout << "Enter 3 for deleting a book.\n";
    std::cout << "Enter 4 for finding a book.\n";
    std::cout << "Enter p for printing the book list.\n";
    std::cout << "Enter q for exiting the app.\n";
}

void Console::uiPrintBooks() {
    auto &all_books = service.getAll();

    if (all_books.size() == 0) {
        std::cout << "There are no books in the library.\n";
        return;
    }

    std::cout << "The books are:\n";
    for (const Book &book: all_books) {
        std::cout << book.intoString() << "\n";
    }
}

void Console::uiAddBook() {
    std::string title, author, genre;
    int year;

    std::cout << "Enter the title: ";
    std::cin.ignore();
    std::getline(std::cin, title);

    std::cout << "Enter the author: ";
    std::getline(std::cin, author);

    std::cout << "Enter the genre: ";
    std::getline(std::cin, genre);

    std::cout << "Enter the year: ";
    std::cin >> year;

    service.addBook(title, author, genre, year);
    std::cout << "The book was added.\n";
}

void Console::uiUpdateBook() {
    std::string title, newTitle, author, genre;
    int year;

    std::cout << "Enter the title of the book you want to update: ";
    std::cin.ignore();
    std::getline(std::cin, title);

    std::cout << "\nEnter the new information:\n";

    std::cout << "Enter the author: ";
    std::getline(std::cin, author);

    std::cout << "Enter the genre: ";
    std::getline(std::cin, genre);

    std::cout << "Enter the year: ";
    std::cin >> year;

    service.updateBook(title, author, genre, year);
    std::cout << "The book was updated.\n";
}

void Console::uiDeleteBook() {
    std::string title;

    std::cout << "Enter the title of the book you want to delete: ";
    std::cin.ignore();
    std::getline(std::cin, title);

    service.deleteBook(title);
    std::cout << "The book was deleted\n";
}

void Console::uiFindBook() {
    std::string title;

    std::cout << "Enter the title of the book you want to find: ";
    std::cin.ignore();
    std::getline(std::cin, title);

    auto found_books = service.findBook(title);

    if (found_books.size() == 0) {
        std::cout << "There are no books that fit the description.\n";
        return;
    }

    std::cout << "The found books are:\n";
    for (const Book &book: found_books) {
        std::cout << book.intoString() << "\n";
    }
}

char Console::getUserInput() {
    char option;
    std::cout << "\n>>> ";
    std::cin >> option;

    std::cout << "\n";
    return option;
}

void Console::run() {
    while (true) {
        printMenu();
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
                uiFindBook();
                break;
            }
            case 'p' : {
                uiPrintBooks();
                break;
            }
            case 'q' : {
                std::cout << "Exiting the app...";
                exit(0);
            }

            default: {
                std::cout << "The option was not yet implemented.\n";
            }

        }
    }
}