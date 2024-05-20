//
// Created by Alex Balta on 20.05.2024.
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

    void testDomain();
    void testRepository();
    void testService();
  public:
    Test();
    void testAll();
};
