#pragma once

typedef int TElem;

//typedef bool (*Relatie)(TElem, TElem);

<<<<<<< HEAD
=======
// in implementarea operatiilor se va folosi functia (relatia) rel (de ex,
// pentru <=)
//  va fi declarata in .h si implementata in .cpp ca functie externa colectiei
>>>>>>> origin/main
bool rel(TElem, TElem);

class IteratorMultime;

class Multime {
    friend class IteratorMultime;

<<<<<<< HEAD
private:
=======
   private:
    /* aici e reprezentarea */
>>>>>>> origin/main
    TElem *items;
    int size;
    int capacity;

<<<<<<< HEAD
    // TO(size)
    void resize_append();

    // TO(size)
    void resize_delete();

public:
    // TO(1)
    Multime();

    // Complexitate amortizata
    // BC = TO(log size) - cand se insereaza pe prima pozitie (cautarea binara)
    //    = TO(1) - cand elementul deja exista (si nu il adaugam)
    // WC = TO(size) - cand trebuie sa inseram pe prima pozitie
    // C = TO(size) (amortizata)
    bool adauga(TElem e);

    // Complexitate amortizata
    // BC = TO(size) - cand se afla pe ultima pozitie (cautarea binara)
    //    = TO(1) - cand elementul nu exista (si nu il stergem)
    // WC = TO(size) - cand trebuie sa stergem de pe ultima pozitie
    // C = TO(size) (amortizata)
    bool sterge(TElem e);

    // C = O(log size)
    bool cauta(TElem elem) const;

    // TO(1)
    int dim() const;

    // TO(1)
    bool vida() const;

    // TO(1)
    IteratorMultime iterator() const;

    // TO(size) ?
    ~Multime();

    // BC = TO(size * other.size)
    // WC = TO(size * other.size * min{size, output.size})
    // O(min{size, output.size} * size * other.size)
    Multime intersection(Multime &other);
=======
    void resize_append();
    void resize_delete();

   public:
    // constructorul implicit
    Multime();

    // adauga un element in multime
    // returneaza adevarat daca elementul a fost adaugat (nu exista deja in
    // multime)
    bool adauga(TElem e);

    // sterge un element din multime
    // returneaza adevarat daca elementul a existat si a fost sters
    bool sterge(TElem e);

    // verifica daca un element se afla in multime
    bool cauta(TElem elem) const;

    // intoarce numarul de elemente din multime;
    int dim() const;

    // verifica daca multimea e vida;
    bool vida() const;

    // returneaza un iterator pe multime
    IteratorMultime iterator() const;

    // destructorul multimii
    ~Multime();
>>>>>>> origin/main
};
