//
// Created by Alex Balta on 26.03.2024.
//

#pragma once

#include <string>

class Test {
  private:
    std::string title;
    std::string author;
    std::string genre;
    int year;

    std::string other_title;
    std::string other_author;
    std::string other_genre;
    int other_year;

    /**
     * Tests the domain module.
     */
    void testDomain();

    /**
     * Tests the repository module.
     */
    void testRepository();

    /**
     * Tests the validator module.
     */
    void testValidator();

    /**
     * Tests the service module.
     */
    void testService();

  public:
    /*!
     * The constructor.
     */
    Test();

    /**
     * Runs all the tests.
     */
    void runAll();
};
