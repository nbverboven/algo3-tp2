#include "AgmMethod.h"

#ifndef PRIM_H_
#define PRIM_H_

/**
 * Resuelve el problema del arbol generador minimo
 * con el metodo de Prim.
 */
class Prim : public AgmMethod {
public:
    /**
     * Constructor.
     */
    Prim(int n, int m, std::vector<Edge>& edges);

    /**
     * Destructor
     */
    virtual ~Prim();

    /**
     * Calcula un arbol generador minimo.
     */
    virtual Agm getAGM();

private:
    int n_;
    int m_;
    std::vector<Edge>& edges_;
};

#endif
