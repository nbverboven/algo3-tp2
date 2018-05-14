#include <vector>

#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

class DisjointSet {

public:
    /**
     * Constructor.
     */
    DisjointSet(int n);

    /**
     * Destructor.
     */
    ~DisjointSet();

    /**
     * Devuelve el representante de x.
     */
    int Find(int x);

    /**
     * Une los conjuntos donde estan x e y.
     */
    void Union(int x, int y);


private:
    std::vector<int> parent_;
};

#endif
