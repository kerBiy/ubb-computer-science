#include "Test.hpp"
#include "Console.hpp"

int main() {
    Test tests;
    tests.runAll();

    Library lib;
    ShoppingCart cart;

    Service service(lib, cart);
    Console ui(service);

    ui.run();

    return 0;
}
