#include "ShortestPathFactory.h"
#include "Dantzig.h"
#include "FloydWarshall.h"
#include "Dijkstra.h"
#include "DijkstraPQ.h"

/**
 * Devuelve el algoritmo para resolver camino minimo
 * correspondiente al nombre pasado por parametro
 */
ShortestPath* ShortestPathFactory::crearAlgoritmo(std::string nombre) {
    if (nombre == "dantzig") {
        return new Dantzig();
    } else if (nombre == "floydWarshall") {
        return new FloydWarshall();
    } else if (nombre == "dijkstra") {
        return new Dijkstra();
    } else if (nombre == "dijkstra-pq") {
        return new DijkstraPQ();
    }
    return NULL;
}
