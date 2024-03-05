#include "../include/console.h"
#include <stdio.h>
#include <stdlib.h>

void printMenu() {
    printf("OPTION MENU:\n");
    printf("Enter 1 to ...\n");
    printf("Enter 2 to ...\n");
    printf("Enter 3 to ...\n");
}

void consoleRun() {
    while (1) {
        printMenu();

        int option;
        printf("\nEnter the mode: ");
        scanf("%d", &option);

        switch (option)
        {
        case 0:
            printf("Exiting the app...\n");
            exit(EXIT_SUCCESS);
        case 1:
            printf("Your are in 1 mode.\n");
            break;
        
        default:
            printf("The command is not yet implemented.\n");
            break;
        }
    }
}