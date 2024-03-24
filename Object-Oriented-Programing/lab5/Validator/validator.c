//
// Created by h on 3/8/24.
//

#include "validator.h"
#include <string.h>

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
        if (id_med == get_id(get_medicament(medicamente, i))) {
            err = 1;
        }
        if (strcmp(get_nume(medicament), get_nume(get_medicament(medicamente, i))) == 0) {
            err = 1;
        }
    }


    if (err) {
        return 0;
    }
    return 1;
}
