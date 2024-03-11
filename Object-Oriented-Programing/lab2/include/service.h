#pragma once
#include "repository.h"
#include "validator.h"

List list;

/*
Initializes the participant manager.
*/
void managerInnit();

/*
Retrieves all participants from the manager.
Returns: a list of all participants.
*/
List managerGetAll();

/*
Adds a participant to the manager.
Params: firstName - the first name of the participant to add.
        lastName - the last name of the participant to add.
        score - the score of the participant to add.
*/
void managerAddParticipant(char firstName[], char lastName[], int score);

/*
Deletes a participant from the manager.
Params: firstName - the first name of the participant to delete.
        lastName - the last name of the participant to delete.
Returns: 1 if the participant is deleted successfully, otherwise 0.
*/
int managerDeleteParticipant(char firstName[], char lastName[]);

/*
Updates the score of a participant in the manager.
Params: firstName - the first name of the participant to update.
        lastName - the last name of the participant to update.
        newScore - the new score of the participant.
Returns: 1 if the participant's score is updated successfully, otherwise 0.
*/
int managerUpdateParticipant(char firstName[], char lastName[], int newScore);
