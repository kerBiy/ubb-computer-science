#include "service.h"

void managerInnit() { list = createList(); }

void managerDestroy() { destroyList(list); }

List *managerGetAll() { return list; }

void managerAddParticipant(const char *firstName, const char *lastName,
                           int score) {
    if (!isValidName(firstName) || !isValidName(lastName) ||
        !isValidScore(score)) {
        printf("Service error.\n");
        return;
    }

    Participant *participant = createParticipant(firstName, lastName, score);
    addParticipant(list, participant);
}

int managerDeleteParticipant(const char *firstName, const char *lastName) {
    if (!isValidName(firstName) || !isValidName(lastName)) {
        printf("Service error.\n");
        return 0;
    }

    return deleteParticipant(list, firstName, lastName);
}

int managerUpdateParticipant(const char *firstName, const char *lastName,
                             int newScore) {
    if (!isValidName(firstName) || !isValidName(lastName) ||
        !isValidScore(newScore)) {
        printf("Service error.\n");
        return 0;
    }

    return updateParticipant(list, firstName, lastName, newScore);
}