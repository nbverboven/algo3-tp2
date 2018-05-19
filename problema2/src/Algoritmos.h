#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include "Mapa.h"

/**
 * Algoritmos para calcular el camino mínimo desde todos los
 * vértices hacia todos los vértices.
 * Devuelven el resultado modificando la matriz pasada por parámetro
 */
void Dijkstra(std::vector<std::vector<int>> &v, const Grafo &grafo);
void DijkstraPQ(std::vector<std::vector<int>> &v, const Grafo &grafo);
void BellmanFord(std::vector<std::vector<int>> &v, const Grafo &grafo);
void AEstrella(std::vector<std::vector<int>> &v, const Grafo &grafo);
void FloydWarshall(std::vector<std::vector<int>> &v, const Grafo &grafo);
void Dantzig(std::vector<std::vector<int>> &v, const Grafo &grafo);

#endif
