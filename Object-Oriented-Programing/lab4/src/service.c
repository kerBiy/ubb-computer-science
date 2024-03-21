#include "service.h"
#include "validator.h"

#include <string.h>
#include <stdlib.h>

List *managerInnit() {
    return createList();
}

void managerDestroyList(List *list) {
    destroyList(list);
}

void managerFreeList(List *list) {
    free(list->items);
    free(list);
}

int managerAddParticipant(List *list, const char *firstName, const char *lastName,
                          int score) {
    if (!isValidName(firstName) || !isValidName(lastName) ||
        !isValidScore(score)) {
        return 0;
    }

    Participant *participant = createParticipant(firstName, lastName, score);
    addParticipant(list, participant);
    return 1;
}

int managerDeleteParticipant(List *list, const char *firstName, const char *lastName) {
    if (!isValidName(firstName) || !isValidName(lastName)) {
        return 0;
    }

    return deleteParticipant(list, firstName, lastName);
}

int managerUpdateParticipant(List *list, const char *firstName, const char *lastName,
                             int newScore) {
    if (!isValidName(firstName) || !isValidName(lastName) ||
        !isValidScore(newScore)) {
        return 0;
    }

    return updateParticipant(list, firstName, lastName, newScore);
}

List *managerFilterParticipantsByScore(List *list, int minScore) {
    List *output = createList();

    for (int i = 0; i < getSize(list); ++i) {
        if (getElement(list, i)->score >= minScore) {
            addParticipant(output, getElement(list, i));
        }
    }

    return output;
}

int byName(Participant *first, Participant *second) {
    return getScore(first) > getScore(second);
}

int byScore(Participant *first, Participant *second) {
    return strcmp(getFirstName(first), getFirstName(second)) > 0;
}


List *managerSortParticipants(List *list, int (*cmp)(Participant *, Participant *), int reversed) {
    List *output = createList();

    for (int i = 0; i < getSize(list); ++i) {
        addParticipant(output, getElement(list, i));
    }

    for (int i = 0; i < getSize(output) - 1; ++i) {
        for (int j = i + 1; j < getSize(output); ++j) {
            if ((cmp(getElement(output, i), getElement(output, j)) && reversed == 0) ||
                (!cmp(getElement(output, i), getElement(output, j)) && reversed == 1)) {
                Participant *aux = output->items[i];
                output->items[i] = output->items[j];
                output->items[j] = aux;
            }
        }
    }

    return output;
}