#include "tests.h"

#include "entity.h"
#include "repository.h"
#include "service.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

void entityTests() {
    const char *firstName = "John";
    const char *lastName = "Snow";
    const int score = 99;

    Participant *participant = createParticipant(firstName, lastName, score);

    assert(strcmp(getFirstName(participant), firstName) == 0);
    assert(strcmp(getLastName(participant), lastName) == 0);
    assert(getScore(participant) == score);

    destroyParticipant(participant);
}

void repoTests() {
    const char *p1FirstName = "The";
    const char *p1LastName = "Rock";
    const int p1Score = 99;

    const char *p2FirstName = "George";
    const char *p2LastName = "Bush";
    const int p2Score = 80;

    const char *badName = "Nobody";

    Participant *p1 = createParticipant(p1FirstName, p1LastName, p1Score);
    Participant *p2 = createParticipant(p2FirstName, p2LastName, p2Score);

    List *myList = createList();

    // Add
    addParticipant(myList, p1);
    addParticipant(myList, p2);

    assert(myList->size == 2);

    assert(strcmp(getFirstName(myList->items[0]), p1FirstName) == 0);
    assert(strcmp(getLastName(myList->items[0]), p1LastName) == 0);
    assert(getScore(myList->items[0]) == p1Score);

    assert(strcmp(getFirstName(myList->items[1]), p2FirstName) == 0);
    assert(strcmp(getLastName(myList->items[1]), p2LastName) == 0);
    assert(getScore(myList->items[1]) == p2Score);

    // Find
    int index = findIndex(myList, p2FirstName, p2LastName);
    assert(index == 1);

    int badIndex = findIndex(myList, badName, p2LastName);
    assert(badIndex == -1);

    // Delete
    deleteParticipant(myList, p1FirstName, p1LastName);
    assert(myList->size == 1);

    assert(strcmp(getFirstName(myList->items[0]), p2FirstName) == 0);
    assert(strcmp(getLastName(myList->items[0]), p2LastName) == 0);
    assert(getScore(myList->items[0]) == p2Score);

    deleteParticipant(myList, badName, p2LastName);
    assert(myList->size == 1);

    // Update
    const int newScore = 99;
    updateParticipant(myList, p2FirstName, p2LastName, newScore);

    assert(strcmp(getFirstName(myList->items[0]), p2FirstName) == 0);
    assert(strcmp(getLastName(myList->items[0]), p2LastName) == 0);
    assert(getScore(myList->items[0]) == newScore);

    updateParticipant(myList, badName, p2LastName, newScore);
    assert(myList->size == 1);
    assert(strcmp(getFirstName(myList->items[0]), p2FirstName) == 0);
    assert(strcmp(getLastName(myList->items[0]), p2LastName) == 0);
    assert(getScore(myList->items[0]) == newScore);

    destroyList(myList);
}

void serviceTests() {
    const char *p1FirstName = "The";
    const char *p1LastName = "Rock";
    const int p1Score = 99;

    const char *p2FirstName = "George";
    const char *p2LastName = "Bush";
    const int p2Score = 80;

    const char *badName = "Nom32";

    List *myList = managerInnit();

    // Add
    managerAddParticipant(myList, p1FirstName, p1LastName, p1Score);
    managerAddParticipant(myList, p2FirstName, p2LastName, p2Score);
    assert(myList->size == 2);

    managerAddParticipant(myList, badName, p2LastName, p2Score);
    assert(myList->size == 2);

    managerDeleteParticipant(myList, p1FirstName, p1LastName);
    assert(myList->size == 1);

    managerDeleteParticipant(myList, badName, p2LastName);
    assert(myList->size == 1);

    const int newScore = 99;
    managerUpdateParticipant(myList, p2FirstName, p2LastName, newScore);
    assert(myList->size == 1);
    assert(getScore(myList->items[0]) == newScore);

    managerUpdateParticipant(myList, p2FirstName, badName, p2Score);
    assert(myList->size == 1);
    assert(getScore(myList->items[0]) == newScore);

    managerDeleteParticipant(myList, p2FirstName, p2LastName);

    managerAddParticipant(myList, p1FirstName, p1LastName, p1Score);
    managerAddParticipant(myList, p2FirstName, p2LastName, p2Score);

    int minScore = 90;
    List *filteredList = managerFilterParticipantsByScore(myList, minScore);
    assert(filteredList->size == 1);

    managerFreeList(filteredList);

    int maxScore = 100;
    filteredList = managerFilterParticipantsByScore(myList, maxScore);
    assert(filteredList->size == 0);

    managerFreeList(filteredList);

    List *sortedList = managerSortParticipantsByName(myList);
    assert(sortedList->size == 2);

    assert(strcmp(getFirstName(sortedList->items[0]), p2FirstName) == 0);
    assert(strcmp(getLastName(sortedList->items[0]), p2LastName) == 0);
    assert(getScore(sortedList->items[0]) == p2Score);

    assert(strcmp(getFirstName(sortedList->items[1]), p1FirstName) == 0);
    assert(strcmp(getLastName(sortedList->items[1]), p1LastName) == 0);
    assert(getScore(sortedList->items[1]) == p1Score);

    managerFreeList(sortedList);

    sortedList = managerSortParticipantsByScore(myList);
    assert(sortedList->size == 2);

    assert(strcmp(getFirstName(sortedList->items[0]), p2FirstName) == 0);
    assert(strcmp(getLastName(sortedList->items[0]), p2LastName) == 0);
    assert(getScore(sortedList->items[0]) == p2Score);

    assert(strcmp(getFirstName(sortedList->items[1]), p1FirstName) == 0);
    assert(strcmp(getLastName(sortedList->items[1]), p1LastName) == 0);
    assert(getScore(sortedList->items[1]) == p1Score);

    managerFreeList(sortedList);

    managerDestroyList(myList);
}

void runTests() {
    entityTests();
    repoTests();
    serviceTests();
    printf("All tests passed.\n");
}