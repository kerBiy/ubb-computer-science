#pragma once
#include "Multime.h"

typedef int TElem;

class IteratorMultime {
    friend class Multime;

  private:
    const Multime &mult;
    TreeNode *curent;
    TreeNode *stack[100];
    TElem top;

    void push_left(TreeNode *node);

    explicit IteratorMultime(const Multime &m);

  public:
    /**
     * Moves the iterator to the first element in the set.
     * @complexity O(log n), where n is the number of elements in the set.
     */
    void prim();

    /**
     * Moves the iterator to the next element in the set.
     * @complexity O(1) on average.
     */
    void urmator();

    /**
     * Checks if the iterator is valid (i.e., not at the end).
     * @return True if the iterator is valid, false otherwise.
     * @complexity T(1).
     */
    bool valid() const;

    /**
     * Returns the element currently pointed to by the iterator.
     * @return The element currently pointed to by the iterator.
     * @raise std::exception if the iterator is not valid.
     * @complexity T(1).
     */
    TElem element() const;
};

