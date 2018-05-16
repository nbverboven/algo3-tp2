#ifndef GRAFO
#define GRAFO

#include <vector>
#include <iostream>
#include <tuple>

using namespace std;

class Grafo {
private:

    unsigned int n; //Cantidad de vertices
    unsigned int m; //Cantidad de aristas
    vector< tuple<int,int > > aristas;
    vector< vector< int > > costoAristas;
	vector< int > costoVertices;

    friend ostream & operator<<(std::ostream & output, const Grafo& grafo);

public:

/**
 * Getters & Setters
 */
int getCantVertices(){
    return n;
}

int getCantAristas(){
    return m;
}

int getCostoVertice(int i){
    return costoVertices[i];
}

int getCostoArista(int a, int b){
    return costoAristas[a][b];
}

vector< tuple<int,int> > getAristas(){
    return aristas;
}


/**
 * LLena el vector de tuplas pasado como parámetro desde el standart input,
 * con los valores correspondientes según el enunciado.
 */
static  Grafo getInstanceFromInput(){
    Grafo ret;
    int a, b, c;
    cin >> ret.n >> ret.m;
    
    ret.costoAristas.resize(ret.n+1);
    ret.costoVertices.resize(ret.n+1);
    ret.aristas.resize(ret.m);

    unsigned int i;
    for(i=0; i <= ret.n; i++)
        ret.costoAristas[i].resize(ret.n+1);
    

    //leno los vertices
    for(i=0; i < ret.n; i++){
        cin >> c;
        ret.costoVertices[i] = c;
    }
    
    //leno las aristas
    for(i=0; i < ret.m; i++){
        cin >> a >> b >> c;
        ret.costoAristas[a][b] = c;
        ret.costoAristas[b][a] = c;
        ret.aristas[i] = make_tuple(a,b);
    }

    return ret;
}

void print(){
    cout << (*this) << endl;
}

};

ostream & operator<<(std::ostream & output, const Grafo& grafo){
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


#endif /* GRAFO */
