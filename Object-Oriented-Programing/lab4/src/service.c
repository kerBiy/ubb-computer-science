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

    for (int i = 0; i < list->size; ++i) {
        if (list->items[i]->score >= minScore) {
            addParticipant(output, list->items[i]);
        }
    }

    return output;
}

List *managerSortParticipantsByName(List *list) {
    List *output = createList();

    for (int i = 0; i < list->size; ++i) {
        addParticipant(output, list->items[i]);
    }

    for (int i = 0; i < output->size - 1; ++i) {
        for (int j = i + 1; j < output->size; ++j) {
            if (strcmp(output->items[i]->firstName, output->items[j]->firstName) > 0
                || (strcmp(output->items[i]->firstName, output->items[j]->firstName) == 0
                    && strcmp(output->items[i]->lastName, output->items[j]->lastName) > 0)) {
                Participant *aux = output->items[i];
                output->items[i] = output->items[j];
                output->items[j] = aux;
            }
        }
    }

    return output;
}

List *managerSortParticipantsByScore(List *list) {
    List *output = createList();

    for (int i = 0; i < list->size; ++i) {
        addParticipant(output, list->items[i]);
    }

    for (int i = 0; i < output->size - 1; ++i) {
        for (int j = i + 1; j < output->size; ++j) {
            if (output->items[i]->score > output->items[j]->score) {
                Participant *aux = output->items[i];
                output->items[i] = output->items[j];
                output->items[j] = aux;
            }
        }
    }

    return output;
}
