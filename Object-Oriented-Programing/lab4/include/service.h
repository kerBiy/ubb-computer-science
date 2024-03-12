#pragma once
#include "repository.h"
#include "validator.h"

List *list;

/*
Initializes the participant manager.
Params: list - a list of participants.
*/
void managerInnit();

/*
Destroys the participant manager.
Params: list - a list of participants.
*/
void managerDestroy();

/*
Retrieves all participants from the manager.
Params: list - a list of participants.
Returns: a list of all participants.
*/
List *managerGetAll();

/*
Adds a participant to the manager.
Params: list - a list of participants.
        firstName - the first name of the participant to add.
        lastName - the last name of the participant to add.
        score - the score of the participant to add.
*/
void managerAddParticipant(const char *firstName, const char *lastName,
                           int score);

/*
Deletes a participant from the manager.
Params: list - a list of participants.
        firstName - the first name of the participant to delete.
        lastName - the last name of the participant to delete.
Returns: 1 if the participant is deleted successfully, otherwise 0.
*/
int managerDeleteParticipant(const char *firstName, const char *lastName);

/*
Updates the score of a participant in the manager.
Params: list - a list of participants.
        firstName - the first name of the participant to update.
        lastName - the last name of the participant to update.
        newScore - the new score of the participant.
Returns: 1 if the participant's score is updated successfully, otherwise 0.
*/
int managerUpdateParticipant(const char *firstName, const char *lastName,
                             int newScore);
