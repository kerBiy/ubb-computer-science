#pragma once

typedef int TElem;

//typedef bool (*Relatie)(TElem, TElem);

bool rel(TElem, TElem);

class IteratorMultime;

class Multime {
    friend class IteratorMultime;

private:
    TElem *items;
    int size;
    int capacity;

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
};
