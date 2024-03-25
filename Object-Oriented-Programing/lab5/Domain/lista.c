//
// Created by h on 3/8/24.
//

#include "lista.h"

#include <string.h>
#include <stdlib.h>

int get_len(Lista *lista) {
    return lista->len;
}

void set_len(Lista *lista, int len) {
    lista->len = len;
}

void push(Lista *lista, void *item) {
    if (lista->len >= lista->capacity) {
        lista->capacity *= 2;
        lista->items = realloc(lista->items, lista->capacity * sizeof(void *));
    }

    lista->items[lista->len++] = item;
}

void pop(Lista *lista, int id) {

    int len = get_len(lista);
    for (int i = 0; i < len; i++) {
        if (get_medicament(lista, i)->id == id) {
            free(lista->items[i]);
            for (int j = i + 1; j < len; j++) {
                lista->items[j - 1] = lista->items[j];
            }
            lista->len -= 1;
            return;
        }
    }
}

Lista *createLista() {
    Lista *list = (Lista *) malloc(sizeof(Lista));
    set_len(list, 0);
    list->capacity = 1;
    list->items = (void **) malloc(list->capacity * sizeof(void *));
    return list;
}

Lista *deepCopy(Lista *oldList) {
    Lista *newList = (Lista *) malloc(sizeof(Lista));

    newList->capacity = oldList->capacity;
    newList->len = oldList->len;
    newList->items = (void **) malloc(oldList->capacity * sizeof(void *));

    for (int i = 0; i < oldList->capacity; ++i) {
        if (i < oldList->len) {
            Medicament *oldMed = (Medicament *) oldList->items[i];

            int id = get_id(oldMed);

            char nume[50];
            strcpy(nume, oldMed->nume);

            float concentratie = get_concentratie(oldMed);

            int cantitate = get_cantitate(oldMed);

            Medicament *newMed = createMedicament(id, nume, concentratie, cantitate);
            newList->items[i] = newMed;
        } else {
            newList->items[i] = NULL;
        }
    }
    return newList;
}

Medicament *get_medicament(Lista *lista, int index) {
    return (Medicament *) lista->items[index];
}

void listswap(Lista *list, int index1, int index2) {
    void *med = list->items[index1];
    list->items[index1] = list->items[index2];
    list->items[index2] = med;
}

int destructor(Lista *list) {
    if (list) {
        for (int i = 0; i < list->len; ++i) {
            if (list->items[i]) {
                free(list->items[i]);
            }
        }
        free(list->items);
        free(list);
        return 1;
    }
    return 0;
}