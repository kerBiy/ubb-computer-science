//
// Created by h on 3/8/24.
//

#include "Service.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int add_medicament(Lista *list, int id, char *nume, float concentratie, int cantitate) {
    Medicament *m = createMedicament(id, nume, concentratie, cantitate);
    if (validator(m, list) == 1) {
        push(list, m);
        return 1;
    } else {
        free(m);
        return 0;
    }
}

int modify_quantity(Lista *list, int id, int cantitate) {
    int len = get_len(list);
    for (int i = 0; i < len; i++) {
        if (get_id(get_medicament(list, i)) == id) {
            set_cantitate(get_medicament(list, i), cantitate);
            return 1;
        }
    }
    return 0;
}

int modify_medicament(Lista *list, int id, char *nume, float concentratie) {
    int len = get_len(list);
    for (int i = 0; i < len; i++) {
        if (get_id(get_medicament(list, i)) == id) {
            set_nume(get_medicament(list, i), nume);
            set_concentratie(get_medicament(list, i), concentratie);
            return 1;
        }
    }
    return 0;

}

int delete_all_stock(Lista *list, int id) {
    int len = get_len(list);
    for (int i = 0; i < len; i++) {
        if (get_id(get_medicament(list, i)) == id) {
            set_cantitate(get_medicament(list, i), 0);
            return 1;
        }

    }
    return 0;
}

int nume_cresc(Medicament *m1, Medicament *m2) {
    if (strcmp(get_nume(m1), get_nume(m2)) > 0) {
        return 1;
    }
    return 0;
}

int nume_descresc(Medicament *m1, Medicament *m2) {
    if (strcmp(get_nume(m1), get_nume(m2)) < 0) {
        return 1;
    }
    return 0;
}

int cantitate_crescator(Medicament *m1, Medicament *m2) {
    if (get_cantitate(m1) > get_cantitate(m2)) {
        return 1;
    }
    return 0;
}

int cantitate_descrescator(Medicament *m1, Medicament *m2) {
    if (get_cantitate(m1) < get_cantitate(m2)) {
        return 1;
    }
    return 0;
}

void sort(Lista *list, int (*functie)(Medicament *m1, Medicament *m2)) {
    int len = get_len(list);
    for (int k = 0; k < len; k++) {
        for (int i = 0; i < len - 1; i++) {
            if (functie(get_medicament(list, i), get_medicament(list, i + 1))) {
                listswap(list, i, i + 1);
            }
        }
    }
}

Lista *filter_cantitate(Lista *list, int cantitate) {
    Lista *filtrate = createLista();

    int len = get_len(list);
    for (int i = 0; i < len; i++) {
        if (get_cantitate(get_medicament(list, i)) <= cantitate) {
            push(filtrate, get_medicament(list, i));
        }
    }
    return filtrate;
}

Lista *filter_initiala(Lista *list, char initiala) {
    Lista *filtrate = createLista();
    int len = get_len(list);
    for (int i = 0; i < len; i++) {
        if (get_nume(get_medicament(list, i))[0] == initiala) {
            push(filtrate, get_medicament(list, i));
        }
    }
    return filtrate;
}

int verify_existence(Lista *list, char *nume) {
    int len = get_len(list);
    for (int i = 0; i < len; i++) {
        if (strcmp(get_nume(get_medicament(list, i)), nume) == 0) {
            return get_id(get_medicament(list, i));
        }
    }
    return -1;

}

// My code

Lista *filter_concentratie(Lista *list, float concentratie) {
    Lista *filtrate = createLista();

    int len = get_len(list);

    for (int i = 0; i < len; i++) {
        if (get_concentratie(get_medicament(list, i)) >= concentratie) {
            push(filtrate, get_medicament(list, i));
        }
    }

    return filtrate;
}

void updateHistory(Lista *history, Lista *medicamente) {
    Lista *newList = deepCopy(medicamente);
    push(history, newList);
}

int undo(Lista *history, Lista **medicamente) {
    if (history->len <= 1) {
        return 0;
    }
    if (*medicamente != (Lista *) history->items[history->len - 1])
        destructor((Lista *) history->items[history->len - 1]);

    destructor(*medicamente);

    history->len--;
    *medicamente = (Lista *) history->items[history->len - 1];
    return 1;
}