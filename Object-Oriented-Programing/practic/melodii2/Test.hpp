//
// Created by Alex Balta on 17.05.2024.
//

#pragma once
#include <string>

class Test {
  private:
    int id1;
    std::string title1;
    std::string artist1;
    std::string genre1;

    int id2;
    std::string title2;
    std::string artist2;
    std::string genre2;

    void testDomain();
    void testRepository();
    void testService();
  public:
    Test();
    void testAll();
};
