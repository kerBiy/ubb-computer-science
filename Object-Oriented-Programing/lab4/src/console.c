#include "console.h"

#include <stdio.h>
#include <stdlib.h>

void printMenu() {
    printf("\nOPTION MENU:\n");
    printf("Enter 0 to Exit\n");
    printf("Enter 1 to Add\n");
    printf("Enter 2 to Delete\n");
    printf("Enter 3 to Update\n");
    printf("Enter 4 to Filter by score\n");
    printf("Enter 5 to Sort by score\n");
    printf("Enter 6 to Sort by name\n");
    printf("Enter 7 to Show this menu.\n");
    printf("Enter 9 to Print the list\n");
}

void uiPrintList(List *list) {
    for (int i = 0; i < getSize(list); ++i) {
        Participant *participant = getElement(list, i);
        printf("%s %s: %d\n", getFirstName(participant), getLastName(participant),
               getScore(participant));
    }
}

void uiPrintParticipants(List *list) {
    if (getSize(list) == 0) {
        printf("There are no participants.\n");
        return;
    }

    printf("The participants are:\n");
    uiPrintList(list);
}

void uiAddParticipant(List *list) {
    char firstName[50], lastName[50];
    int score;

    printf("\nEnter the first name: ");
    scanf("%s", firstName);

    printf("Enter the last name: ");
    scanf("%s", lastName);

    printf("Enter the score: ");
    scanf("%d", &score);

    int found = managerAddParticipant(list, firstName, lastName, score);

    found ? printf("The participant was added.\n")
          : printf("The participant is not valid.\n");
}

void uiDeleteParticipant(List *list) {
    char firstName[50], lastName[50];

    printf("\nEnter the first name: ");
    scanf("%s", firstName);

    printf("Enter the last name: ");
    scanf("%s", lastName);

    int found = managerDeleteParticipant(list, firstName, lastName);

    found ? printf("The participant was added.\n")
          : printf("The participant doesn't exist.\n");
}

void uiUpdateParticipant(List *list) {
    char firstName[50], lastName[50];
    int newScore;

    printf("\nEnter the first name: ");
    scanf("%s", firstName);

    printf("Enter the last name: ");
    scanf("%s", lastName);

    printf("Enter the new score: ");
    scanf("%d", &newScore);

    int found = managerUpdateParticipant(list, firstName, lastName, newScore);

    found ? printf("The participant was added.\n")
          : printf("The participant is not valid or doesn't exist.\n");
}

void uiFilterParticipantsByScore(List *list) {
    int minScore;

    printf("Enter the min score you what to filter by: ");
    scanf("%d", &minScore);

    List *filteredList = managerFilterParticipantsByScore(list, minScore);

    if (getSize(filteredList) == 0) {
        printf("There are no elements that fit the description.\n");
    }

    uiPrintList(filteredList);

    managerFreeList(filteredList);
}

void uiSortParticipantsByScore(List *list) {
    int reversed;
    printf("Enter 1 for reversed: ");
    scanf("%d", &reversed);

    List *sortedList;

    if (reversed == 1) {
        sortedList = managerSortParticipants(list, byScore, 1);
    } else {
        sortedList = managerSortParticipants(list, byScore, 0);
    }

    if (getSize(sortedList) == 0) {
        printf("The list is empty.\n");
    }

    uiPrintList(sortedList);

    managerFreeList(sortedList);
}

void uiSortParticipantsByName(List *list) {
    int reversed;
    printf("Enter 1 for reversed: ");
    scanf("%d", &reversed);

    List *sortedList;

    if (reversed == 1) {
        sortedList = managerSortParticipants(list, byName, 1);
    } else {
        sortedList = managerSortParticipants(list, byName, 0);
    }

    if (getSize(sortedList) == 0) {
        printf("The list is empty.\n");
    }

    uiPrintList(sortedList);

    managerFreeList(sortedList);
}

void consoleRun() {
    List *list = managerInnit();

    while (1) {
        int option;
        printf("\n>>> ");
        scanf("%d", &option);

        switch (option) {
            case 7:
                printMenu();
                break;
            case 0:
                printf("Exiting the app...\n");
                managerDestroyList(list);
                exit(EXIT_SUCCESS);
            case 9:
                uiPrintParticipants(list);
                break;
            case 1:
                uiAddParticipant(list);
                break;
            case 2:
                uiDeleteParticipant(list);
                break;
            case 3:
                uiUpdateParticipant(list);
                break;
            case 4:
                uiFilterParticipantsByScore(list);
                break;
            case 5:
                uiSortParticipantsByScore(list);
                break;
            case 6:
                uiSortParticipantsByName(list);
                break;

            default:
                printf("The command is not yet implemented.\n");
                break;
        }
    }
}