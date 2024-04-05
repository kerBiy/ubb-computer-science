//
// Created by Alex Balta on 02.04.2024.
//

#pragma once

#include <cstddef>

template<typename TElem>
class Iterator;

/*
 * Vector hpp
 */

template<typename TElem>
class Vector {
private:
    size_t len{0}; // Current length of the list
    size_t capacity{1}; // Current capacity of the list
    TElem *items; // Array to store list elements

    /**
     * Helper function to resize the list when needed.
     */
    void resizeList();

public:
    /**
     * Default constructor.
     */
    Vector();

    /**
     * Copy constructor.
     * @param other The list to be copied.
     */
    Vector(const Vector &other);

    /**
     * Destructor.
     */
    ~Vector();

    /**
     * Assignment operator.
     * @param other The list to be assigned.
     * @return Reference to the assigned list.
     */
    Vector &operator=(const Vector &other);

    /**
     * Adds an element to the end of the list.
     * @param element The element to be added.
     */
    void push_back(const TElem &element);

    /**
     * Removes the element at the position pointed by the iterator.
     * @param iterator The iterator pointing to the element to be removed.
     */
    void erase(Iterator<TElem> iterator);

    /**
    * Retrieves the element at the specified position.
    * @param position The position of the element to retrieve.
    * @return Reference to the element at the specified position.
    */
    TElem &operator[](size_t position);

    /**
     * Sets the element at the specified position given by the iterator.
     * @param iter An iterator pointing to the position at which to set the element.
     * @param element The element to set.
     */
    void set(Iterator<TElem> &iter, const TElem &element);

    /**
     * Returns the current size of the list.
     * @return The number of elements in the list.
     */
    [[nodiscard]] size_t size() const;

    friend class Iterator<TElem>;

    /**
    * Returns an iterator pointing to the beginning of the list.
    * @return An iterator pointing to the beginning of the list.
    */
    Iterator<TElem> begin();

    /**
     * Returns an iterator pointing to the end of the list.
     * @return An iterator pointing to the end of the list.
     */
    Iterator<TElem> end();
};

/*
 * Vector cpp
 */

template<typename TElem>
Vector<TElem>::Vector() : items{new TElem[1]} {}

template<typename TElem>
Vector<TElem>::Vector(const Vector<TElem> &other) : len{other.len}, capacity{other.capacity},
                                                    items{new TElem[other.capacity]} {
    for (size_t i = 0; i < len; ++i) {
        items[i] = other.items[i];
    }
}

template<typename TElem>
Vector<TElem> &Vector<TElem>::operator=(const Vector<TElem> &other) {
    delete[] items;

    items = new TElem[other.capacity];
    len = other.len;
    capacity = other.capacity;

    for (size_t i = 0; i < len; ++i) {
        items[i] = other.items[i];
    }

    return *this;
}

template<typename TElem>
Vector<TElem>::~Vector() {
    delete[] items;
}

template<typename TElem>
void Vector<TElem>::push_back(const TElem &element) {
    if (len == capacity) {
        resizeList();
    }

    items[len++] = element;
}

template<typename TElem>
void Vector<TElem>::erase(Iterator<TElem> iterator) {
    auto nextIt = iterator;
    ++nextIt;

    while (nextIt.valid()) {
        *iterator = *nextIt;
        ++iterator;
        ++nextIt;
    }

    len--;
}

template<typename TElem>
TElem &Vector<TElem>::operator[](size_t position) {
    return items[position];
}

template<typename TElem>
void Vector<TElem>::set(Iterator<TElem> &iter, const TElem &element) {
    *iter = element;
}

template<typename TElem>
size_t Vector<TElem>::size() const {
    return len;
}

template<typename TElem>
void Vector<TElem>::resizeList() {
    capacity *= 2;
    auto temp = new TElem[capacity];
    for (size_t i = 0; i < len; ++i) {
        temp[i] = items[i];
    }

    delete[] items;
    items = temp;
}

template<typename TElem>
Iterator<TElem> Vector<TElem>::begin() {
    return Iterator<TElem>(*this);
}

template<typename TElem>
Iterator<TElem> Vector<TElem>::end() {
    return Iterator<TElem>(*this, len);
}

/*
 * Iterator hpp
 */

template<typename TElem>
class Iterator {
private:
    const Vector<TElem> &list; // Reference to the list being iterated
    size_t index; // Current index of the iterator within the list
public:
    /**
     * Constructor with list reference parameter
     * @param list a reference to the list that is being iterated
     */
    explicit Iterator(Vector<TElem> &list);

    /**
     * Constructor with list reference and starting index parameters
     * @param list a reference to the list that is being iterated
     * @param index a position in the list
     */
    Iterator(Vector<TElem> &list, size_t index);

    /**
     * Checks if the iterator is still within the bounds of the list.
     * @return true if the iterator is valid, false otherwise.
     */
    [[nodiscard]] bool valid() const;

    /**
     * Dereferences the iterator to retrieve the element at the current position.
     * @return Reference to the element at the current iterator position.
     */
    TElem &operator*();

    /**
     * Prefix increment operator to move the iterator to the next position.
     * @return Reference to the iterator after increment.
     */
    Iterator &operator++();

    /**
     * Equality comparison operator.
     * @param other Another iterator to compare with.
     * @return true if the iterators are equal, false otherwise.
     */
    bool operator==(const Iterator &other);

    /**
     * Inequality comparison operator.
     * @param other Another iterator to compare with.
     * @return true if the iterators are not equal, false otherwise.
     */
    bool operator!=(const Iterator &other);
};

/*
 * Iterator cpp
 */

template<typename TElem>
Iterator<TElem>::Iterator(Vector<TElem> &list) : list{list}, index{0} {}

template<typename TElem>
Iterator<TElem>::Iterator(Vector<TElem> &list, size_t index) : list{list}, index{index} {}

template<typename TElem>
bool Iterator<TElem>::valid() const {
    return index < list.len;
}

template<typename TElem>
TElem &Iterator<TElem>::operator*() {
    return list.items[index];
}

template<typename TElem>
Iterator<TElem> &Iterator<TElem>::operator++() {
    index++;
    return *this;
}

template<typename TElem>
bool Iterator<TElem>::operator==(const Iterator<TElem> &other) {
    return index == other.index;
}

template<typename TElem>
bool Iterator<TElem>::operator!=(const Iterator<TElem> &other) {
    return !(*this == other);
}