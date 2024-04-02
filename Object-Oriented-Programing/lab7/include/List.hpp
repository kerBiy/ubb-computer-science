//
// Created by Alex Balta on 02.04.2024.
//

#pragma once

#include <cstddef>

template<typename TElem>
class Iterator;

template<typename TElem>
class List {
private:
    size_t len;
    size_t capacity;
    TElem *items;

    void resizeList();

public:
    List();

    List(const List &other);

    ~List();

    List &operator=(const List &other);

    void pushBack(const TElem &element);

    TElem &get(size_t position) const;

    void set(size_t position, const TElem &element);

    size_t size() const;

    friend class Iterator<TElem>;

    Iterator<TElem> begin();

    Iterator<TElem> end();
};

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
    return *this;
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
void List<TElem>::pushBack(const TElem &element) {
    if (len == capacity) {
        resizeList();
    }

    items[len++] = element;
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

// NIGGer

template<typename TElem>
class Iterator {
private:
    const List<TElem> &list;
    size_t index = 0;
public:
    explicit Iterator(List<TElem> &list);

    Iterator(List<TElem> &list, size_t index);

    bool valid() const;

    TElem &element() const;

    void next();

    TElem &operator*();

    Iterator &operator++();

    bool operator==(const Iterator &other);

    bool operator!=(const Iterator &other);
};

template<typename TElem>
Iterator<TElem>::Iterator(List<TElem> &list) : list{list} {}

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