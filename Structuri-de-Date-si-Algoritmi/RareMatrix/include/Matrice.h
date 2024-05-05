#pragma once

typedef int TElem;

#define NULL_TELEMENT 0

// Struct to represent a triplet <line, column, value>
struct Triplet {
    int line;
    int column;
    TElem value;

    Triplet(int line, int column, TElem value = NULL_TELEMENT) : line{line}, column{column}, value{value} {}
};

// Linked list node
struct Node {
    Triplet triplet;
    Node *next;

    explicit Node(const Triplet &t) : triplet{t}, next{nullptr} {}
};

// Hash table with separate chaining
class HashMap {
  private:
    int capacity;
    int size;
    Node **buckets;

    /**
     * Returns a hash position.
     * @param line the number of lines.
     * @param column the number of columns.
     * @return a hash for the line and column given.
     * @complexity T(1)
     */
    int hashFunction(int line, int column) const;

  public:
    /**
     * The constructor for the hash map.
     * @param capacity the max size for the hashmap array.
     * @complexity T(1)
     */
    explicit HashMap(int capacity);

    /*
     * The destructor for the hash map.
     */
    ~HashMap();

    /**
     * Insert a triplet into the hash table.
     * @param triplet the element you want to insert.
     * @complexity T(1)
     */
    void insert(const Triplet &triplet);

    /**
     * Get the value of a triplet from the hash table.
     * @param linie the line of the element you want.
     * @param coloana the column of the element you want.
     * @return the value of the element on the line and column given.
     * @complexity O(n), where n is the number of elements with the same hash.
     */
    int getValue(int linie, int coloana) const;
};

class Matrice {
  private:
    int line_count;
    int column_count;
    HashMap table;

  public:

    /**
     * The constructor for the matrix.
     * @param nrLinii the number of lines desired.
     * @param nrColoane the number of column desired.
     * @raise invalid_argument exception if the nrLinii <= 0 or nrColoane <= 0.
     * @complexity T(1)
     */
    Matrice(int nrLinii, int nrColoane);

    /**
     * The default destructor.
     */
    ~Matrice() = default;

    /**
     * Gets the element on the position given.
     * @param i the line number.
     * @param j the column number.
     * @return the element on the position given.
     * @raise out_of_range exception if i and j are not in the matrix.
     * @complexity O(n), where n is the number of elements with the same hash.
     */
    TElem element(int i, int j) const;

    /**
     * Getter for the number of lines.
     * @return the number of lines in the matrix.
     */
    int nrLinii() const;

    /**
     * Getter for the number of columns.
     * @return the number of columns in the matrix.
     */
    int nrColoane() const;

    /**
     * Modifies the element on the position given.
     * @param i the line number.
     * @param j the column number.
     * @param new_value the value you want to replace your element with.
     * @return the old element that was modified.
     * @raise out_of_range exception if i and j are not in the matrix.
     * @complexity O(n), where n is the number of elements with the same hash.
     */
    TElem modifica(int i, int j, TElem new_value);
};