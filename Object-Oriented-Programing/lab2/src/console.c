#include "../include/console.h"
#include <stdio.h>
#include <stdlib.h>

void uiInnit() {
    managerInnit();
}

void deallocateMemory() {
    managerDestroy();
}

void printMenu() {
    printf("\nOPTION MENU:\n");
    printf("Enter 1 to Print\n");
    printf("Enter 2 to Add\n");
    printf("Enter 3 to Delete\n");
    printf("Enter 4 to Update\n");
    printf("Enter 0 to Exit\n");
}

void uiPrintParticipants() {
    printf("The participants are:\n");

    List *list = managerGetAll();
    for (int i = 0; i < list->size; ++i)
        printParticipant(list->items[i]);
}

void uiAddParticipant() {
    char firstName[50], lastName[50];
    int score;
    
    printf("\nEnter the first name: ");
    scanf("%s", firstName);

    printf("\nEnter the last name: ");
    scanf("%s", lastName);

    printf("\nEnter the score: ");
    scanf("%d", &score);

    managerAddParticipant(firstName, lastName, score);

    printf("\nThe participant was added.");
}

void uiDeleteParticipant() {
    char firstName[50], lastName[50];
    
    printf("\nEnter the first name: ");
    scanf("%s", firstName);

    printf("\nEnter the last name: ");
    scanf("%s", lastName);

    int found = managerDeleteParticipant(firstName, lastName);
    if (found) printf("\nThe participant was deleted.");
}

void uiUpdateParticipant() {
    char firstName[50], lastName[50];
    int newScore;
    
    printf("\nEnter the first name: ");
    scanf("%s", firstName);

    printf("\nEnter the last name: ");
    scanf("%s", lastName);

    printf("\nEnter the new score: ");
    scanf("%d", &newScore);

    int found = managerUpdateParticipant(firstName, lastName, newScore);
    if (found) printf("\nThe participant was updated.");
}

void consoleRun() {
    uiInnit();

    while (1) {
        printMenu();

        int option;
        printf("\nEnter the mode: ");
        scanf("%d", &option);

        switch (option)
        {
        case 0:
            printf("Exiting the app...\n");
            deallocateMemory();
            exit(EXIT_SUCCESS);
        case 1:
            uiPrintParticipants();
            break;
        case 2:
            uiAddParticipant();
            break;
        case 3:
            uiDeleteParticipant();
            break;
        case 4:
            uiUpdateParticipant();
            break;
        
        default:
            printf("The command is not yet implemented.\n");
            break;
        }
    }
}