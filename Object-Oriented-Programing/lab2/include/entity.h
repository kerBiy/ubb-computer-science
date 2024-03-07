#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char firstName[50];
    char lastName[50];
    int score;
} Participant;

Participant *createParticipant(const char *firstName, const char *lastName, int score);
void updateParticipant(Participant *participant, int newScore);
void destroyParticipant(Participant *participant);
void printParticipant(Participant *participant);