//
// Created by Alex Balta on 27.03.2024.
//

#pragma once

#include "Service.hpp"

class Console {
private:
    Service service;

    static void printMenu();

    static char getUserInput();

    void uiPrintBooks();

    void uiAddBook();

    void uiUpdateBook();

    void uiDeleteBook();

public:
    Console(Service &service);

    ~Console() = default;

    void run();
};
