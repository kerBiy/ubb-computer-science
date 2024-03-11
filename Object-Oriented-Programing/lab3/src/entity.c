#include "../include/entity.h"

Participant *createParticipant(const char *firstName, const char *lastName,
                               int score) {
    Participant *participant = (Participant *)malloc(sizeof(Participant));

    participant->firstName = (char *)malloc((strlen(firstName) + 1));
    strcpy(participant->firstName, firstName);

    participant->lastName = (char *)malloc((strlen(lastName) + 1));
    strcpy(participant->lastName, lastName);

    participant->score = score;

    return participant;
}

void destroyParticipant(Participant *participant) {
    if (participant != NULL) {
        free(participant->firstName);
        free(participant->lastName);
        free(participant);
    }
}

void printParticipant(Participant *participant) {
    printf("%s %s: %d\n", participant->firstName, participant->lastName,
           participant->score);
}

char *getFirstName(Participant *participant) { return participant->firstName; }

char *getLastName(Participant *participant) { return participant->lastName; }

int getScore(Participant *participant) { return participant->score; }

void setScore(Participant *participant, int newScore) {
    participant->score = newScore;
}