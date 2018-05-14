#include "DisjointSet.h"

/**
 * Constructor.
 */
DisjointSet::DisjointSet(int n) {
    this->parent_ = std::vector<int>(n);
    for (int i = 0; i < n; ++i) {
        this->parent_[i] = i;
    }
}

/**
 * Destructor.
 */
DisjointSet::~DisjointSet() {
}

/**
 *
 */
int DisjointSet::Find(int x) {
    if (x == parent_[x]) {
        return x;
    }
    return Find(parent_[x]);
}

/**
 *
 */
void DisjointSet::Union(int x, int y) {
    int x_root = Find(x);
    int y_root = Find(y);
    this->parent_[x_root] = y_root;
}
