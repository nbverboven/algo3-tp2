#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <tuple>
#include <vector>
#include <limits>
#include <utility>
#include <forward_list>
#include <algorithm>
#include <cassert>
#include "../../problema1/src/Edge.h"
#include "../../problema1/src/DisjointSet.h"

using namespace std;

class Grafo {
public:

	/**
	 * Constructor.
	 */
	Grafo();
	Grafo(std::vector<Edge> v);

	/**
	 * Getters & Setters
	 */
	int getCantVertices();
	int getCantAristas();
	int getCostoVertice(int i);
	int getCostoArista(int a, int b);
	vector< tuple<int,int> > getAristas();


	/**
	 * LLena el vector de tuplas pasado como parámetro desde el standart input,
	 * con los valores correspondientes según el enunciado.
	 */
	static Grafo& getInstanceFromInput();

	void print();

	friend ostream& operator<<(std::ostream &output, const Grafo &grafo);

	/**
	 * Algoritmos para calcular el camino mínimo desde todos los
	 * vértices hacia todos los vértices.
	 * Devuelven el resultado modificando la matriz pasada por parámetro
	 */
	void Dijkstra(std::vector<std::vector<int>> &v) const;
	void DijkstraPQ(std::vector<std::vector<int>> &v) const;
	void BellmanFord(std::vector<std::vector<int>> &v) const;
	void AEstrella(std::vector<std::vector<int>> &v) const;
	void FloydWarshall(std::vector<std::vector<int>> &v) const;
	void Dantzig(std::vector<std::vector<int>> &v) const;

private:

	unsigned int n; //Cantidad de vertices
	unsigned int m; //Cantidad de aristas
	vector< tuple<int,int > > aristas;
	vector< vector< int > > costoAristas;
	vector< int > costoVertices;

};


#endif /* GRAFO_H */
