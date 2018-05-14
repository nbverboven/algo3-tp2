#include "AgmMethod.h"

#ifndef KRUSKAL_PATH_COMPRESSION_H
#define KRUSKAL_PATH_COMPRESSION_H

class KruskalPathCompression : public AgmMethod {
public:

    /**
     * Constructor.
     */
    KruskalPathCompression(int n, int m, std::vector<Edge>& edges);

    /**
     * Destructor.
     */
    virtual ~KruskalPathCompression();

    /**
     * Metodo para obtener el AGM de un grafo
     */
    virtual Agm getAGM();

private:
    int n_;
    int m_;
    std::vector<Edge>& edges_;
};

#endif
