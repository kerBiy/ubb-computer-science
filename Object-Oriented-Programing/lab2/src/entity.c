#include "../include/entity.h"

Participant createParticipant(char firstName[], char lastName[], int score) {
    Participant participant;

    strcpy(participant.firstName, firstName);
    strcpy(participant.lastName, lastName);
    participant.score = score;

    return participant;
}

void printParticipant(Participant participant) {
    printf("%s %s: %d\n", participant.firstName, participant.lastName,
           participant.score);
}

char *getFirstName(Participant *participant) { return participant->firstName; }

char *getLastName(Participant *participant) { return participant->lastName; }

int getScore(Participant *participant) { return participant->score; }

void setScore(Participant *participant, int newScore) {
    participant->score = newScore;
}