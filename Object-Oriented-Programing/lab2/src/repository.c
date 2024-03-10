#include "../include/repository.h"

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
        destroyParticipant(&list->items[i]);
    free(list);
}

void addParticipant(List *list, Participant participant) {
    list->items[list->size] = participant;
    list->size = list->size + 1;
}

int updateParticipant(List *list, const char *firstName, const char *lastName, int newScore) {
    int poz = findIndex(list, firstName, lastName);

     if (poz == -1) {
        printf("Error not found.\n");
        return 0;
    }

    setScore(&list->items[poz], newScore);
    return 1;
}

int deleteParticipant(List *list, const char *firstName, const char *lastName) {
    int poz = findIndex(list, firstName, lastName);

    if (poz == -1) {
        printf("Error not found.\n");
        return 0;
    }

    destroyParticipant(&list->items[poz]);

    for (int i = poz; i < list->size; ++i)
		list->items[i] = list->items[i + 1];

	list->size = list->size - 1;
    return 1;
}

int findIndex(List *list, const char *firstName, const char *lastName) {
    for(int i = 0; i < list->size; ++i) {
        if (strcmp(getFirstName(&list->items[i]), firstName) == 0
            && strcmp(getLastName(&list->items[i]), lastName) == 0) 
            return i;
    }
    return -1;
}
