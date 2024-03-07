#include "../include/entity.h"

Participant *createParticipant(const char* firstName, const char* lastName, int score) {
    Participant *participant = (Participant*)malloc(sizeof(Participant));

    if (participant == NULL) {
        printf("Memory Allocation Error.");
        exit(EXIT_FAILURE);
    }

    strcpy(participant->firstName, firstName);
    strcpy(participant->lastName, lastName);
    participant->score = score;

    return participant;
}

void updateParticipant(Participant *participant, int newScore) {
    participant->score = newScore;
}

void destroyParticipant(Participant* participant) {
    free(participant);
}

void printParticipant(Participant* participant) {
    printf("%s %s: %d\n", participant->firstName, participant->lastName, participant->score);
} 
