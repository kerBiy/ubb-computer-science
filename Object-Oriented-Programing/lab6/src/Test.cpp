//
// Created by Alex Balta on 26.03.2024.
//

#include "Test.hpp"

#include "Book.hpp"
#include "Repository.hpp"
#include "Service.hpp"

#include <iostream>
#include <cassert>

Test::Test() {
    title = "War and Peace";
    author = "Lev Tolstoy";
    genre = "Social Roman";
    year = 1890;

    other_title = "The brothers Karamazov";
    other_author = "Fyodor Dostoievski";
    other_genre = "Crime";
    other_year = 1910;
}

void Test::testDomain() {
    Book new_book(title, author, genre, year);

    assert(new_book.getTitle() == title);
    assert(new_book.getAuthor() == author);
    assert(new_book.getGenre() == genre);
    assert(new_book.getYear() == year);

    assert(new_book.intoString() == "War and Peace, Lev Tolstoy, Social Roman, 1890");

    new_book.setTitle(other_title);
    new_book.setAuthor(other_author);
    new_book.setGenre(other_genre);
    new_book.setYear(other_year);

    assert(new_book.getTitle() == other_title);
    assert(new_book.getAuthor() == other_author);
    assert(new_book.getGenre() == other_genre);
    assert(new_book.getYear() == other_year);

    std::cout << "Domain tests ran successfully.\n";
}

void Test::testRepository() {
    Repository repo;
    Book new_book(title, author, genre, year);
    Book other_book(other_title, other_author, other_genre, other_year);

    // TEST ADD
    repo.addBook(new_book);
    assert(repo.getLen() == 1);
    repo.addBook(other_book);
    assert(repo.getLen() == 2);

    // TEST DELETE
    auto book_iter = repo.findBook(other_title);
    assert(repo.isPositionValid(book_iter));
    repo.deleteBook(book_iter);
    assert(repo.getLen() == 1);

    // TEST UPDATE
    book_iter = repo.findBook(title);
    repo.updateBook(book_iter, other_book);
    assert(repo.getLen() == 1);

    auto all = repo.getBooks();
    assert(all.front().getTitle() == other_title);
    assert(all.front().getAuthor() == other_author);
    assert(all.front().getGenre() == other_genre);
    assert(all.front().getYear() == other_year);

    std::cout << "Repository tests ran successfully.\n";
}


void Test::testService() {
    Repository repo;
    Service service(repo);

    // TEST ADD
    service.addBook(title, author, genre, year);
    assert(service.getAll().size() == 1);
    assert(repo.getLen() == 1);

    service.addBook(title, other_author, other_genre, other_year);
    assert(service.getAll().size() == 1);
    assert(repo.getLen() == 1);

    // TEST UPDATE
    service.updateBook(title, other_author, other_genre, other_year);
    assert(service.getAll().size() == 1);

    service.updateBook(other_title, author, genre, year);
    assert(service.getAll().size() == 1);

    auto all = service.getAll();
    assert(all.front().getTitle() == title);
    assert(all.front().getAuthor() == other_author);
    assert(all.front().getGenre() == other_genre);
    assert(all.front().getYear() == other_year);

    auto all_repo = repo.getBooks();
    assert(all_repo.front().getTitle() == title);
    assert(all_repo.front().getAuthor() == other_author);
    assert(all_repo.front().getGenre() == other_genre);
    assert(all_repo.front().getYear() == other_year);

    // TEST DELETE
    service.deleteBook(title);
    assert(service.getAll().empty());

    service.addBook(title, other_author, other_genre, other_year);
    service.deleteBook(other_title);
    assert(service.getAll().size() == 1);

    std::cout << "Service tests ran successfully.\n";
}

void Test::runAll() {
    testDomain();
    testRepository();
    testService();
    std::cout << "All tests ran successfully.\n";
}
