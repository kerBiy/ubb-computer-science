#pragma once
#include "entity.h"

typedef struct {
    Participant items[101];
    int size;
} List;

/*
Creates an empty list of participants.
Returns: an empty list.
*/
List createList();
/*
Getter for the number of participants in the list.
Params: list - a list of participants.
Returns: the number of participants in the list.
*/
int getLen(List list);

/*
Adds a participant to the list.
Params: list - a pointer to the list of participants.
        participant - the participant to add to the list.
*/
void addParticipant(List *list, Participant participant);

/*
Finds the index of a participant in the list by their first and last name.
Params: list - a pointer to the list of participants.
        firstName - the first name of the participant to search for.
        lastName - the last name of the participant to search for.
Returns: the index of the participant in the list if found, otherwise -1.
*/
int findIndex(List *list, char firstName[], char lastName[]);

/*
Deletes a participant from the list by their first and last name.
Params: list - a pointer to the list of participants.
        firstName - the first name of the participant to delete.
        lastName - the last name of the participant to delete.
Returns: 1 if the participant is deleted successfully, otherwise 0.
*/
int deleteParticipant(List *list, char firstName[], char lastName[]);

/*
Updates the score of a participant in the list by their first and last name.
Params: list - a pointer to the list of participants.
        firstName - the first name of the participant to update.
        lastName - the last name of the participant to update.
        newScore - the new score of the participant.
Returns: 1 if the participant's score is updated successfully, otherwise 0.
*/
int updateParticipant(List *list, char firstName[], char lastName[],
                      int newScore);
