//
// Created by h on 3/8/24.
//

#ifndef SERVICE_H
#define SERVICE_H

#include "../Domain/lista.h"
#include "../Domain/medicament.h"
#include "../Validator/validator.h"

///
/// @param list Lista de items
/// @param id id medicament
/// @param nume nume medicament
/// @param concentratie concentratie medicament
/// @param cantitate cantitate medicament
/// @return 0 sau 1 in functie daca medicamentul a fost adaugat in lista
int add_medicament(Lista *list, int id, char *nume, float concentratie, int cantitate);

///
/// @param list lista de items
/// @param id id ul medicamentului care sa fie modificat
/// @param cantitate noua cantitate
/// @return 1 sau 0 in functie de succesul functiei
int modify_quantity(Lista *list, int id, int cantitate);

///
/// @param list lista de items
/// @param id id care sa fie modificat
/// @param nume numele noiu
/// @param concentratie concentratia noua
/// @return 1 sau 0 in functie de succesul functiei
int modify_medicament(Lista *list, int id, char *nume, float concentratie);

///
/// @param list lista de items
/// @param id id de la care sa fie sters tot stockul
/// @return 1 sau 0 in functie de succesul functiei
int delete_all_stock(Lista *list, int id);

/// Filtreaza items dupa o cantitate data
/// @param list lista de items
/// @param cantitate de filtrat
/// @return o lista de items filtrata
Lista *filter_cantitate(Lista *list, int cantitate);

/// FIltreaza items dupa initiala
/// @param list
/// @param initiala
/// @return
Lista *filter_initiala(Lista *list, char initiala);

/// Filtreaza items dupa o concentratie data
/// @param list lista de items
/// @param concentratie de filtrat
/// @return o lista de items filtrata
Lista *filter_concentratie(Lista *list, float concentratie);

/// Verifica daca exista medicamentul cu nume dat
/// @param list lista de items
/// @param nume nume dupa care se cauta
/// @return id-ul medicamentului cu numele
int verify_existence(Lista *list, char *nume);

int nume_cresc(Medicament *m1, Medicament *m2);

int nume_descresc(Medicament *m1, Medicament *m2);

int cantitate_crescator(Medicament *m1, Medicament *m2);

int cantitate_descrescator(Medicament *m1, Medicament *m2);

void sort(Lista *list, int (*functie)(Medicament *m1, Medicament *m2));

// My Code

void updateHistory(Lista *history, Lista *medicamente);

int undo(Lista *history, Lista **medicamente);

#endif //SERVICE_H
