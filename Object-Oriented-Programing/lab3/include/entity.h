#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *firstName;
    char *lastName;
    int score;
} Participant;

Participant *createParticipant(const char *firstName, const char *lastName,
                               int score);
void destroyParticipant(Participant *participant);
void printParticipant(Participant *participant);

char *getFirstName(Participant *participant);
char *getLastName(Participant *participant);
int getScore(Participant *participant);
void setScore(Participant *participant, int newScore);