#include "../include/entity.h"

Participant createParticipant(const char* firstName, const char* lastName, int score) {
    Participant participant;

    strcpy(participant.firstName, firstName);
    strcpy(participant.lastName, lastName);
    participant.score = score;

    return participant;
}

void destroyParticipant(Participant participant) {
    // free(participant);
}

void printParticipant(Participant participant) {
    printf("%s %s: %d\n", participant.firstName, participant.lastName, participant.score);
} 
