#pragma once
#include "repository.h"
#include "validator.h"

List list;

void managerInnit();
List managerGetAll();

void managerAddParticipant(char firstName[], char lastName[], int score);
int managerDeleteParticipant(char firstName[], char lastName[]);
int managerUpdateParticipant(char firstName[], char lastName[], int newScore);
