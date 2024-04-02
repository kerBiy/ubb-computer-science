#include <iostream>

#include "TestScurt.h"
#include "TestExtins.h"

int main() {
    testAll();
    testAllExtins();

    std::cout << "All tests ran successfully.\n";
    return 0;
}