#include "Algoritmos.h"

void DijkstraAux(std::vector<int> &min_path_len, int vertex, const Grafo &g) {
	int n = g.getCantVertices();
	assert(vertex >= 0);
	assert(vertex < n);

	std::vector<int> not_added;
	int max_int = std::numeric_limits<int>::max();

	// Convierte la lista completa de aristas a una lista de adyacencias
	// de la forma a -> [<b, costo>]
	std::vector<std::tuple<int,int>> edges = g.getAristas();
	std::vector<std::vector<std::tuple<int, int>>> adjacencyList(g.getCantVertices());

	for(int i = 0; i < g.getCantAristas(); ++i) {
		std::tuple<int, int> e = edges[i];

		if (g.getCostoArista(get<0>(e), get<1>(e)) != max_int) {
			adjacencyList[get<0>(e)].push_back(std::make_tuple(get<1>(e), g.getCostoArista(get<0>(e), get<1>(e))));
		}

		if (g.getCostoArista(get<1>(e), get<0>(e)) != max_int) {
			adjacencyList[get<1>(e)].push_back(std::make_tuple(get<0>(e), g.getCostoArista(get<1>(e), get<0>(e))));
		}
	}

	for (int i = 0; i < n; ++i) {
		min_path_len[i] = g.getCostoArista(vertex, i);

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
			int dir_path_len = get<1>(adj_node);
			int alt_path_len = minimum + dir_path_len;

			if (minimum != max_int && alt_path_len < min_path_len[get<0>(adj_node)]) {
				min_path_len[get<0>(adj_node)] = alt_path_len;
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


bool compare_pairs(const std::pair<int,int> &a, const std::pair<int,int> &b) {
	return a > b;
}


void DijkstraPQAux(std::vector<int> &min_path_len, int vertex, const Grafo &graph) {
	int n = graph.getCantVertices();
	assert(vertex >= 0);
	assert(vertex < n);

	// not_added es un vector de tuplas (a, b), donde
	// (longitud del camino mínimo hasta un vértice, número de vértice)
	std::vector<std::pair<int,int>> not_added;
	int max_int = std::numeric_limits<int>::max();

	// Convierte la lista completa de aristas a una lista de adyacencias
	// de la forma a -> [<b, costo>]
	std::vector<std::tuple<int,int>> edges = graph.getAristas();
	std::vector<std::vector<std::tuple<int, int>>> adjacencyList(graph.getCantVertices());

	for(int i = 0; i < graph.getCantAristas(); ++i) {
		std::tuple<int, int> e = edges[i];

		if (graph.getCostoArista(get<0>(e), get<1>(e)) != max_int) {
			adjacencyList[get<0>(e)].push_back(std::make_tuple(get<1>(e), graph.getCostoArista(get<0>(e), get<1>(e))));
		}

		if (graph.getCostoArista(get<1>(e), get<0>(e)) != max_int) {
			adjacencyList[get<1>(e)].push_back(std::make_tuple(get<0>(e), graph.getCostoArista(get<1>(e), get<0>(e))));
		}
	}

	for (int i = 0; i < n; ++i) {
		min_path_len[i] = graph.getCostoArista(vertex, i);

		if (i != vertex) {
			not_added.push_back(std::make_pair(min_path_len[i], i));
		}
	}

	// Convierto al vector de pares en un minHeap
	// El élemento más prioritario será aquel cuyo camino desde
	// vertex posea la menor longitud
	std::make_heap(not_added.begin(), not_added.end(), compare_pairs);

	while (!not_added.empty()) {
		// Busco la longitud del camino mínimo entre el
		// vértice original y uno que no haya sido agregado
		// a la solución
		pop_heap(not_added.begin(), not_added.end());
		std::pair<int,int> minimum = not_added.back();
		not_added.pop_back();

		int vertex_to_add = minimum.second;

		// Actualizo, si correspondiese, la longitud del
		// camino mínimo desde vertex hasta los sucesores
		// del vértice que agrego
		for (std::pair<int,int> &node : not_added) {
			int dir_path_len = graph.getCostoArista(vertex_to_add, node.second);
			int alt_path_len = minimum.first + dir_path_len;

			if (dir_path_len != max_int && minimum.first != max_int && alt_path_len < min_path_len[node.second]) {
				min_path_len[node.second] = alt_path_len;
			}
		}

		// Restauro la propiedad de heap
		std::make_heap(not_added.begin(), not_added.end(), compare_pairs);
	}
}


void DijkstraPQ(std::vector<std::vector<int>> &v, const Grafo &grafo) {
	int n = grafo.getCantVertices();
	assert(n > 0);

	for (int i = 0; i < n; ++i) {
		DijkstraPQAux(v[i], i, grafo);
	}
}
