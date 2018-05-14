#include "DisjointSetCompression.h"

/**
 * Constructor.
 */
DisjointSetCompression::DisjointSetCompression(int n) {
    this->parent_ = std::vector<int>(n);
    this->rank_ = std::vector<int>(n, 0);
    for (int i = 0; i < n; ++i) {
        this->parent_[i] = i;
    }
}

/**
 * Destructor.
 */
DisjointSetCompression::~DisjointSetCompression() {
}

/**
 *
 */
int DisjointSetCompression::Find(int x) {
    if (this->parent_[x] != x) {
        this->parent_[x] = Find(this->parent_[x]);
    }
    return parent_[x];
}

/**
 *
 */
void DisjointSetCompression::Union(int x, int y) {
    int x_root = Find(x);
    int y_root = Find(y);
    if (x_root != y_root) {
        if (this->rank_[x_root] < this->rank_[y_root]) {
            this->parent_[x_root] = y_root;
        } else if (this->rank_[y_root] < this->rank_[x_root]) {
            this->parent_[y_root] = x_root;
        } else {
            this->rank_[x_root] += 1;
            this->parent_[y_root] = x_root;
        }
    }
}
