//
// Created by h on 3/8/24.
//

#include "validator.h"
#include <string.h>


/// Valideaza un medicament creat
/// @param medicament medicamentul de verificat
/// @param medicamente lista de medicamente
/// @return 0 sau 1 in functie daca medicamentul este valid sau nu
int validator(Medicament *medicament, Lista *medicamente) {
    int err = 0;
    if (strcmp(get_nume(medicament), "") == 0) {
        err = 1;
    }
    if (get_concentratie(medicament) > 100) {
        err = 1;
    }
    int id_med = get_id(medicament);
    int len = get_len(medicamente);
    for (int i = 0; i < len; i++) {
        Medicament *med = (Medicament *) medicamente->medicamente[i];

        if (id_med == get_id(med)) {
            err = 1;
        }
        if (strcmp(get_nume(medicament), get_nume(med)) == 0) {
            err = 1;
        }
    }


    if (err) {
        return 0;
    }
    return 1;
}
