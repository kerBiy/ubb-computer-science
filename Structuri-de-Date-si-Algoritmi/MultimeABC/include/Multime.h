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

    bool adauga(TElem element);
    bool sterge(TElem element);
    bool cauta(TElem element) const;
    int dim() const;
    bool vida() const;
    IteratorMultime iterator() const;

    ~Multime();
    void destroy(TreeNode *node);
};
