#pragma once

#include "service.h"

/*
Prints the main menu.
*/
void printMenu();

/*
Prints a list given as input.
Params: list - a list of participants
*/
void uiPrintList(List *list);

/*
Prints all participants.
Params: list - a list of participants
*/
void uiPrintParticipants(List *list);

/*
Handles adding a participant through the user interface.
Params: list - a list of participants
*/
void uiAddParticipant(List *list);

/*
Handles deleting a participant through the user interface.
Params: list - a list of participants
*/
void uiDeleteParticipant(List *list);

/*
Handles updating a participant's score through the user interface.
Params: list - a list of participants
*/
void uiUpdateParticipant(List *list);

/*
Handles filtering the participants by score through the user interface.
Params: list - a list of participants
*/
void uiFilterParticipantsByScore(List *list);

/*
Handles sorting the participants by score through the user interface.
Params: list - a list of participants
*/
void uiSortParticipantsByScore(List *list);

/*
Runs the console user interface.
*/
void consoleRun();
