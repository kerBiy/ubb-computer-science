#pragma once
#include <utility>

#define NIL (-1)

typedef int TElem;
typedef int TPrioritate;

typedef std::pair<TElem, TPrioritate> Element;

typedef bool (*Relatie)(TPrioritate p1, TPrioritate p2);

class CP {
  private:

    struct Node {
        Element element;
        int next;
        int prev;

        Node() : element{std::make_pair(NIL, NIL)}, next{NIL}, prev{NIL} {}
    };

    int size;
    int capacity;
    Node *items;

    int head;
    int tail;
    Relatie rel;

    void resize_enqueue();

  public:
    /**
     * Constructor for CP
     * @param r The relation function pointer
     * @complexity T(1)
     */
    CP(Relatie r);

    /**
     * Adds an element with a priority to the priority queue
     * @param e The element to be added
     * @param p The priority of the element
     * @complexity - Best Case: T(1): Adding to an empty queue
     *             - Worst Case: T(n): Adding to the end of the queue
     *             => Amortized Complexity: O(n), where n is the current number of elements in the queue
     */
    void adauga(TElem e, TPrioritate p);

    /**
     * Retrieves the element with the highest priority from the queue
     * @return The element with the highest priority
     * @throws std::exception if the queue is empty
     * @complexity T(1)
     */
    Element element() const;

    /**
     * Removes and returns the element with the highest priority from the queue
     * @return The element with the highest priority
     * @throws std::exception if the queue is empty
     * @complexity T(1)
     */
    Element sterge();

    /**
     * Checks if the priority queue is empty
     * @return true if the queue is empty, false otherwise
     * @complexity T(1)
     */
    bool vida() const;

    /**
     * Destructor for CP
     * @complexity T(1)
     */
    ~CP();

    /**
     * Changes a priority from an existing element
     * @param e The element to be added
     * @param pn The new priority of the element
     * @return the priority being updated or NIL if the element does not exist
     * @complexity - Best Case: T(1): Changing the head with the same priority as before
     *             - Worst Case: T(n): Changing the tail with a new priority
     *             => Complexity: O(n), where n is the current number of elements in the queue
     */
    TPrioritate schimbaPrioritate(TElem e, TPrioritate pn);
};
