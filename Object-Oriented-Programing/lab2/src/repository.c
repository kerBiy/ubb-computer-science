#include "../include/repository.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

List *createList() {
    List *list = (List *)malloc(sizeof(List));

    if (list == NULL) {
        printf("Memory Allocation Error.");
        exit(EXIT_FAILURE);
    }

    list->size = 0;
    return list;
}

void destroyList(List* list) {
    for (int i = 0; i < list->size; ++i)
        destroyParticipant(list->items[i]);
    free(list);
}

void addParticipant(List *list, Participant *participant) {
    list->items[list->size] = participant;
    list->size = list->size + 1;
}

int updateParticipantScore(List *list, const char *firstName, const char *lastName, int newScore) {
    Participant* participant = findParticipant(list, firstName, lastName);

    if (participant == NULL) {
        printf("Error not found.");
        return 0;
    }

    updateParticipant(participant, newScore);
    return 1;
}

int deleteParticipant(List *list, const char *firstName, const char *lastName) {
    int poz = findIndex(list, firstName, lastName);

    if (poz == -1) {
        printf("Error not found.");
        return 0;
    }

    destroyParticipant(list->items[poz]);

    for (int i = poz; i < list->size; ++i)
		list->items[i] = list->items[i + 1];

	list->size = list->size - 1;
    return 1;
}

Participant *findParticipant(List *list, const char *firstName, const char *lastName) {
    for(int i = 0; i < list->size; ++i) {
        if (strcmp(list->items[i]->firstName, firstName) == 0 && strcmp(list->items[i]->lastName, lastName) == 0)
            return list->items[i];
    }
    return NULL;
}

int findIndex(List *list, const char *firstName, const char *lastName) {
    for(int i = 0; i < list->size; ++i) {
        if (strcmp(list->items[i]->firstName, firstName) == 0 && strcmp(list->items[i]->lastName, lastName) == 0) 
            return i;
    }
    return -1;
}
