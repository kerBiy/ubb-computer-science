//
// Created by Alex Balta on 20.05.2024.
//

#include "Test.hpp"

#include <iostream>
#include <fstream>
#include <cassert>

Test::Test() {
    id1 = 1;
    description1 = "A fullstack e-comers app.";
    programmer1.push_back("Alex");
    programmer1.push_back("Iustin");
    programmer1.push_back("David");
    status1 = "inprogress";

    id2 = 2;
    description2 = "A frontend social media app.";
    programmer2.push_back("Darius");
    programmer2.push_back("Ciprian");
    programmer2.push_back("Alex");
    status2 = "closed";
}

void Test::testDomain() {
    std::cout << "Domain tests started\n";

    Task t1(id1, description1, programmer1, status1);

    assert(t1.getId() == id1);
    assert(t1.getDescription() == description1);
    assert(t1.getProgrammers() == programmer1);
    assert(t1.getStatus() == status1);

    std::cout << "Domain tests ran successfully\n";
}

void Test::testRepository() {
    std::cout << "Repository tests started\n";

    Task t1(id1, description1, programmer1, status1);
    Task t2(id2, description2, programmer2, status2);

    std::ofstream out("test.txt");
    out.close();

    Repository repo("test.txt");

    repo.addTask(t1);
    assert(repo.findTask(id1) == true);

    assert(repo.findTask(id2) == false);
    repo.addTask(t2);

    assert(repo.getAll().size() == 2);

    Repository repo2("test.txt");
    assert(repo2.getAll().size() == 2);

    try {
        Repository repo3("random_file_name.txt");
    } catch (const std::exception &e) {}

    std::remove("test.txt");
    std::cout << "Repository tests ran successfully\n";
}

void Test::testService() {
    std::cout << "Service tests started\n";

    Task t1(id1, description1, programmer1, status1);

    std::ofstream out("test.txt");
    out.close();

    Repository repo("test.txt");
    repo.addTask(t1);

    Service service(repo);
    assert(service.getAll().size() == 1);
    assert(service.getLen() == 1);

    service.addTask(id2, description2, programmer2, status2);
    assert(repo.getAll().size() == 2);
    assert(service.getLen() == 2);

    try {
        service.addTask(id2, description1, programmer1, status1);
    } catch (const ServiceException &e) {}

    try {
        service.addTask(0, "", {}, "");
    } catch (const ServiceException &e) {}

    try {
        service.addTask(0, description1, programmer1, "random");
    } catch (const ServiceException &e) {}

    auto res = service.searchByProgrammer("Alex");
    assert(res.size() == 2);

    auto res2 = service.searchByProgrammer("David");
    assert(res2.size() == 1);

    auto res3 = service.searchByProgrammer("Nush");
    assert(res3.empty());

    try {
        service.searchByProgrammer("");
    } catch (const ServiceException &e) {}

    std::remove("test.txt");
    std::cout << "Service tests ran successfully\n";
}

void Test::testAll() {
    std::cout << "Testing started...\n";
    testDomain();
    testRepository();
    testService();
    std::cout << "All tests ran successfully\n";
}

