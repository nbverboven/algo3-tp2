#include "ShortestPath.h"

#ifndef BELLMAN_FORD_H
#define BELLMAN_FORD_H

class BellmanFord : public ShortestPath {
public:

    /**
     * Constructor.
     */
    BellmanFord();

    /**
     * Destructor.
     */
    virtual ~BellmanFord();

    /**
     * Metodo para resolver camino minimo usando Bellman-Ford.
     */
    virtual std::vector<std::vector<double>> resolver(std::vector<Ruta>& rutas, std::vector<int> costos, int n);

private:

    void BellmanFordAux(std::vector<double>& caminoMin, int vertex, std::vector<std::vector<double>>& distancias, const std::vector<Edge>& edges);

};

#endif
