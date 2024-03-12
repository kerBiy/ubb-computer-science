#include "console.h"

#include <stdio.h>
#include <stdlib.h>

void deallocateMemory(List *list) {
    managerDestroy(list);
}

void printMenu() {
    printf("\nOPTION MENU:\n");
    printf("Enter 0 to Exit\n");
    printf("Enter 1 to Add\n");
    printf("Enter 2 to Delete\n");
    printf("Enter 3 to Update\n");
    printf("Enter 7 for this menu.\n");
    printf("Enter 9 to Print\n");
}

void uiPrintParticipants(List *list) {
    if (list->size == 0) {
        printf("There are no participants.\n");
        return;
    }

    printf("The participants are:\n");

    for (int i = 0; i < list->size; ++i) {
        Participant *participant = list->items[i];
        printf("%s %s: %d\n", getFirstName(participant), getLastName(participant),
               getScore(participant));
    }
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

    if (found) {
        printf("The participant was added.\n");
    } else {
        printf("The participant is not valid.\n");
    }

}

void uiDeleteParticipant(List *list) {
    char firstName[50], lastName[50];

    printf("\nEnter the first name: ");
    scanf("%s", firstName);

    printf("Enter the last name: ");
    scanf("%s", lastName);

    int found = managerDeleteParticipant(list, firstName, lastName);

    if (found) {
        printf("The participant was deleted.\n");
    } else {
        printf("The participant is not valid or doesn't exist.\n");
    }

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

    if (found) {
        printf("The participant was updated.\n");
    } else {
        printf("The participant is not valid or doesn't exist.\n");
    }
}

void consoleRun() {
    List *list = managerInnit();
    printf("Press 7 for help.\n");

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
                deallocateMemory(list);
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

            default:
                printf("The command is not yet implemented.\n");
                break;
        }
    }
}