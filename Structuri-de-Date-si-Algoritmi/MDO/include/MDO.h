#pragma once

#include <utility>
#include <vector>

typedef int TCheie;
typedef int TValoare;

#include <utility>

typedef std::pair<TCheie, TValoare> TElem;

class IteratorMDO;

struct Nod {
    TElem element;
    Nod *next;

    explicit Nod(TElem e, Nod *urm = nullptr) : element(std::move(e)), next(urm) {}
};

typedef bool(*Relatie)(TCheie, TCheie);

class MDO {
    friend class IteratorMDO;

private:
    Relatie rel;
    Nod *head;
public:

    explicit MDO(Relatie r);

    void adauga(TCheie c, TValoare v);

    std::vector<TValoare> cauta(TCheie c) const;

    bool sterge(TCheie c, TValoare v);

    int dim() const;

    bool vid() const;

    IteratorMDO iterator() const;

    ~MDO();

};
