#pragma once
#include "entity.h"

typedef struct
{
    Participant items[101];
    int size;
} List;

List *createList();
void destroyList(List *list);
void addParticipant(List *list, Participant participant);
int updateParticipant(List *list, const char *firstName, const char *lastName, int newScore);
int deleteParticipant(List *list, const char *firstName, const char *lastName);
int findIndex(List *list, const char *firstName, const char *lastName);
// void filterParticipantsByScore(List list, int scoreThreshold);
// void filterParticipantsByName(List list, const char *namePrefix);
// void sortParticipantsByName(List list, int ascending);
// void sortParticipantsByScore(List list, int ascending);
// void printParticipants(List list);

