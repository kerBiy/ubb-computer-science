#pragma once

#include "repository.h"

/*
Initializes the participant manager.
Params: list - a list of participants.
*/
List *managerInnit();

/*
Destroys the list given as input.
This mean that does free the list and it's items.
Params: list - a list of participants.
*/
void managerDestroyList(List *list);

/*
Frees the list given as input.
This mean that does not free the content only the container.
Params: list - a list of participants.
*/
void managerFreeList(List *list);

/*
Adds a participant to the manager.
Params: list - a list of participants.
        firstName - the first name of the participant to add.
        lastName - the last name of the participant to add.
        score - the score of the participant to add.
*/
int managerAddParticipant(List *list, const char *firstName, const char *lastName,
                          int score);

/*
Deletes a participant from the manager.
Params: list - a list of participants.
        firstName - the first name of the participant to delete.
        lastName - the last name of the participant to delete.
Returns: 1 if the participant is deleted successfully, otherwise 0.
*/
int managerDeleteParticipant(List *list, const char *firstName, const char *lastName);

/*
Updates the score of a participant in the manager.
Params: list - a list of participants.
        firstName - the first name of the participant to update.
        lastName - the last name of the participant to update.
        newScore - the new score of the participant.
Returns: 1 if the participant's score is updated successfully, otherwise 0.
*/
int managerUpdateParticipant(List *list, const char *firstName, const char *lastName,
                             int newScore);

/*
Filters the participants by the score.
Params: list - a list of participants.
        minScore - a number representing the min score of the filtered participants.
Returns: a list of participants if they score higher than the score given as parameter.
*/
List *managerFilterParticipantsByScore(List *list, int minScore);

/*
Compare the participants by name
Params: first - a participant
        second - a participant
Returns: 1 if they are not in order 0 otherwise
*/
int byName(Participant *first, Participant *second);

/*
Compare the participants by name
Params: first - a participant
        second - a participant
Returns: 1 if they are not in order 0 otherwise
*/
int byScore(Participant *first, Participant *second);

/*
Sorts the participants by the cmp given as parameter.
Params: list - a list of participants.
        cmp - a function which compares the elements
Returns: a list of participants sorted by their score.
*/
List *managerSortParticipants(List *list, int (*cmp)(Participant *, Participant *), int reversed);