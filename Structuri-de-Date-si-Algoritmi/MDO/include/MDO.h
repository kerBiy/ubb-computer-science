#pragma once

#include <utility>
#include <vector>

typedef int TCheie;
typedef int TValoare;

#include <utility>

typedef std::pair<TCheie, TValoare> TElem;

class IteratorMDO;

struct Nod {
    TElem element;
    Nod *next;

    explicit Nod(TElem e, Nod *urm = nullptr) : element(std::move(e)), next(urm) {}
};

typedef bool(*Relatie)(TCheie, TCheie);

class MDO {
    friend class IteratorMDO;

private:
    Relatie rel;
    Nod *head;
public:
    /**
     * The constructor
     * @param r the relation
     * @complexity T(1)
     */
    explicit MDO(Relatie r);

    /**
     * Appends to the list respecting the relation
     * @param c the key
     * @param v the value
     * @complexity - BC: T(1): the pair fits right at the beginning of the list
     *             - WC: T(n): the pair fits at the end of the list
     *             => AC: O(n), where n is the current number of nodes in the list
     */
    void adauga(TCheie c, TValoare v);

    /**
     * Searches the list for all the elements with c as key
     * @param c the key
     * @return a vector with all the values having c as their key
     * @complexity - T(n), where n is the number of nodes
     */
    std::vector<TValoare> cauta(TCheie c) const;

    /**
     * Appends to the back of the list
     * @param c the key
     * @param v the value
     * @return true if there have been a deletion false otherwise
     * @complexity - BC: T(1): the pair is at the beginning of the list
     *             - WC: T(n): the pair is at the end of the list
     *             => AC: O(n), where n is the current number of nodes in the list
     */
    bool sterge(TCheie c, TValoare v);

    /**
     * Getter for the size of the dict
     * @return the size of the dict
     * @complexity T(1)
     */
    int dim() const;

    /**
     * Sees if the list hast no elements
     * @return true if there are no elements in the list, false otherwise
     * @complexity T(1)
     */
    bool vid() const;

    /**
     * Makes a iterator for the list
     * @return an iterator for the list
     */
    IteratorMDO iterator() const;

    /**
     * Destructor of the dict
     * @complexity - T(n), where n is the number of nodes in the list
     */
    ~MDO();

    /**
     * Serches for all the elements that have keys in the [a, b] range
     * @param a the smallest key
     * @param b the biggest key
     * @return a vector containing the searched elements
     * @complexity - T(n), where n is the number of nodes
     */
    std::vector<TElem> inRange(TCheie a, TCheie b);
};
