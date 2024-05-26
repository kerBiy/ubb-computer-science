#include "TestExtins.h"
#include "TestScurt.h"

#include <iostream>

int main() {
    std::cout << "Tests starting...\n";

    testAll();
    testAllExtins();

    std::cout << "All tests ran successfully\n";
    return 0;
}
