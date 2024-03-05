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
    free(list);
}

void addParticipant(List *list, Participant *participant) {
    list->participants[list->size] = participant;
    list->size = list->size + 1;
}

