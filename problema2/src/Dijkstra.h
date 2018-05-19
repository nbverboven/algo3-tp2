#include "ShortestPath.h"

#ifndef DIJKSTRA_H
#define DIJKSTRA_H

class Dijkstra : public ShortestPath {
public:

    /**
     * Constructor.
     */
    Dijkstra();

    /**
     * Destructor.
     */
    virtual ~Dijkstra();

    /**
     * Metodo polimorfico para resolver el problema
     * de camino minimo. Las clases que implementen esta interfaz
     * deben implementar este metodo.
     */
    virtual std::vector<std::vector<int>> resolver(std::vector<Ruta>& rutas, std::vector<int> costos, int n);
private:
    /**
     * Funcion auxiliar que corre Dijsktra sobre un vertice. Se usa para
     * correr Dijkstra secuencialmente sobre todos los vertices del grafo.
     */
    void DijkstraAux(std::vector<int>& min_path_len,
        int vertex,
        std::vector<std::vector<int>>& distancias,
        std::vector<std::vector<std::tuple<int, int>>> adjacencyList);
};

#endif
