#include <iostream>

#include "TestScurt.h"
#include "TestExtins.h"
#include "TestScurtList.h"
#include "TestExtinsList.h"

int main() {
    testAllList();
    testAllExtinsList();
    std::cout << "List tests ran successfully.\n";


    testAll();
    testAllExtins();
    std::cout << "Dict tests ran successfully.\n";

    std::cout << "All tests ran successfully.\n";
    return 0;
}