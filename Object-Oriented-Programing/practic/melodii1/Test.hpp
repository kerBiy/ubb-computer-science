//
// Created by Alex Balta on 17.05.2024.
//

#pragma once

#include <string>

class Test {
  private:
    int id1;
    std::string title1;
    std::string author1;
    int rank1;

    int id2;
    std::string title2;
    std::string author2;
    int rank2;

    void testDomain();
    void testRepository();
    void testService();
  public:
    Test();
    void testAll();
};
