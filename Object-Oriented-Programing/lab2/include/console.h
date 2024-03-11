#pragma once
#include "service.h"

/*
Initializes the user interface.
*/
void uiInnit();

/*
Prints the main menu.
*/
void printMenu();

/*
Prints all participants.
*/
void uiPrintParticipants();

/*
Handles adding a participant through the user interface.
*/
void uiAddParticipant();

/*
Handles deleting a participant through the user interface.
*/
void uiDeleteParticipant();

/*
Handles updating a participant's score through the user interface.
*/
void uiUpdateParticipant();

/*
Runs the console user interface.
*/
void consoleRun();
