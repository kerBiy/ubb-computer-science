
#include "CP.h"
#include <exception>

CP::CP(Relatie r) : size{0}, capacity{1}, items{new Node[capacity]}, head{NIL}, tail{NIL}, rel{r} {
}

void CP::adauga(TElem e, TPrioritate p) {
    if (size == capacity) {
        resize_enqueue();
    }

    int newNodeIndex = size;
    items[newNodeIndex].element = std::make_pair(e, p);
    size++;

    if (size == 1) {
        head = newNodeIndex;
        tail = newNodeIndex;
        return;
    }

    int current = head;
    int prev = NIL;

    while (current != NIL && rel(items[current].element.second, p)) {
        prev = current;
        current = items[current].next;
    }

    if (prev == NIL) {
        items[newNodeIndex].next = head;
        items[head].prev = newNodeIndex;
        head = newNodeIndex;
    } else if (current == NIL) {
        items[prev].next = newNodeIndex;
        items[newNodeIndex].prev = prev;
        tail = newNodeIndex;
    } else {
        items[prev].next = newNodeIndex;
        items[newNodeIndex].prev = prev;
        items[newNodeIndex].next = current;
        items[current].prev = newNodeIndex;
    }

}

Element CP::element() const {
    if (vida()) {
        throw std::exception();
    }

    return items[head].element;
}

Element CP::sterge() {
    if (vida()) {
        throw std::exception();
    }

    Element deletedElement = items[head].element;

    if (size == 1) {
        head = NIL;
        tail = NIL;
    } else {
        int nextHead = items[head].next;
        items[nextHead].prev = NIL;
        head = nextHead;
    }

    size--;

    return deletedElement;
}

bool CP::vida() const {
    return size == 0;
}

CP::~CP() {
    delete[] items;
}

void CP::resize_enqueue() {
    capacity *= 2;
    auto *new_items = new Node[capacity];

    for (int i = 0; i < size; ++i) {
        new_items[i] = items[i];
    }

    delete[] items;
    items = new_items;
}


