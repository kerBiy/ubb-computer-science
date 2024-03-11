#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
It's an Participant object
Attrs: firstName - a string containing the first name of a participant
        lastName - a string containing the last name of a participant
        score - an number form 0 to 100 witch is the score of the participant
*/
typedef struct {
    char firstName[50];
    char lastName[50];
    int score;
} Participant;

/*
Creates an participant
Params: firstName - a string containing the first name of a participant
        lastName - a string containing the last name of a participant
        score - an number form 0 to 100 witch is the score of the participant
*/
Participant createParticipant(char firstName[], char lastName[], int score);

/*
Prints a participant on screen
Params: participant - a participant given by value
*/
void printParticipant(Participant participant);

/*
Getter for the first name of an participant
Params: participant - a participant given by an address
*/
char *getFirstName(Participant *participant);

/*
Getter for the last name of an participant
Params: participant - a participant given by an address
*/
char *getLastName(Participant *participant);

/*
Getter for the score of an participant
Params: participant - a participant given by an address
*/
int getScore(Participant *participant);

/*
Setter for the score attribute of an participant
Params: participant - a participant given by an address
*/
void setScore(Participant *participant, int newScore);