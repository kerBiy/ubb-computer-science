#include "IteratorMultime.h"
#include <exception>

IteratorMultime::IteratorMultime(const Multime &m) : mult(m), curent(nullptr), top(0) {
    prim();
}

void IteratorMultime::push_left(TreeNode *node) {
    while (node != nullptr) {
        stack[top++] = node;
        node = node->left;
    }
}

void IteratorMultime::prim() {
    top = 0;
    push_left(mult.root);
    urmator();
}

void IteratorMultime::urmator() {
    if (top == 0) {
        curent = nullptr;
        return;
    }
    curent = stack[--top];
    push_left(curent->right);
}

bool IteratorMultime::valid() const {
    return curent != nullptr;
}

TElem IteratorMultime::element() const {
    if (!valid()) {
        throw std::exception();
    }
    return curent->value;
}

