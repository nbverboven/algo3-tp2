#include <vector>
#include <limits>
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

protected:
    /**
     * Metodo auxiliar para armar el grafo en niveles en base a las rutas existentes
     * y los costos de la nafta en cada ciudad.
     */
    std::vector<std::vector<int>> armarGrafoEnNiveles(std::vector<Ruta>& rutas,
        std::vector<int> costos,
        int n);
};

#endif
