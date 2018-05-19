#include <vector>
#include <limits>
#include "Ruta.h"
#include "Edge.h"

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
    virtual std::vector<std::vector<double>> resolver(std::vector<Ruta>& rutas, std::vector<int> costos, int n)=0;

protected:
    /**
     * Metodo auxiliar para armar el grafo en niveles en base a las rutas existentes
     * y los costos de la nafta en cada ciudad.
     */
    std::vector<std::vector<double>> armarGrafoEnNiveles(std::vector<Ruta>& rutas,
        std::vector<int> costos,
        int n);

    /**
     * Metodo auxiliar para armar el grafo en niveles como la lista de todas las aristas,
     * necesario para implementar las dos versiones de Dijkstra.
     */
    std::vector<Edge> armarGrafoEnNivelesComoListaDeAristas(std::vector<Ruta>& rutas,
        std::vector<int> costos,
        int n);

};

#endif
