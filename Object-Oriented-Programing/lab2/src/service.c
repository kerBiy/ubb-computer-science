#include "../include/service.h"

void managerInnit() { list = createList(); }

List managerGetAll() { return list; }

void managerAddParticipant(char firstName[], char lastName[], int score) {
    if (!isValidName(firstName) || !isValidName(lastName) ||
        !isValidScore(score)) {
        printf("Service error.\n");
        return;
    }

    Participant participant = createParticipant(firstName, lastName, score);
    addParticipant(&list, participant);
}

int managerDeleteParticipant(char firstName[], char lastName[]) {
    if (!isValidName(firstName) || !isValidName(lastName)) {
        printf("Service error.\n");
        return 0;
    }

    return deleteParticipant(&list, firstName, lastName);
}

int managerUpdateParticipant(char firstName[], char lastName[], int newScore) {
    if (!isValidName(firstName) || !isValidName(lastName) ||
        !isValidScore(newScore)) {
        printf("Service error.\n");
        return 0;
    }

    return updateParticipant(&list, firstName, lastName, newScore);
}