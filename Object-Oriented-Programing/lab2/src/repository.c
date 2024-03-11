#include "../include/repository.h"

List createList() {
    List list;
    list.size = 0;
    return list;
}

int getLen(List list) { return list.size; }

void addParticipant(List *list, Participant participant) {
    list->items[list->size] = participant;
    list->size = list->size + 1;
}

int findIndex(List *list, char firstName[], char lastName[]) {
    for (int i = 0; i < list->size; ++i) {
        if (strcmp(getFirstName(&list->items[i]), firstName) == 0 &&
            strcmp(getLastName(&list->items[i]), lastName) == 0)
            return i;
    }
    return -1;
}

int deleteParticipant(List *list, char firstName[], char lastName[]) {
    int poz = findIndex(list, firstName, lastName);

    if (poz == -1) {
        printf("Error not found.\n");
        return 0;
    }

    for (int i = poz; i < list->size; ++i) {
        list->items[i] = list->items[i + 1];
    }

    list->size = list->size - 1;
    return 1;
}

int updateParticipant(List *list, char firstName[], char lastName[],
                      int newScore) {
    int poz = findIndex(list, firstName, lastName);

    if (poz == -1) {
        printf("Error not found.\n");
        return 0;
    }

    setScore(&list->items[poz], newScore);
    return 1;
}
