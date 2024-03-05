#ifndef ENTITY_H
#define ENTITY_H

typedef struct
{
    char firstName[50];
    char lastName[50];
    int score;
} Participant;

Participant *createParticipant(const char *firstName, const char *lastName, int score);
void updateParticipant(Participant *participant, const char *firstName, const char *lastName, int score);
void destroyParticipant(Participant *participant);

#endif