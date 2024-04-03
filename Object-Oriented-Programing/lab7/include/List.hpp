//
// Created by Alex Balta on 02.04.2024.
//

#pragma once

#include <cstddef>

template<typename TElem>
class Iterator;

/*
 * List hpp
 */

template<typename TElem>
class List {
private:
    size_t len; // Current length of the list
    size_t capacity; // Current capacity of the list
    TElem *items; // Array to store list elements

    /**
     * Helper function to resize the list when needed.
     */
    void resizeList();

public:
    /**
     * Default constructor.
     */
    List();

    /**
     * Copy constructor.
     * @param other The list to be copied.
     */
    List(const List &other);

    /**
     * Destructor.
     */
    ~List();

    /**
     * Assignment operator.
     * @param other The list to be assigned.
     * @return Reference to the assigned list.
     */
    List &operator=(const List &other);

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
    TElem &get(size_t position) const;

    /**
     * Sets the element at the specified position.
     * @param position The position at which to set the element.
     * @param element The element to set.
     */
    void set(size_t position, const TElem &element);

    /**
     * Returns the current size of the list.
     * @return The number of elements in the list.
     */
    size_t size() const;

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
 * List cpp
 */

template<typename TElem>
List<TElem>::List() : len{0}, capacity{1}, items{new TElem[1]} {}

template<typename TElem>
List<TElem>::List(const List<TElem> &other) {
    items = new TElem[other.capacity];

    for (size_t i = 0; i < other.len; ++i) {
        items[i] = other.items[i];
    }

    len = other.len;
    capacity = other.capacity;
}

template<typename TElem>
List<TElem> &List<TElem>::operator=(const List<TElem> &other) {
    if (this == &other) {
        return *this;
    }

    delete[] items;
    items = new TElem[other.capacity];

    for (size_t i = 0; i < other.len; ++i) {
        items[i] = other.items[i];
    }

    len = other.len;
    capacity = other.capacity;
    return *this;
}

template<typename TElem>
List<TElem>::~List() {
    delete[] items;
}

template<typename TElem>
void List<TElem>::push_back(const TElem &element) {
    if (len == capacity) {
        resizeList();
    }

    items[len++] = element;
}

template<typename TElem>
void List<TElem>::erase(Iterator<TElem> iterator) {
    if (!iterator.valid() || iterator == end()) {
        throw std::out_of_range("Iterator is not valid or at the end of the list");
    }

    auto nextIt = iterator;
    nextIt.next();

    while (nextIt != end()) {
        *iterator = *nextIt;
        ++iterator;
        ++nextIt;
    }

    len--;
}


template<typename TElem>
TElem &List<TElem>::get(size_t position) const {
    return items[position];
}

template<typename TElem>
void List<TElem>::set(size_t position, const TElem &element) {
    items[position] = element;
}

template<typename TElem>
size_t List<TElem>::size() const {
    return len;
}

template<typename TElem>
void List<TElem>::resizeList() {
    capacity *= 2;
    auto temp = new TElem[capacity];
    for (size_t i = 0; i < len; ++i) {
        temp[i] = items[i];
    }

    delete[] items;
    items = temp;
}

template<typename TElem>
Iterator<TElem> List<TElem>::begin() {
    return Iterator<TElem>(*this);
}

template<typename TElem>
Iterator<TElem> List<TElem>::end() {
    return Iterator<TElem>(*this, len);
}

/*
 * Iterator hpp
 */

template<typename TElem>
class Iterator {
private:
    const List<TElem> &list; // Reference to the list being iterated
    size_t index; // Current index of the iterator within the list
public:
    /**
     * Constructor with list reference parameter
     * @param list a reference to the list that is being iterated
     */
    explicit Iterator(List<TElem> &list);

    /**
     * Constructor with list reference and starting index parameters
     * @param list a reference to the list that is being iterated
     * @param index a position in the list
     */
    Iterator(List<TElem> &list, size_t index);

    /**
     * Checks if the iterator is still within the bounds of the list.
     * @return true if the iterator is valid, false otherwise.
     */
    bool valid() const;

    /**
    * Retrieves the element at the current iterator position.
    * @return Reference to the element at the current iterator position.
    */
    TElem &element() const;

    /**
     * Moves the iterator to the next element in the list.
     */
    void next();

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
Iterator<TElem>::Iterator(List<TElem> &list) : list{list}, index{0} {}

template<typename TElem>
Iterator<TElem>::Iterator(List<TElem> &list, size_t index) : list{list}, index{index} {}

template<typename TElem>
bool Iterator<TElem>::valid() const {
    return index < list.len;
}

template<typename TElem>
TElem &Iterator<TElem>::element() const {
    return list.items[index];
}

template<typename TElem>
void Iterator<TElem>::next() {
    index++;
}

template<typename TElem>
TElem &Iterator<TElem>::operator*() {
    return element();
}

template<typename TElem>
Iterator<TElem> &Iterator<TElem>::operator++() {
    next();
    return *this;
}

template<typename TElem>
bool Iterator<TElem>::operator==(const Iterator<TElem> &other) {
    return index == other.index;
}

template<typename TElem>
bool Iterator<TElem>::operator!=(const Iterator<TElem> &other) {
    return index != other.index;
}