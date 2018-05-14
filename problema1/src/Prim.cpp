#include "Prim.h"
#include <iostream>
#include <utility>
#include <limits>

/**
 * Constructor.
 */
Prim::Prim(int n, int m, std::vector<Edge>& edges):n_(n),m_(m),edges_(edges) {
}

/**
 * Destructor
 */
Prim::~Prim() {
}

/**
 * Calcula un arbol generador minimo.
 */
Agm Prim::getAGM() {

    // convierte la lista completa de aristas a una lista de adyacencias
    // de la forma a -> [<b, costo>]
    std::vector<std::vector<std::pair<int, int>>> adjacencyList(n_);
    for(int i = 0; i < m_; ++i) {
        const Edge& e = edges_[i];
        adjacencyList[e.getA()].push_back(std::make_pair(e.getB(), e.getCost()));
        adjacencyList[e.getB()].push_back(std::make_pair(e.getA(), e.getCost()));
    }

    std::vector<bool> insideTree(n_, false);
    std::vector<int> parent(n_, -1);
    std::vector<int> key(n_, std::numeric_limits<int>::max());

    // arbitrariamente, arranco el agm por el 0
    parent[0] = 0;
    key[0] = -1;

    for (int i = 0; i < n_-1; ++i) {

        // busco el minimo de la frontera
        int minVertex;
        int minimumKey = std::numeric_limits<int>::max();
        for (int vertex = 0; vertex < n_; ++vertex) {
            if (!insideTree[vertex] && key[vertex] < minimumKey) {
                minVertex = vertex;
                minimumKey = key[vertex];
            }
        }

        // lo marco como incluido en el arbol
        insideTree[minVertex] = true;

        // actualizo el valor de key de los adyacentes a vertex
        for (std::pair<int, int>& adjacent: adjacencyList[minVertex]) {
            if (!insideTree[adjacent.first] && adjacent.second < key[adjacent.first]) {
                parent[adjacent.first] = minVertex;
                key[adjacent.first] = adjacent.second;
            }
        }
    }

    std::vector<Edge> edges;
    double weight = 0;
    for (int i = 1; i < n_; ++i) {
        edges.push_back(Edge(i, parent[i], key[i]));
        weight += key[i];
    }
    return Agm(edges, weight);
}

