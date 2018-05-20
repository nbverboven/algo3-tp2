#include "BellmanFord.h"
#include <cmath>
#include <tuple>

/**
 * Constructor.
 */
BellmanFord::BellmanFord() {

}

/**
 * Destructor.
 */
BellmanFord::~BellmanFord() {

}

/**
 * Metodo para resolver camino minimo usando Bellman-ford.
 */
std::vector<std::vector<double>> BellmanFord::resolver(std::vector<Ruta>& rutas, std::vector<int> costos, int n) {
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
        BellmanFordAux(resultado[i], i, distancias, adjacencyList);
    }
    
    return resultado;
}

/**
 * Funcin auxiliar que corre Bellman-Ford sobre un vertice. Se usa para 
 * correr Bellman-Ford secuencialmente sobre todos los vertices del grafo. 
 */
void BellmanFord::BellmanFordAux(std::vector<double>& caminoMin, unsigned int vertice, 
    std::vector<std::vector<double>>& distancias, std::vector<std::vector<std::tuple<int, int>>> adjacencyList) {

    unsigned int N = distancias.size();

    //Inicializo el vector en infinito para todas los vertices
    for(unsigned int i=0; i < N; i++){
        if(i!=vertice)
            caminoMin[i] = std::numeric_limits<double>::infinity();
    }
    //La distancia a el mismo es 0
    caminoMin[vertice] = 0;

    std::vector<double> caminoMin_prim;
    //Utilizo el i por si existen ciclos negativos, sino no cortaria nunca
    for(unsigned int i=0; i < N && caminoMin_prim != caminoMin; i++){
        caminoMin_prim = caminoMin;

        //Recorro todas las aristas
        for(unsigned int k=0; k < adjacencyList.size(); k++){
            caminoMin_prim = caminoMin;
            int cantLlegan = adjacencyList[k].size();
            if(k!=vertice){
                for(int j=0; j < cantLlegan; j++){
                    int anterior = std::get<0>(adjacencyList[k][j]);
                    double costo = distancias[anterior][k];

                    if(!std::isinf(caminoMin_prim[anterior])){
                        if(std::isinf(caminoMin[k]))
                            caminoMin[k] = caminoMin_prim[anterior] + costo;
                        else
                            caminoMin[k] = std::min(caminoMin[k], caminoMin_prim[anterior] + costo);
                    }
                }
            }
        }
    }

    //Si quisiera saber si tiene ciclos negativos tendría que volver a recorrer las 
    //aristas y fijarme si encuentro un camino mas corto. Si lo encuentro es porque
    //hay ciclos negativos.

}
