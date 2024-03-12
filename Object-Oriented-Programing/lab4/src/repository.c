#include "repository.h"

#include <stdlib.h>
#include <string.h>

List *createList() {
    List *list = (List *) malloc(sizeof(List));

    list->size = 0;
    list->capacity = 1;
    list->items = (Participant **) malloc(list->capacity * sizeof(Participant *));

    return list;
}

void destroyList(List *list) {
    if (list != NULL) {
        for (int i = 0; i < list->size; ++i) {
            destroyParticipant(list->items[i]);
        }
        free(list->items);
        free(list);
    }
}

void resizeList(List *list) {
    list->capacity = list->capacity * 2;
    list->items = (Participant **) realloc(
            list->items, list->capacity * sizeof(Participant *));
    if (list->items == NULL) {
        exit(EXIT_FAILURE);
    }
}

void addParticipant(List *list, Participant *participant) {
    if (list->size == list->capacity) {
        resizeList(list);
    }

    list->items[list->size] = participant;
    list->size = list->size + 1;
}

int updateParticipant(List *list, const char *firstName, const char *lastName,
                      int newScore) {
    int poz = findIndex(list, firstName, lastName);

    if (poz == -1) {
        return 0;
    }

    setScore(list->items[poz], newScore);
    return 1;
}

int deleteParticipant(List *list, const char *firstName, const char *lastName) {
    int poz = findIndex(list, firstName, lastName);

    if (poz == -1) {
        return 0;
    }

    destroyParticipant(list->items[poz]);

    for (int i = poz; i < list->size; ++i) {
        list->items[i] = list->items[i + 1];
    }
    list->size = list->size - 1;
    return 1;
}

int findIndex(List *list, const char *firstName, const char *lastName) {
    for (int i = 0; i < list->size; ++i) {
        if (strcmp(getFirstName(list->items[i]), firstName) == 0 &&
            strcmp(getLastName(list->items[i]), lastName) == 0)
            return i;
    }
    return -1;
}
