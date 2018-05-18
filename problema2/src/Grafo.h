#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <tuple>
#include <vector>
#include <limits>
#include <utility>
#include <algorithm>
#include <cassert>
#include "../../problema1/src/Edge.h"

using namespace std;

class Grafo {
public:

	/**
	 * Constructor.
	 */
	Grafo();
	Grafo(const std::vector<Edge> &edges, int cant_vertices);

	/**
	 * Getters & Setters
	 */
	int getCantVertices() const;
	int getCantAristas() const;
	int getCostoVertice(int i) const;
	int getCostoArista(int a, int b) const;
	vector< tuple<int,int> > getAristas();
	vector< vector< int > > getMatrizAdyacencia() const;

	/**
	 * LLena el vector de tuplas pasado como parámetro desde el standart input,
	 * con los valores correspondientes según el enunciado.
	 */
	static Grafo* getInstanceFromInput();

	void print();

	friend ostream& operator<<(std::ostream &output, const Grafo &grafo);

private:

	unsigned int n; //Cantidad de vertices
	unsigned int m; //Cantidad de aristas
	vector< tuple<int,int > > aristas;
	vector< vector< int > > costoAristas;
	vector< int > costoVertices;

};


#endif /* GRAFO_H */
