#include "Algoritmos.h"

void DijkstraAux(std::vector<int> &min_path_len, int vertex, const Grafo &grafo) {
	int n = grafo.getCantVertices();
	assert(vertex >= 0);
	assert(vertex < n);

	std::list<int> not_added;

	for (int i = 0; i < n; ++i) {
		min_path_len[i] = grafo.getCostoArista(vertex, i);

		if (i != vertex) {
			not_added.push_front(i);
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
		not_added.erase(minimum_index);

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


void Dijkstra(std::vector<std::vector<int>> &v, const Grafo &grafo) {
	int n = grafo.getCantVertices();
	assert(n > 0);

	for (int i = 0; i < n; ++i) {
		DijkstraAux(v[i], i, grafo);
	}
}


void DijkstraPQAux(std::vector<int> &min_path_len, int vertex, const Grafo &grafo) {
	int n = grafo.getCantVertices();
	assert(vertex >= 0);
	assert(vertex < n);

	std::vector<int> not_added;

	for (int i = 0; i < n; ++i) {
		min_path_len[i] = grafo.getCostoArista(vertex, i);

		if (i != vertex) {
			not_added.push_back(i);
		}
	}

	while (!not_added.empty()) {
		// Busco la longitud del camino mínimo entre el
		// vértice original y uno que no haya sido agregado
		// a la solución
		int minimum = std::numeric_limits<int>::max();
		int minimum_index = 0;

		for (unsigned int i = 0; i < not_added.size(); ++i) {
			int node = not_added[i];

			if (min_path_len[node] <= minimum) {
				minimum = min_path_len[node];
				minimum_index = i;
			}
		}

		int vertex_to_add = not_added[minimum_index];

		// Elimino el elemento que ya elegí para agregar a
		// la solución
		int aux = not_added[-1];
		not_added[-1] = not_added[minimum_index];
		not_added[minimum_index] = aux;
		not_added.pop_back();

		// Actualizo, si correspondiese, la longitud del 
		// camino mínimo desde vertex hasta los sucesores
		// del vértice que agrego
		for (unsigned int i = 0; i < not_added.size(); ++i) {
			int node = not_added[i];

			if (grafo.getCostoArista(vertex_to_add, node) < std::numeric_limits<int>::max() &&
				min_path_len[node] > minimum + grafo.getCostoArista(vertex_to_add, node)) {
				min_path_len[node] = minimum + grafo.getCostoArista(vertex_to_add, node); 
			}
		}
	}
}


void DijkstraPQ(std::vector<std::vector<int>> &v, const Grafo &grafo) {
	int n = grafo.getCantVertices();
	assert(n > 0);

	for (int i = 0; i < n; ++i) {
		DijkstraPQAux(v[i], i, grafo);
	}
}


void FloydWarshall(std::vector<std::vector<int>> &dist_matrix, const Grafo &grafo)
{
	int n = grafo.getCantVertices();

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			dist_matrix[i][j] = grafo.getCostoArista(i, j);
		}
	}

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