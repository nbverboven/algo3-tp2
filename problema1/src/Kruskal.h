#include "AgmMethod.h"

#ifndef KRUSKAL_H
#define KRUSKAL_H

class Kruskal : public AgmMethod {
public:

    /**
     * Constructor.
     */
    Kruskal(int n, int m, std::vector<Edge>& edges);

    /**
     * Destructor.
     */
    virtual ~Kruskal();

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
