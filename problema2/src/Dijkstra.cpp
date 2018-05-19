#include "Dijkstra.h"
#include <tuple>

/**
 * Constructor.
 */
Dijkstra::Dijkstra() {

}

/**
 * Destructor.
 */
Dijkstra::~Dijkstra() {

}

/**
 * Metodo polimorfico para resolver el problema
 * de camino minimo con Dijkstra.
 */
std::vector<std::vector<double>> Dijkstra::resolver(std::vector<Ruta>& rutas, std::vector<int> costos, int n) {
    std::vector<Edge> edges = this->armarGrafoEnNivelesComoListaDeAristas(rutas, costos, n);
    int N = n*61; // el tamaño de la matriz L es n*61, por los niveles

    // Convierte la lista completa de aristas a una lista de adyacencias
    // de la forma a -> [<b, costo>]
    std::vector<std::vector<std::tuple<int, int>>> adjacencyList(N);

    for(Edge& e: edges) {
        adjacencyList[e.getA()].push_back(std::make_tuple(e.getB(), e.getCost()));
        adjacencyList[e.getB()].push_back(std::make_tuple(e.getA(), e.getCost()));
    }

    std::vector<std::vector<double>> distancias = this->armarGrafoEnNiveles(rutas, costos, n);

    std::vector<std::vector<double>> resultado(N, std::vector<double>(N, 0));
    for (int i = 0; i < N; ++i) {
        DijkstraAux(resultado[i], i, distancias, adjacencyList);
    }
    return resultado;

}

/**
 * Funcion auxiliar que corre Dijsktra sobre un vertice. Se usa para
 * correr Dijkstra secuencialmente sobre todos los vertices del grafo.
 */
void Dijkstra::DijkstraAux(std::vector<double>& min_path_len,
    int vertex,
    std::vector<std::vector<double>>& distancias,
    std::vector<std::vector<std::tuple<int, int>>> adjacencyList) {

    int max_int = std::numeric_limits<int>::max();
    int N = distancias.size();

    std::vector<int> not_added;
    for (int i = 0; i < N; ++i) {
        min_path_len[i] = distancias[vertex][i]; // g.getCostoArista(vertex, i);
        if (i != vertex) {
            not_added.push_back(i);
        }
    }

    while (!not_added.empty()) {
        // Busco la longitud del camino mínimo entre el
        // vértice original y uno que no haya sido agregado
        // a la solución
        int minimum = max_int;
        int minimum_index = 0;

        for (unsigned int i = 0; i < not_added.size(); ++i) {
            if (min_path_len[not_added[i]] <= minimum) {
                minimum = min_path_len[not_added[i]];
                minimum_index = i;
            }
        }

        int vertex_to_add = not_added[minimum_index];
        not_added[minimum_index] = not_added[not_added.size()-1];
        not_added.pop_back();

        // Actualizo, si correspondiese, la longitud del camino mínimo desde
        // vertex hasta los sucesores del vértice que agrego
        for (std::tuple<int,int> &adj_node : adjacencyList[vertex_to_add]) {
            int dir_path_len = std::get<1>(adj_node);
            int alt_path_len = minimum + dir_path_len;

            if (minimum != max_int && alt_path_len < min_path_len[std::get<0>(adj_node)]) {
                min_path_len[std::get<0>(adj_node)] = alt_path_len;
            }
        }
    }

}
