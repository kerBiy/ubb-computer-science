#pragma once

typedef int TElem;

bool rel(TElem, TElem);

class IteratorMultime;

struct TreeNode {
    TElem value;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(TElem elem, TreeNode *left = nullptr, TreeNode *right = nullptr)
        : value(elem), left(left), right(right) {}
};

class Multime {
    friend class IteratorMultime;

  private:
    TreeNode *root;

    TreeNode *addHelper(TreeNode *node, TElem elem, bool &isAdded);
    TreeNode *deleteHelper(TreeNode *node, TElem elem, bool &isDeleted);
    TreeNode *searchHelper(TreeNode *node, TElem elem) const;

    int getSize(TreeNode *node) const;
    TreeNode *getMinim(TreeNode *node) const;
    TreeNode *deleteMinim(TreeNode *node);

  public:
    Multime();

    /**
    * Adds an element to the set.
    * @param element The element to be added.
    * @return True if the element was successfully added, false if the element already exists in the set.
    * @complexity O(log n), where n is the number of elements in the set.
    */
    bool adauga(TElem element);

    /**
    * Removes an element from the set.
    * @param element The element to be removed.
    * @return True if the element was successfully removed, false if the element does not exist in the set.
    * @complexity O(log n), where n is the number of elements in the set.
    */
    bool sterge(TElem element);

    /**
     * Searches for an element in the set.
     * @param element The element to search for.
     * @return True if the element exists in the set, false otherwise.
     * @complexity O(log n), where n is the number of elements in the set.
     */
    bool cauta(TElem element) const;

    /**
     * Returns the number of elements in the set.
     * @return The number of elements in the set.
     * @complexity O(1).
     */
    int dim() const;

    /**
     * Checks if the set is empty.
     * @return True if the set is empty, false otherwise.
     * @complexity O(1).
     */
    bool vida() const;

    /**
     * Creates an iterator for the set.
     * @return An iterator for the set.
     * @complexity O(1).
     */
    IteratorMultime iterator() const;

    ~Multime();
    void destroy(TreeNode *node);

    // New function

    /**
     * Deletes all of the elements in [a, b] range
     * @param a the min of range
     * @param b the max of range
     * @return the number of deleted elements
     * @complexity O((a + b) * log n)
     */
    int eliminaInterval(int a, int b);
};
