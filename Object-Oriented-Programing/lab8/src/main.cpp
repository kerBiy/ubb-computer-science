#include "Test.hpp"
#include "Console.hpp"

int main() {
    Test tests;
    tests.runAll();

    Repository repo;
    Service service(repo);
    Console ui(service);

    ui.run();

    return 0;
}
