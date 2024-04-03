#pragma once

#include "MDO.h"


class IteratorMDO {
    friend class MDO;

private:
    /**
     * The constructor
     * @param dict the dictionary of the iterator
     * @complexity T(1)
     */
    explicit IteratorMDO(const MDO &dict);

    const MDO &dict;
    Nod *current;

public:
    /**
     * Setter for the current to point to the first element in the dict
     * @complexity T(1)
     */
    void prim();

    /**
     * Updates to current to point to the next element in the dict
     * @complexity T(1)
     */
    void urmator();

    /** Sees if the current pointer is valid
     * @return true if the pointer is not nullptr, false otherwise
     * @complexity T(1)
    */
    bool valid() const;

    /**
     * Getter for the current node
     * @complexity T(1)
     */
    TElem element() const;
};

