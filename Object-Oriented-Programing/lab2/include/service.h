#pragma once
#include "repository.h"
#include "validator.h"
#include <stdio.h>

List *list;
void managerInnit();
void managerDestroy();

List* managerGetAll();
void managerAddParticipant(const char *firstName, const char *lastName, int score);
int managerDeleteParticipant(const char *firstName, const char *lastName);
int managerUpdateParticipant(const char *firstName, const char *lastName, int newScore);



