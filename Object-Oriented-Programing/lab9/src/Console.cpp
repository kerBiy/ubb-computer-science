//
// Created by Alex Balta on 27.03.2024.
//
#include "Console.hpp"
#include <iostream>

Console::Console(Service &service) : service{service} {}

void Console::printMenu() {
    std::cout << "\nOPTION MENU\n"
              << "Enter 1 for adding a book.\n"
              << "Enter 2 for updating a book.\n"
              << "Enter 3 for deleting a book.\n"
              << "Enter 4 for finding books.\n"
              << "Enter 5 for filtering books.\n"
              << "Enter 6 for sorting books.\n"
              << "Enter 7 for a report of books by genre.\n"
              << "Enter c for the shopping cart menu.\n"
              << "Enter p for printing the book list.\n"
              << "Enter z for undoing the last operation.\n"
              << "Enter q for exiting the app.\n";
}

void Console::uiPrintBooks() {
    auto &all_books = service.getAllLib();

    if (all_books.empty()) {
        throw UiError("There are no books in the library.");
    }

    std::cout << "The books are:\n";
    for (const Book &book : all_books) {
        std::cout << book.intoString() << "\n";
    }
}

void Console::uiAddBook() {
    std::string title, author, genre;
    int year{0};

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
        throw UiError("Invalid input for year.");
    }

    service.addBookLib(title, author, genre, year);
    std::cout << "The book was added.\n";
}

void Console::uiUpdateBook() {
    std::string title, new_author, new_genre;
    int new_year{0};

    std::cout << "Enter the title of the book you want to update: ";
    std::getline(std::cin, title);

    std::cout << "\nEnter the new information:\n";

    std::cout << "Enter the new author: ";
    std::getline(std::cin, new_author);

    std::cout << "Enter the new genre: ";
    std::getline(std::cin, new_genre);

    std::cout << "Enter the new year: ";
    std::cin >> new_year;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw UiError("Invalid input for year.");
    }

    service.updateBookLib(title, new_author, new_genre, new_year);
    std::cout << "The book was updated.\n";

}

void Console::uiDeleteBook() {
    std::string title;

    std::cout << "Enter the title of the book you want to delete: ";
    std::getline(std::cin, title);

    service.deleteBookLib(title);
    std::cout << "The book was deleted\n";
}

void Console::uiFindBooks() {
    std::string title;

    std::cout << "Enter the title of the book you want to find: ";
    std::getline(std::cin, title);

    auto found_books = service.findBooksLib(title);

    if (found_books.empty()) {
        throw UiError("There are no books that fit the description.");
    }

    std::cout << "The found books are:\n";
    for (const Book &book : found_books) {
        std::cout << book.intoString() << "\n";
    }
}

void Console::uiFilterBooks() {
    int year{0};

    std::cout << "Enter the year: ";
    std::cin >> year;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw UiError("Invalid input for year.");
    }

    auto filtered_books = service.filterBooksLib(year);

    if (filtered_books.empty()) {
        throw UiError("There are no books published after " + std::to_string(year));
    }

    std::cout << "The filtered books are:\n";
    for (const Book &book : filtered_books) {
        std::cout << book.intoString() << "\n";
    }
}

void Console::uiSortBooks() {
    auto sorted_books = service.sortBooksLib([](const Book &b1, const Book &b2) {
        return b1.getYear() < b2.getYear();
    });

    if (sorted_books.empty()) {
        throw UiError("There are no books to sort.");
    }

    std::cout << "The sorted books are:\n";
    for (const Book &book : sorted_books) {
        std::cout << book.intoString() << "\n";
    }
}

void Console::uiShowRaport() {
    auto raport = service.getRaport();

    if (raport.empty()) {
        throw UiError("There are no books in the library.");
    }

    std::cout << "The genre, count pairs are:\n";
    for (const auto &x : raport) {
        std::cout << "The genre " << x.first << " has " << x.second << " books\n";
    }
}

void Console::uiUndo() {
    service.undo();
    std::cout << "Undoing the last action...\n";
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
        } else if (std::cin.peek() != '\n') {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Invalid input. Please enter only one character.\n";
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
                case '7': {
                    uiShowRaport();
                    break;
                }
                case 'c': {
                    uiShoppingCartMenu();
                    break;
                }
                case 'z': {
                    uiUndo();
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

        } catch (const RepositoryError &re) {
            std::cerr << "Repository Error: " << re.what() << std::endl;
        } catch (const ValidatorError &ve) {
            std::cerr << "Validation Error: " << ve.what() << std::endl;
        } catch (const ServiceError &se) {
            std::cerr << "Service Error: " << se.what() << std::endl;
        } catch (const UiError &ue) {
            std::cerr << "Ui Error: " << ue.what() << std::endl;
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
}
