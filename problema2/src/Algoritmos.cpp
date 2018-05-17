#include "Algoritmos.h"

void Dijkstra(std::vector<std::vector<int>> &v, const Grafo &grafo) {
	int n = grafo.getCantVertices();
	assert(n > 0);

	for (int i = 0; i < n; ++i) {
		DijkstraAux(v[i], i, grafo);
	}
}

void DijkstraAux(std::vector<int> &min_path_len, int vertex, const Grafo &grafo) {
	int n = grafo.getCantVertices();
	assert(vertex >= 0);
	assert(vertex < n);

	// std::vector<int> min_path_len(n);
	std::forward_list<int> not_added;

	for (int i = 0; i < n; ++i) {
		min_path_len[i] = grafo.getCostoArista(vertex, i);

		if (i != vertex) {
			not_added.push_front(n-1-i);
		}
	}

	while (!not_added.empty()) {
		// Busco la longitud del camino mínimo entre el
		// vértice original y uno que no haya sido agregado
		// a la solución
		int minimum = std::numeric_limits<int>::max();
		auto minimum_index = not_added.begin();

		for (auto it = not_added.begin(); it != not_added.end(); ++it) {
			int node = *it;

			if (min_path_len[node] <= minimum) {
				minimum = min_path_len[node];
				minimum_index = it;
			}
		}

		int vertex_to_add = *minimum_index;
		not_added.erase_after(minimum_index);

		// Actualizo, si correspondiese, la longitud del 
		// camino mínimo desde vertex hasta los sucesores
		// del vértice que agrego
		for (auto it = not_added.begin(); it != not_added.end(); ++it) {
			if (grafo.getCostoArista(vertex_to_add, *it) < std::numeric_limits<int>::max() &&
				min_path_len[*it] > minimum + grafo.getCostoArista(vertex_to_add, *it)) {
				min_path_len[*it] = minimum + grafo.getCostoArista(vertex_to_add, *it); 
			}
		}
	}
}


void FloydWarshall(std::vector<std::vector<int>> &dist_matrix, const Grafo &grafo)
{
	// std::vector<std::vector<int>> matrix = dist_matrix_;
	// unsigned int n = matrix.size();

	int n = grafo.getCantVertices();

	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			if (i != k && grafo.getCostoArista(i, k) != std::numeric_limits<int>::max()) {
				for (int j = 0; j < n; ++j) {
					if (j != k && j != i) {
						dist_matrix[i][j] = std::min(dist_matrix[i][j], dist_matrix[i][k]+dist_matrix[k][j]);
					}
				}
			}
		}	
	}
}