#include "ShortestPath.h"

#ifndef DANTZIG_H
#define DANTZIG_H

class Dantzig : public ShortestPath {
public:

    /**
     * Constructor.
     */
    Dantzig();

    /**
     * Destructor.
     */
    virtual ~Dantzig();

    /**
     * Metodo para resolver camino minimo usando Dantzig.
     */
    virtual void resolver(std::vector<Ruta>& rutas, std::vector<int> costos, int n);

};

#endif
