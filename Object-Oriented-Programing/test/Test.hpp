//
// Created by Alex Balta on 16.06.2024.
//

#pragma once

#include "Service.hpp"

class Test {
  private:
    int id1;
    std::string description1;
    std::vector<std::string> programmer1;
    std::string status1;

    int id2;
    std::string description2;
    std::vector<std::string> programmer2;
    std::string status2;

    // tests all domain functions
    void testDomain();

    // tests all repo functions
    void testRepository();

    // tests all the service functions
    void testService();
  public:
    // the main constructor
    Test();

    // tests all functions
    void testAll();
};
