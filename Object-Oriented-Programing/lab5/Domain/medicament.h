//
// Created by h on 3/8/24.
//

#ifndef MEDICAMENT_H
#define MEDICAMENT_H
typedef struct {
    int id;
    char nume[50];
    float concentratie;
    int cantitate;
} Medicament;

/// Getter id
/// @param m medicament
/// @return id medicament
int get_id(Medicament *m);

/// Getter nume
/// @param m medicament
/// @return nume medicament
char *get_nume(Medicament *m);

/// Getter concentratie
/// @param m medicament
/// @return concentratie medicament
float get_concentratie(Medicament *m);

/// Getter cantitate
/// @param m medicament
/// @return cantitate medicament
int get_cantitate(Medicament *m);

/// Setter nume
/// @param m medicament
/// @param nume nume nou
void set_nume(Medicament *m, char *nume);

/// Setter concentratie
/// @param m medicament
/// @param concentratie concentratie noua
void set_concentratie(Medicament *m, float concentratie);

/// Setter cantitate
/// @param m medicament
/// @param cantitate cantitate noua
void set_cantitate(Medicament *m, int cantitate);

/// Creaza medicament
/// @param id  id medicament
/// @param nume nume medicament
/// @param concentratie concentratie medicament
/// @param cantitate cantitate medicament
/// @return medicament creat
Medicament createMedicament(int id, char *nume, float concentratie, int cantitate);

/// Alocheaza vectorul dinamic
/// @return adresa medicamentului de pe heap
Medicament *allocateMedicament();

/// Mareste vectorul dinamic
/// @return 1 daca s a realocat 0 daca nu
int reallocMedicament(Medicament **med, int n);

#endif //MEDICAMENT_H
