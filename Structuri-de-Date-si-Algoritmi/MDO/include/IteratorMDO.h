#pragma once

#include "MDO.h"


class IteratorMDO {
    friend class MDO;

private:
    explicit IteratorMDO(const MDO &dict);

    const MDO &dict;
    Nod *current;

public:
    void prim();

    void urmator();

    bool valid() const;

    TElem element() const;
};

