#include "IteratorMDO.h"
#include "MDO.h"

IteratorMDO::IteratorMDO(const MDO &dict) : dict(dict), current(dict.head) {}

void IteratorMDO::prim() {
    current = dict.head;
}

void IteratorMDO::urmator() {
    if (!valid()) {
        throw std::runtime_error("Iterator invalid!");
    }
    current = current->next;
}

bool IteratorMDO::valid() const {
    return current != nullptr;
}

TElem IteratorMDO::element() const {
    if (!valid()) {
        throw std::runtime_error("Iterator invalid!");
    }
    return current->element;
}
