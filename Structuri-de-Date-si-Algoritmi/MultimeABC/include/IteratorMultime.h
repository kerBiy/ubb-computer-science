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
    void prim();
    void urmator();
    bool valid() const;
    TElem element() const;
};

