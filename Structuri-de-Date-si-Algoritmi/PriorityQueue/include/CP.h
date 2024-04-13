#pragma once
#include <utility>

#define NIL (-1)

typedef int TElem;
typedef int TPrioritate;

typedef std::pair<TElem, TPrioritate> Element;

typedef bool (*Relatie)(TPrioritate p1, TPrioritate p2);

class CP {
  private:

    struct Node {
        Element element;
        int next;
        int prev;

        Node() : element{std::make_pair(NIL, NIL)}, next{NIL}, prev{NIL} {}
    };

    int size;
    int capacity;
    Node *items;

    int head;
    int tail;
    Relatie rel;

    void resize_enqueue();
    void resize_dequeue();

  public:
    //constructorul implicit
    CP(Relatie r);

    //adauga un element in CP
    void adauga(TElem e, TPrioritate p);

    //acceseaza elementul cel mai prioritar in raport cu relatia de ordine
    //arunca exceptie daca CP e vida
    Element element() const;

    //sterge elementul cel mai prioritar si il returneaza
    //arunca exceptie daca CP e vida
    Element sterge();

    //verifica daca CP e vida;
    bool vida() const;

    // destructorul cozii
    ~CP();
};
