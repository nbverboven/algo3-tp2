#include "ShortestPath.h"

#ifndef DIJKSTRA_PQ
#define DIJKSTRA_PQ

class DijkstraPQ : public ShortestPath {
public:

    /**
     * Constructor.
     */
    DijkstraPQ();

    /**
     * Destructor.
     */
    virtual ~DijkstraPQ();

    /**
     * Metodo polimorfico para resolver el problema
     * de camino minimo. Las clases que implementen esta interfaz
     * deben implementar este metodo.
     */
    virtual std::vector<std::vector<double>> resolver(std::vector<Ruta>& rutas, std::vector<int> costos, int n);
    
private:

    /**
     * Funcion auxiliar que corre Dijsktra con priority queue sobre un vertice.
     * Se usa para correr Dijkstra secuencialmente sobre todos los vertices del grafo.
     */
    void DijkstraPQAux(std::vector<double> &min_path_len,
        int vertex,
        std::vector<std::vector<double>>& distancias);
};

#endif
