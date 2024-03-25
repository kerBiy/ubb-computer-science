//
// Created by h on 3/8/24.
//

#ifndef VALIDATOR_H
#define VALIDATOR_H

#include "../Domain/medicament.h"
#include "../Domain/lista.h"

/// Valideaza un medicament creat
/// @param medicament medicamentul de verificat
/// @param medicamente lista de items
/// @return 0 sau 1 in functie daca medicamentul este valid sau nu
int validator(Medicament *m, Lista *medicamente);

#endif //VALIDATOR_H
