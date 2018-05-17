#include "Grafo.h"

Grafo::Grafo() : n(0), m(0){

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

vector< tuple<int,int> > Grafo::getAristas(){
	return aristas;
}


Grafo* Grafo::getInstanceFromInput(){
	Grafo *ret = new Grafo();
	int a, b, c;
	cin >> ret->n >> ret->m;
	
	ret->costoAristas.resize(ret->n+1);
	ret->costoVertices.resize(ret->n+1);
	ret->aristas.resize(ret->m);

	unsigned int i;
	for(i=0; i <= ret->n; i++)
		ret->costoAristas[i].resize(ret->n+1);
	

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