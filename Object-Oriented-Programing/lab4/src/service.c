#include "service.h"
#include "validator.h"

List *managerInnit() {
    return createList();
}

void managerDestroy(List *list) {
    destroyList(list);
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