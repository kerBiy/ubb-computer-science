#include "Test.hpp"
#include "Console.hpp"

int main() {
    Test tests;
    tests.runAll();

    LibraryFile lib{"../database/stock.txt"};
    ShoppingCart cart;

    Service service{lib, cart};
    Console ui{service};

    ui.run();

    return 0;
}
