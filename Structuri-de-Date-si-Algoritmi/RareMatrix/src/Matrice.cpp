#include "Matrice.h"

#include <stdexcept>
#include <iostream>

/*
 * TABELA DE DISPERSIE
 */

int HashMap::hashFunction(int line, int column) const {
    return (line * 31 + column) % capacity;
}

HashMap::HashMap(int capacity) : capacity{capacity}, size{0}, buckets{new Node *[capacity]} {
    for (int i = 0; i < capacity; ++i) {
        buckets[i] = nullptr;
    }
}

HashMap::~HashMap() {
    for (int i = 0; i < capacity; ++i) {
        Node *current = buckets[i];

        while (current != nullptr) {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
    }

    delete[] buckets;
}

void HashMap::insert(const Triplet &triplet) {
    int index = hashFunction(triplet.line, triplet.column);
    Node *new_node = new Node(triplet);

    new_node->next = buckets[index];
    buckets[index] = new_node;

    size++;
}

int HashMap::getValue(int linie, int coloana) const {
    int index = hashFunction(linie, coloana);
    Node *current = buckets[index];

    while (current != nullptr) {
        if (current->triplet.line == linie && current->triplet.column == coloana)
            return current->triplet.value;
        current = current->next;
    }

    return 0;
}

HashMap &HashMap::operator=(HashMap &&other) noexcept {
    if (this == &other) return *this;

    for (int i = 0; i < capacity; ++i) {
        Node *current = buckets[i];
        while (current != nullptr) {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] buckets;

    capacity = other.capacity;
    size = other.size;
    buckets = other.buckets;

    other.capacity = 0;
    other.size = 0;
    other.buckets = nullptr;

    return *this;
}

/*
 * MATRICE RARA
 */

Matrice::Matrice(int nrLinii, int nrColoane) : line_count{nrLinii}, column_count{nrColoane}, table{nrLinii *
    nrColoane} {
    if (nrLinii <= 0 || nrColoane <= 0) {
        throw std::invalid_argument("The number of line and columns should be greater then 0.");
    }
}

TElem Matrice::element(int i, int j) const {
    if (i < 0 || i >= line_count || j < 0 || j >= column_count) {
        throw std::out_of_range("The indexes are not valid.");
    }

    return table.getValue(i, j);
}

int Matrice::nrLinii() const {
    return line_count;
}

int Matrice::nrColoane() const {
    return column_count;
}

TElem Matrice::modifica(int i, int j, TElem new_value) {
    if (i < 0 || i >= line_count || j < 0 || j >= column_count) {
        throw std::out_of_range("The indexes are not valid.");
    }

    TElem old_value = table.getValue(i, j);
    table.insert(Triplet(i, j, new_value));

    return old_value;
}

void Matrice::transpusa() {
    HashMap newTable(column_count * line_count);

    for (int i = 0; i < table.getCapacity(); ++i) {
        Node *current = table.getBuckets()[i];
        while (current != nullptr) {
            Triplet triplet = current->triplet;

            newTable.insert(Triplet(triplet.column, triplet.line, triplet.value));
            current = current->next;
        }
    }

    std::swap(line_count, column_count);
    table = std::move(newTable);
}
