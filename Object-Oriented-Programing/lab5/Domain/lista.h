//
// Created by h on 3/8/24.
//

#ifndef LISTA_H
#define LISTA_H

#include "medicament.h"

typedef struct {
    void **medicamente;
    int len;
    int capacity;
} Lista;

///
/// @param lista lista de medicamente
/// @return returneaza len
int get_len(Lista *lista);

///
/// @param lista lista de medicamente
/// @param len lungimea noua a listei
void set_len(Lista *lista, int len);

///
/// @param lista lista de medicamente
/// @param index pozitia elementului
/// @return returneaza medicamentul de la pozitia i
Medicament *get_medicament(Lista *lista, int index);

/// Adauga medicament in listsa
/// @param lista lista de medicamente
/// @param medicament medicament nou
void push(Lista *lista, void *item);

/// Sterge medicamentul cu id-ul furnizat
/// @param lista lista de medicamente
/// @param id id ul medicamentului care sa fie sters
void pop(Lista *lista, int id);

/// Interschimba 2 elemente
/// @param list lista de medicamente
/// @param index1 index medicament 1
/// @param index2 index medicament 2
void listswap(Lista *list, int index1, int index2);

/// Creaza o lista
/// @return Returneaza lista
Lista createLista();

/// Distruge o lista
/// @param list lista de medicamente
/// @return 1 daca a fost distrus 0 altfel
int destructor(Lista *list);

int equal_medicaments(Medicament *med1, Medicament *med2);

#endif //LISTA_H
