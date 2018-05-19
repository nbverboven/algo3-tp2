#include <vector>
#include "Ruta.h"

#ifndef SHORTEST_PATH
#define SHORTEST_PATH

class ShortestPath {
public:
    /**
     * Constructor.
     */
    ShortestPath();
    /**
     * Destructor.
     */
    virtual ~ShortestPath();
    /**
     * Metodo polimorfico para resolver el problema
     * de camino minimo. Las clases que implementen esta interfaz
     * deben implementar este metodo.
     */
    virtual void resolver(std::vector<Ruta>& rutas, std::vector<int> costos, int n)=0;
};

#endif
