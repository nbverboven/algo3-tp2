#include "ShortestPath.h"

#ifndef FLOYD_WARSHALL_H
#define FLOYD_WARSHALL_H

class FloydWarshall : public ShortestPath {
public:
    /**
     * Constructor.
     */
    FloydWarshall();

    /**
     * Destructor.
     */
    virtual ~FloydWarshall();

    /**
     * Metodo polimorfico para resolver el problema
     * de camino minimo. Las clases que implementen esta interfaz
     * deben implementar este metodo.
     */
    virtual std::vector<std::vector<int>> resolver(std::vector<Ruta>& rutas, std::vector<int> costos, int n);

};

#endif
