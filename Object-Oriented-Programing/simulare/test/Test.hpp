//
// Created by Alex Balta on 21.05.2024.
//

#pragma once

#include "Repository.hpp"

class Test {
  private:
    int id1;
    std::string name1;
    std::string size1;
    double price1;
    bool valid1;

    void testDomain();
    void testRepository();
    void testService();
  public:
    Test();
    void testAll();
};
