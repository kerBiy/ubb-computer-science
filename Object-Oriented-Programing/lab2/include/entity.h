#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char firstName[50];
    char lastName[50];
    int score;
} Participant;

Participant createParticipant(const char *firstName, const char *lastName,
                              int score);
void printParticipant(Participant participant);

char *getFirstName(Participant *participant);
char *getLastName(Participant *participant);
int getScore(Participant *participant);
void setScore(Participant *participant, int newScore);