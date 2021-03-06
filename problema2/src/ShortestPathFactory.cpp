#include "ShortestPathFactory.h"
#include "Dantzig.h"
#include "FloydWarshall.h"
#include "Dijkstra.h"
#include "DijkstraPQ.h"
#include "BellmanFord.h"
#include "AEstrella.h"

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
    } else if(nombre == "bellmanFord"){
        return new BellmanFord();
    } else if(nombre == "aEstrella"){
        return new AEstrella();
    }
    return NULL;
}
