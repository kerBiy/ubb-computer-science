#pragma once
<<<<<<< HEAD

=======
>>>>>>> origin/main
#include "Multime.h"

// typedef int TElem;

class IteratorMultime {
    friend class Multime;

private:
    // TO(1)
    IteratorMultime(const Multime &m);

    const Multime &mult;

    int index;

public:
    // TO(1)
    void prim();

    // TO(1)
    void urmator();

    // TO(1)
    bool valid() const;

    // TO(1)
=======
   private:
    // constructorul primeste o referinta catre Container
    // iteratorul va referi primul element din container
    IteratorMultime(const Multime &m);

    // contine o referinta catre containerul pe care il itereaza
    const Multime &mult;

    /* aici e reprezentarea  specifica a iteratorului */
    int index;

   public:
    // reseteaza pozitia iteratorului la inceputul containerului
    void prim();

    // muta iteratorul in container
    //  arunca exceptie daca iteratorul nu e valid
    void urmator();

    // verifica daca iteratorul e valid (indica un element al containerului)
    bool valid() const;

    // returneaza valoarea elementului din container referit de iterator
    // arunca exceptie daca iteratorul nu e valid
>>>>>>> origin/main
    TElem element() const;
};
