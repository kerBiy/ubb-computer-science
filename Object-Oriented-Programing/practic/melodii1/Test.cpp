//
// Created by Alex Balta on 17.05.2024.
//

#include "Test.hpp"

#include "Entity.hpp"
#include "Repository.hpp"
#include "Service.hpp"

#include <cassert>
#include <iostream>

Test::Test() {
    id1 = 1;
    title1 = "Alright";
    author1 = "Kendrick Lamar";
    rank1 = 4;

    id2 = 2;
    title2 = "Runaway";
    author2 = "Kanye West";
    rank2 = 1;
}

void Test::testDomain() {
    std::cout << "Domain tests started\n";

    Song new_song{id1, title1, author1, rank1};
    assert(new_song.getId() == id1);
    assert(new_song.getTitle() == title1);
    assert(new_song.getAuthor() == author1);
    assert(new_song.getRank() == rank1);

    new_song.setTitle(title2);
    assert(new_song.getTitle() == title2);

    new_song.setRank(rank2);
    assert(new_song.getRank() == rank2);

    std::cout << "Domain tests ran successfully\n";
}

void Test::testRepository() {
    std::cout << "Repository tests started\n";

    std::cout << "Repository tests ran successfully\n";
}

void Test::testService() {
    std::cout << "Service tests started\n";

    std::cout << "Service tests ran successfully\n";
}

void Test::testAll() {
    std::cout << "Tests started\n";
    testDomain();
    testRepository();
    testService();
    std::cout << "All tests ran successfully\n";
}
