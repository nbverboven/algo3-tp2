#include <queue>
#include "Kruskal.h"
#include "DisjointSet.h"

/**
 * Constructor.
 */
Kruskal::Kruskal(int n, int m, std::vector<Edge>& edges):n_(n),m_(m),edges_(edges) {

}

/**
 * Destructor.
 */
Kruskal::~Kruskal() {
}

/**
 * Metodo para obtener el AGM de un grafo
 */
Agm Kruskal::getAGM() {
    DisjointSet set(n_);
    std::priority_queue<Edge> edges;
    for (Edge& e: edges_) {
        edges.push(e);
    }

    std::vector<Edge> agmEdges;
    double weight = 0;
    while (!edges.empty()) {
        Edge e = edges.top();
        if (set.Find(e.getA()) != set.Find(e.getB())) {
            agmEdges.push_back(e);
            weight += e.getCost();
            set.Union(e.getA(), e.getB());
        }
        edges.pop();
    }
    return Agm(agmEdges, weight);
}
