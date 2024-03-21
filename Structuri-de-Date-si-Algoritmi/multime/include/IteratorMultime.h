#pragma once

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
    TElem element() const;
};
