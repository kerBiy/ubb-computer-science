#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "entity.h"

typedef struct
{
    Participant* participants[101];
    int size;
} List;

List *createList();
void destroyList(List* list);
void addParticipant(List* list, Participant* participant);
// void updateParticipantScore(List list, const char *firstName, const char *lastName, int newScore);
// void deleteParticipant(List list, const char *firstName, const char *lastName);
// void filterParticipantsByScore(List list, int scoreThreshold);
// void filterParticipantsByName(List list, const char *namePrefix);
// void sortParticipantsByName(List list, int ascending);
// void sortParticipantsByScore(List list, int ascending);
// void printParticipants(List list);

#endif
