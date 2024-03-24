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

void push(Lista *lista, Medicament *medicament) {
    if (lista->len >= lista->capacity) {
        lista->capacity *= 2;
        lista->medicamente = realloc(lista->medicamente, lista->capacity * sizeof(void *));
    }

    lista->medicamente[lista->len++] = (void *) medicament;
}

void pop(Lista *lista, int id) {

    int len = get_len(lista);
    for (int i = 0; i < len; i++) {

        if (get_medicament(lista, i)->id == id) {
            free(get_medicament(lista, i));
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
    list.medicamente = (void **) malloc(1 * sizeof(void *));
    return list;
}

Medicament *get_medicament(Lista *lista, int index) {
    return (Medicament *) lista->medicamente[index];
}

void listswap(Lista *list, int index1, int index2) {
    void *med = list->medicamente[index1];
    list->medicamente[index1] = list->medicamente[index2];
    list->medicamente[index2] = med;
}

int destructor(Lista *list) {
    for (int i = 0; i < list->len; ++i) {
        free(get_medicament(list, i));
    }
    free(list->medicamente);
    return 1;
}