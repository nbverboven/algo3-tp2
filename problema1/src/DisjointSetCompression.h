#include <vector>

#ifndef DISJOINT_SET_COMPRESSION_H
#define DISJOINT_SET_COMPRESSION_H

class DisjointSetCompression {

public:
    /**
     * Constructor.
     */
    DisjointSetCompression(int n);

    /**
     * Destructor.
     */
    ~DisjointSetCompression();

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
    std::vector<int> rank_;
};

#endif
