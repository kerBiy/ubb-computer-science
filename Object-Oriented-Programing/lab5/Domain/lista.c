//
// Created by h on 3/8/24.
//

#include "lista.h"
#include <stdlib.h>

int get_len(Lista *lista) {
    return lista->len;
}

void set_len(Lista *lista, int len) {
    lista->len = len;
}

Medicament *get_medicamente(Lista *lista) {
    return lista->medicamente;
}

void push(Lista *lista, Medicament medicament) {
    lista->medicamente[get_len(lista)] = medicament;
    lista->len += 1;
    reallocMedicament(&lista->medicamente, lista->len);
}

void pop(Lista *lista, int id) {

    int len = get_len(lista);
    for (int i = 0; i < len; i++) {
        if (lista->medicamente[i].id == id) {
            for (int j = i + 1; j < len; j++) {
                lista->medicamente[j - 1] = lista->medicamente[j];
            }
            lista->len -= 1;
            return;
        }
    }
}

Lista createLista() {
    Lista list;
    set_len(&list, 0);
    list.medicamente = allocateMedicament();
    return list;
}

void listswap(Lista *list, int index1, int index2) {
    Medicament med = list->medicamente[index1];
    list->medicamente[index1] = list->medicamente[index2];
    list->medicamente[index2] = med;
}

int destructor(Lista *list) {
    free(list->medicamente);
    return 1;
}