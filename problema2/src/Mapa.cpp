#include "Grafo.h"

Grafo::Grafo() : n(0), m(0){

}

Grafo::Grafo(const std::vector<Edge> &edges, int cant_vertices) {
	this->n = cant_vertices;
	this->m = edges.size();
	this->costoAristas.resize(this->n);

	for (unsigned int i = 0; i < this->n; ++i) {
		this->costoAristas[i].resize(n, std::numeric_limits<int>::max());
		this->costoAristas[i][i] = 0;
	}

	for (unsigned int i = 0; i < this->m; ++i) {
		this->costoAristas[edges[i].getA()][edges[i].getB()] = edges[i].getCost();
		this->aristas.push_back(std::make_tuple(edges[i].getA(), edges[i].getB()));
	}
}

int Grafo::getCantVertices() const {
	return n;
}

int Grafo::getCantAristas() const {
	return m;
}

int Grafo::getCostoVertice(int i) const {
	return costoVertices[i];
}

int Grafo::getCostoArista(int a, int b) const {
	return costoAristas[a][b];
}

vector< tuple<int,int> > Grafo::getAristas() const {
	return aristas;
}

vector< vector< int > > Grafo::getMatrizAdyacencia() const {
    return costoAristas;
}


Grafo* Grafo::getInstanceFromInput(){
	Grafo *ret = new Grafo();
	int a, b, c;
	cin >> ret->n >> ret->m;
	
	ret->costoAristas.resize(ret->n);
	ret->costoVertices.resize(ret->n);
	ret->aristas.resize(ret->m);

	int int_max = std::numeric_limits<int>::max();
	unsigned int i;
	for(i=0; i < ret->n; i++){
		//Inicializo la matriz con el maximo valor representable (infinito)
		ret->costoAristas[i].resize(ret->n, int_max);
		//No existen las aristas que salgan y entren al mismo nodo
		ret->costoAristas[i][i] = 0;
	}
	
	//lleno los vertices
	for(i=0; i < ret->n; i++){
		cin >> c;
		ret->costoVertices[i] = c;
	}
	
	//lleno las aristas
	for(i=0; i < ret->m; i++){
		cin >> a >> b >> c;
		ret->costoAristas[a][b] = c;
		ret->costoAristas[b][a] = c;
		ret->aristas[i] = make_tuple(a,b);
	}

	return ret;
}

void Grafo::print(){
	cout << (*this) << endl;
}


ostream& operator<<(std::ostream &output, const Grafo &grafo){
	output << "Grafo " << grafo.n << ", " << grafo.m << endl;

	output << " vertices: [";
	for(unsigned int i=0; i< grafo.n; i++){
		if(i!=0)
			output << ", ";
		output << grafo.costoVertices[i];
	}
	output << "]" << endl;

	output << " aristas: [";
	tuple<int,int> tpl;
	for(unsigned int i=0; i < grafo.m; i++){
		if(i!=0)
			output << ", ";

		tpl = grafo.aristas[i];
		int c = grafo.costoAristas[get<0>(tpl)][get<1>(tpl)];

		output << "(" << get<0>(tpl) << "," << get<1>(tpl) << "," << c << ")";
	}
	output << "]" << endl;

	return output;
}