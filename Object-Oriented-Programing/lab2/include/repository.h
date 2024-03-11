#pragma once
#include "entity.h"

typedef struct {
    Participant items[101];
    int size;
} List;

List createList();
int getLen(List list);

void addParticipant(List *list, Participant participant);
int findIndex(List *list, char firstName[], char lastName[]);
int deleteParticipant(List *list, char firstName[], char lastName[]);
int updateParticipant(List *list, char firstName[], char lastName[],
                      int newScore);
