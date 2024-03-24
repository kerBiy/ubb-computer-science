//
// Created by h on 3/8/24.
//
#include "medicament.h"

#include <stdlib.h>
#include <string.h>

int get_id(Medicament *m) {
    return m->id;
}

char *get_nume(Medicament *m) {
    return m->nume;
}

float get_concentratie(Medicament *m) {
    return m->concentratie;
}

int get_cantitate(Medicament *m) {
    return m->cantitate;
}

void set_nume(Medicament *m, char *nume) {
    strncpy(m->nume, nume, 50);
}

void set_concentratie(Medicament *m, float concentratie) {
    m->concentratie = concentratie;
}

void set_cantitate(Medicament *m, int cantitate) {
    m->cantitate = cantitate;
}

Medicament createMedicament(int id, char *nume, float concentratie, int cantitate) {
    Medicament m;
    m.id = id;
    set_nume(&m, nume);
    set_concentratie(&m, concentratie);
    set_cantitate(&m, cantitate);

    return m;
}

Medicament *allocateMedicament() {
    //alocates account array
    Medicament *a = (Medicament *) malloc(1 * sizeof(Medicament));
    return a;

}

int reallocMedicament(Medicament **a, int n) {
    //reallocates accounts array by 1
    n++;
    *a = (Medicament *) realloc(*a, n * sizeof(Medicament));
    if (*a == NULL) {

        return 0;
    }
    return n;

}

