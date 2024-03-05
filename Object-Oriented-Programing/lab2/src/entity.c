#include "../include/entity.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void updateParticipant(Participant *participant, const char* firstName, const char* lastName, int score) {
    strcpy(participant->firstName, firstName);
    strcpy(participant->lastName, lastName);
    participant->score = score;
}

void destroyParticipant(Participant* participant) {
    free(participant);
}
