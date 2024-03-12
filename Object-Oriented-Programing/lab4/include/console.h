#pragma once
#include "service.h"

/*
Prints the main menu.
*/
void printMenu();

/*
Prints all participants.
*/
void uiPrintParticipants(List *list);

/*
Handles adding a participant through the user interface.
*/
void uiAddParticipant(List *list);

/*
Handles deleting a participant through the user interface.
*/
void uiDeleteParticipant(List *list);

/*
Handles updating a participant's score through the user interface.
*/
void uiUpdateParticipant(List *list);

/*
Runs the console user interface.
*/
void consoleRun();
