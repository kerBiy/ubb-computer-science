//
// Created by Alex Balta on 21.05.2024.
//

#include "Test.hpp"
#include "Service.hpp"

#include <iostream>
#include <fstream>
#include <cassert>

Test::Test() {
    id1 = 1;
    name1 = "Rochie 1";
    size1 = "L";
    price1 = 100;
    valid1 = true;
}

void Test::testDomain() {
    std::cout << "Domain tests started\n";

    Dress d1(id1, name1, size1, price1, valid1);
    assert(d1.getId() == id1);
    assert(d1.getName() == name1);
    assert(d1.getSize() == size1);
    assert(d1.getPrice() == price1);
    assert(d1.getValid() == valid1);

    std::cout << "Domain tests ran successfully\n";
}

void Test::testRepository() {
    std::cout << "Repo tests started\n";

    Repository repo("test.txt");
    assert(repo.getAll().size() == 5);

    std::cout << "Repo tests ran successfully\n";
}

void Test::testService() {
    std::cout << "Service tests started\n";

    Repository repo("test.txt");
    Service service(repo);

    assert(service.getAll().size() == 5);
    assert(service.getLen() == 5);

    auto sorted_list = service.sortBySize();
    assert(sorted_list.size() == 5);

    sorted_list = service.sortByPrice();
    assert(sorted_list.size() == 5);

    std::cout << "Service tests ran successfully\n";
}

void Test::testAll() {
    std::cout << "All tests started\n";

    testDomain();
    testRepository();

    std::cout << "All tests ran successfully\n";
}
