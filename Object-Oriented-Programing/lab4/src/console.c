#include "console.h"

void uiInnit() {
    managerInnit();
    printf("Press 7 for help.\n");
}

void deallocateMemory() { managerDestroy(); }

void printMenu() {
    printf("\nOPTION MENU:\n");
    printf("Enter 0 to Exit\n");
    printf("Enter 1 to Add\n");
    printf("Enter 2 to Delete\n");
    printf("Enter 3 to Update\n");
    printf("Enter 7 for this menu.\n");
    printf("Enter 9 to Print\n");
}

void uiPrintParticipants() {
    List *list = managerGetAll();

    if (list->size == 0) {
        printf("There are no participants.\n");
        return;
    }

    printf("The participants are:\n");

    for (int i = 0; i < list->size; ++i) {
        printParticipant(list->items[i]);
    }
}

void uiAddParticipant() {
    char firstName[50], lastName[50];
    int score;

    printf("\nEnter the first name: ");
    scanf("%s", firstName);

    printf("Enter the last name: ");
    scanf("%s", lastName);

    printf("Enter the score: ");
    scanf("%d", &score);

    managerAddParticipant(firstName, lastName, score);

    printf("The participant was added.\n");
}

void uiDeleteParticipant() {
    char firstName[50], lastName[50];

    printf("\nEnter the first name: ");
    scanf("%s", firstName);

    printf("Enter the last name: ");
    scanf("%s", lastName);

    int found = managerDeleteParticipant(firstName, lastName);

    if (found) printf("The participant was deleted.\n");
}

void uiUpdateParticipant() {
    char firstName[50], lastName[50];
    int newScore;

    printf("\nEnter the first name: ");
    scanf("%s", firstName);

    printf("Enter the last name: ");
    scanf("%s", lastName);

    printf("Enter the new score: ");
    scanf("%d", &newScore);

    int found = managerUpdateParticipant(firstName, lastName, newScore);

    if (found) printf("The participant was updated.\n");
}

void consoleRun() {
    uiInnit();

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
                deallocateMemory();
                exit(EXIT_SUCCESS);
            case 9:
                uiPrintParticipants();
                break;
            case 1:
                uiAddParticipant();
                break;
            case 2:
                uiDeleteParticipant();
                break;
            case 3:
                uiUpdateParticipant();
                break;

            default:
                printf("The command is not yet implemented.\n");
                break;
        }
    }
}