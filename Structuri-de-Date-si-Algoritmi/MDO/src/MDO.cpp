#include "IteratorMDO.h"
#include "MDO.h"

#include <iostream>
#include <vector>

MDO::MDO(Relatie r) : rel(r), head(nullptr) {}

void MDO::adauga(TCheie c, TValoare v) {
    TElem elem = {c, v};
    Nod *new_node = new Nod(elem);

    if (head == nullptr || !rel(head->element.first, c)) {
        new_node->next = head;
        head = new_node;
        return;
    }

    Nod *current = head;
    while (current->next != nullptr && rel(current->next->element.first, c)) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
}


std::vector<TValoare> MDO::cauta(TCheie c) const {
    std::vector<TValoare> output;
    Nod *current = head;

    while (current != nullptr) {
        if (current->element.first == c) {
            output.push_back(current->element.second);
        }
        current = current->next;
    }

    return output;
}

bool MDO::sterge(TCheie c, TValoare v) {
    if (head == nullptr) {
        return false;
    }

    TElem elem = {c, v};

    if (head->element == elem) {
        Nod *temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    Nod *current = head;
    while (current->next != nullptr) {
        if (current->next->element == elem) {
            Nod *temp = current->next;
            current->next = current->next->next;
            delete temp;
            return true;
        }
        current = current->next;
    }

    return false;
}

int MDO::dim() const {
    int count = 0;
    Nod *current = head;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}

bool MDO::vid() const {
    return head == nullptr;
}

IteratorMDO MDO::iterator() const {
    return IteratorMDO(*this);
}

MDO::~MDO() {
    Nod *current = head;

    while (current != nullptr) {
        Nod *temp = current;
        current = current->next;
        delete temp;
    }
}

std::vector<TElem> MDO::inRange(TCheie a, TCheie b) {
    std::vector<TElem> output;
    Nod *current = head;

    while (current != nullptr) {
        if (current->element.first >= a && current->element.first <= b) {
            output.push_back(current->element);
        }
        current = current->next;
    }

    return output;
}