#include <iostream>

#include "TestExtins.h"
#include "TestScurt.h"

//#include "Multime.h"
//#include "IteratorMultime.h"

int main() {
    testAll();
    testAllExtins();

//    Multime mult;
//    mult.adauga(1);
//    mult.adauga(2);
//    mult.adauga(3);
//    mult.adauga(4);
//
//    Multime mult2;
//    mult2.adauga(1);
//    mult2.adauga(5);
//
//    auto newInters = mult.intersection(mult2);
//
//    auto iter = newInters.iterator();
//    while (iter.valid()) {
//        auto e = iter.element();
//        std::cout << e << " ";
//        iter.urmator();
//    }

    std::cout << "All tests ran successfully.\n";
    return 0;
}
