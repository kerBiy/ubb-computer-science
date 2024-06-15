//
// Created by Alex Balta on 17.05.2024.
//

#include "Test.hpp"

#include "Song.hpp"
#include "Repository.hpp"
#include "Service.hpp"

#include <cassert>
#include <iostream>
#include <fstream>

Test::Test() {
    id1 = 1;
    title1 = "Alright";
    artist1 = "Kendrick Lamar";
    genre1 = "rock";

    id2 = 2;
    title2 = "Runaway";
    artist2 = "Kanye West";
    genre2 = "pop";
}

void Test::testDomain() {
    std::cout << "Domain tests started\n";

    Song new_song{id1, title1, artist1, genre1};
    assert(new_song.getId() == id1);
    assert(new_song.getTitle() == title1);
    assert(new_song.getArtist() == artist1);
    assert(new_song.getGenre() == genre1);

    new_song.setTitle(title2);
    assert(new_song.getTitle() == title2);

    new_song.setArtist(artist2);
    assert(new_song.getArtist() == artist2);

    new_song.setGenre(genre2);
    assert(new_song.getGenre() == genre2);

    std::cout << "Domain tests ran successfully\n";
}

void Test::testRepository() {
    std::cout << "Repository tests started\n";

    Song t1(id1, title1, artist1, genre1);
    Song t2(id2, title2, artist2, genre2);

    std::ofstream out("test.txt");
    out.close();

    Repository repo("test.txt");

    repo.addSong(t1);
    assert(repo.findSong(id1) == true);

    assert(repo.findSong(id2) == false);

    repo.addSong(t2);
    assert(repo.getAll().size() == 2);

    repo.deleteSong(id1);
    assert(repo.getAll().size() == 1);

    repo.updateSong(id2, t1);
    assert(repo.getAll()[0].getTitle() == title1);

    Repository repo2("test.txt");
    assert(repo2.getAll().size() == 1);

    try {
        Repository repo3("random_file_name.txt");
    } catch (const std::exception &e) {}

    std::remove("test.txt");
    std::cout << "Repository tests ran successfully\n";
}

void Test::testService() {
    std::cout << "Service tests started\n";

    Song t1(id1, title1, artist1, genre1);

    std::ofstream out("test.txt");
    out.close();

    Repository repo("test.txt");
    repo.addSong(t1);

    Service service(repo);
    assert(service.getAll().size() == 1);
    assert(service.getLen() == 1);

    service.addSong(title2, artist2, genre2);
    assert(repo.getAll().size() == 2);
    assert(service.getLen() == 2);

    try {
        service.addSong("", "", "");
    } catch (const ServiceException &e) {}

    try {
        service.addSong(title1, artist1, "random");
    } catch (const ServiceException &e) {}

    std::remove("test.txt");
    std::cout << "Service tests ran successfully\n";
}

void Test::testAll() {
    std::cout << "Tests started\n";
    testDomain();
    testRepository();
    testService();
    std::cout << "All tests ran successfully\n";
}
