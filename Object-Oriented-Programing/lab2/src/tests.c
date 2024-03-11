#include "../include/tests.h"

void entityTests() {
    char firstName[] = "Alex";
    char lastName[] = "Balta";
    int score = 99;

    Participant participant = createParticipant(firstName, lastName, score);

    assert(strcmp(getFirstName(&participant), firstName) == 0);
    assert(strcmp(getLastName(&participant), lastName) == 0);
    assert(getScore(&participant) == score);
}

void repoTests() {
    char p1FirstName[] = "Alex";
    char p1LastName[] = "Balta";
    int p1Score = 99;

    char p2FirstName[] = "Timu";
    char p2LastName[] = "Iustin";
    int p2Score = 80;

    Participant p1 = createParticipant(p1FirstName, p1LastName, p1Score);
    Participant p2 = createParticipant(p2FirstName, p2LastName, p2Score);

    List myList = createList();

    // Add
    addParticipant(&myList, p1);
    addParticipant(&myList, p2);

    assert(myList.size == 2);

    assert(strcmp(getFirstName(&myList.items[0]), p1FirstName) == 0);
    assert(strcmp(getLastName(&myList.items[0]), p1LastName) == 0);
    assert(getScore(&myList.items[0]) == p1Score);

    assert(strcmp(getFirstName(&myList.items[1]), p2FirstName) == 0);
    assert(strcmp(getLastName(&myList.items[1]), p2LastName) == 0);
    assert(getScore(&myList.items[1]) == p2Score);

    // Find
    int index = findIndex(&myList, p2FirstName, p2LastName);
    assert(index == 1);

    // Delete
    deleteParticipant(&myList, p1FirstName, p1LastName);
    assert(myList.size == 1);

    assert(strcmp(getFirstName(&myList.items[0]), p2FirstName) == 0);
    assert(strcmp(getLastName(&myList.items[0]), p2LastName) == 0);
    assert(getScore(&myList.items[0]) == p2Score);

    // Update
    int newScore = 99;
    updateParticipant(&myList, p2FirstName, p2LastName, newScore);

    assert(strcmp(getFirstName(&myList.items[0]), p2FirstName) == 0);
    assert(strcmp(getLastName(&myList.items[0]), p2LastName) == 0);
    assert(getScore(&myList.items[0]) == newScore);
}

void runTests() {
    entityTests();
    repoTests();
    printf("All tests passed.\n");
}