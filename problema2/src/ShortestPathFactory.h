#include "ShortestPath.h"
#include <string>

#ifndef SHORTEST_PATH_FACTORY
#define SHORTEST_PATH_FACTORY

class ShortestPathFactory {
public:
    /**
     * Devuelve el algoritmo para resolver camino minimo
     * correspondiente al nombre pasado por parametro
     */
    static ShortestPath* crearAlgoritmo(std::string nombre);
};

#endif
