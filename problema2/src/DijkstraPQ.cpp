#include "DijkstraPQ.h"
#include <tuple>
#include <algorithm>
#include <cmath>

/**
 * Constructor.
 */
DijkstraPQ::DijkstraPQ() {

}

/**
 * Destructor.
 */
DijkstraPQ::~DijkstraPQ() {

}

/**
 * Metodo polimorfico para resolver el problema
 * de camino minimo usando Dijkstra con priority queue.
 */
std::vector<std::vector<double>> DijkstraPQ::resolver(std::vector<Ruta>& rutas, std::vector<int> costos, int n) {
    int N = n*61;

    // Convierte la lista completa de aristas a una lista de adyacencias
    // de la forma a -> [<b, costo>]
    // std::vector<Edge> edges = this->armarGrafoEnNivelesComoListaDeAristas(rutas, costos, n);
    std::vector<std::vector<double>> distancias = this->armarGrafoEnNiveles(rutas, costos, n);
    std::vector<std::vector<double>> resultado(N, std::vector<double>(N, 0));
    for (int i = 0; i < N; ++i) {
        DijkstraPQAux(resultado[i], i, distancias);
    }
    return resultado;
}

/**
 * Funcion auxiliar para comparar pares.
 */
bool comparePairs(const std::pair<double,int> &a, const std::pair<double,int> &b) {
    return a > b;
}

/**
 * Funcion auxiliar que corre Dijsktra con priority queue sobre un vertice.
 * Se usa para correr Dijkstra secuencialmente sobre todos los vertices del grafo.
 */
void DijkstraPQ::DijkstraPQAux(std::vector<double> &min_path_len,
    int vertex,
    std::vector<std::vector<double>>& distancias) {

    int N = distancias.size();
    // int max_int = std::numeric_limits<int>::max();

    // not_added es un vector de tuplas (a, b), donde
    // (longitud del camino mínimo hasta un vértice, número de vértice)
    std::vector<std::pair<double,int>> not_added;

    for (int i = 0; i < N; ++i) {
        min_path_len[i] = distancias[vertex][i]; // graph.getCostoArista(vertex, i);
        if (i != vertex) {
            not_added.push_back(std::make_pair(min_path_len[i], i));
        }
    }

    // Convierto al vector de pares en un minHeap
    // El élemento más prioritario será aquel cuyo camino desde
    // vertex posea la menor longitud
    std::make_heap(not_added.begin(), not_added.end(), comparePairs);

    while (!not_added.empty()) {
        // Busco la longitud del camino mínimo entre el
        // vértice original y uno que no haya sido agregado
        // a la solución
        pop_heap(not_added.begin(), not_added.end());
        std::pair<double,int> minimum = not_added.back();
        not_added.pop_back();

        int vertex_to_add = minimum.second;

        // Actualizo, si correspondiese, la longitud del
        // camino mínimo desde vertex hasta los sucesores
        // del vértice que agrego
        for (std::pair<double,int> &node : not_added) {
            double dir_path_len = distancias[vertex_to_add][node.second]; // graph.getCostoArista(vertex_to_add, node.second);
            double alt_path_len = minimum.first + dir_path_len;

            if (!std::isinf(dir_path_len) && !std::isinf(minimum.first) && (alt_path_len < min_path_len[node.second])) {
                min_path_len[node.second] = alt_path_len;
                node.first = alt_path_len;
            }
        }

        // Restauro la propiedad de heap
        std::make_heap(not_added.begin(), not_added.end(), comparePairs);
    }

}
