#include "Multime.h"
#include "IteratorMultime.h"

bool rel(TElem e1, TElem e2) {
    return e1 <= e2;
}

Multime::Multime() : root(nullptr) {}

TreeNode *Multime::addHelper(TreeNode *node, TElem elem, bool &isAdded) {
    if (node == nullptr) {
        isAdded = true;
        return new TreeNode(elem);
    }

    if (rel(elem, node->value)) {
        if (elem == node->value) {
            isAdded = false;
            return node;
        }
        node->left = addHelper(node->left, elem, isAdded);
    } else {
        node->right = addHelper(node->right, elem, isAdded);
    }

    return node;
}

bool Multime::adauga(TElem element) {
    bool added = false;
    root = addHelper(root, element, added);
    return added;
}

TreeNode *Multime::deleteHelper(TreeNode *node, TElem elem, bool &isDeleted) {
    if (node == nullptr) {
        isDeleted = false;
        return nullptr;
    }

    if (rel(elem, node->value)) {
        if (elem == node->value) {
            isDeleted = true;
            if (node->left == nullptr) {
                TreeNode *temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode *temp = node->left;
                delete node;
                return temp;
            } else {
                TreeNode *min = getMinim(node->right);
                node->value = min->value;
                node->right = deleteMinim(node->right);
            }
        } else {
            node->left = deleteHelper(node->left, elem, isDeleted);
        }
    } else {
        node->right = deleteHelper(node->right, elem, isDeleted);
    }

    return node;
}

bool Multime::sterge(TElem element) {
    bool deleted = false;
    root = deleteHelper(root, element, deleted);
    return deleted;
}

TreeNode *Multime::searchHelper(TreeNode *node, TElem elem) const {
    if (node == nullptr || node->value == elem) {
        return node;
    }

    if (rel(elem, node->value)) {
        return searchHelper(node->left, elem);
    } else {
        return searchHelper(node->right, elem);
    }
}

bool Multime::cauta(TElem element) const {
    return searchHelper(root, element) != nullptr;
}

int Multime::getSize(TreeNode *node) const {
    if (node == nullptr) {
        return 0;
    }
    return 1 + getSize(node->left) + getSize(node->right);
}

int Multime::dim() const {
    return getSize(root);
}

bool Multime::vida() const {
    return root == nullptr;
}

IteratorMultime Multime::iterator() const {
    return IteratorMultime(*this);
}

Multime::~Multime() {
    destroy(root);
}

void Multime::destroy(TreeNode *node) {
    if (node != nullptr) {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

TreeNode *Multime::getMinim(TreeNode *node) const {
    while (node->left != nullptr) {
        node = node->left;
    }

    return node;
}

TreeNode *Multime::deleteMinim(TreeNode *node) {
    if (node->left == nullptr) {
        return node->right;
    }

    node->left = deleteMinim(node->left);
    return node;
}

int Multime::eliminaInterval(int a, int b) {
    int count = 0;

    for (int i = a; i <= b; ++i) {
        bool isFound = sterge(i);

        if (isFound) {
            count++;
        }
    }

    return count;
}
