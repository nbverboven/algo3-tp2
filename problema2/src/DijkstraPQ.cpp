#include "DijkstraPQ.h"
#include <tuple>
#include <algorithm>

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
    int max_int = std::numeric_limits<int>::max();

    // not_visited es un vector de tuplas (a, b), donde
    // a: longitud del camino mínimo hasta un vértice
    // b: número de dicho vértice
    std::vector<std::pair<int,int>> not_visited;

    for (int i = 0; i < N; ++i) {
        min_path_len[i] = distancias[vertex][i];
        if (i != vertex) {
            not_visited.push_back(std::make_pair(min_path_len[i], i));
        }
    }

    // Convierto al vector de pares en un minHeap
    // El élemento más prioritario será aquel cuyo camino desde
    // vertex posea la menor longitud
    std::make_heap(not_visited.begin(), not_visited.end(), comparePairs);

    while (!not_visited.empty()) {
        // Busco la longitud del camino mínimo entre el
        // vértice original y uno que no haya sido agregado
        // a la solución
        pop_heap(not_visited.begin(), not_visited.end());
        std::pair<int,int> minimum = not_visited.back();
        not_visited.pop_back();

        int vertex_to_add = minimum.second;

        // Actualizo, si correspondiese, la longitud del
        // camino mínimo desde vertex hasta los sucesores
        // del vértice que agrego
        for (std::pair<int,int> &node : not_visited) {
            int dir_path_len = distancias[vertex_to_add][node.second];
            int alt_path_len = minimum.first + dir_path_len;

            if (dir_path_len != max_int && minimum.first != max_int && (alt_path_len < min_path_len[node.second])) {
                min_path_len[vertex_to_add] = minimum.first;
                node.first = alt_path_len;
            }
        }

        // Restauro la propiedad de heap
        std::make_heap(not_visited.begin(), not_visited.end(), comparePairs);
    }

}
