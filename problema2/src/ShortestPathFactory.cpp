#include "ShortestPathFactory.h"
#include "Dantzig.h"

/**
 * Devuelve el algoritmo para resolver camino minimo
 * correspondiente al nombre pasado por parametro
 */
ShortestPath* ShortestPathFactory::crearAlgoritmo(std::string nombre) {
    if (nombre == "dantzig") {
        return new Dantzig();
    }
    return NULL;
}
