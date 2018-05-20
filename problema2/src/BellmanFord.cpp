#include "BellmanFord.h"
#include <cmath>

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

    std::vector<std::vector<double>> distancias = this->armarGrafoEnNiveles(rutas, costos, n);
    
    std::vector<std::vector<double>> resultado(N, std::vector<double>(N, 0));
    for (int i = 0; i < N; ++i) {
        BellmanFordAux(resultado[i], i, distancias, edges);
    }
    
    return resultado;
}

/**
 * Funcin auxiliar que corre Bellman-Ford sobre un vertice. Se usa para 
 * correr Bellman-Ford secuencialmente sobre todos los vertices del grafo. 
 */
void BellmanFord::BellmanFordAux(std::vector<double>& caminoMin, int vertice, 
    std::vector<std::vector<double>>& distancias, const std::vector<Edge>& edges) {

    int N = distancias.size();

    //Inicializo el vector en infinito para todas los vertices
    for(int i=0; i < N; i++){
        if(i!=vertice)
            caminoMin[i] = std::numeric_limits<double>::infinity();
    }
    //La distancia a el mismo es 0
    caminoMin[vertice] = 0;

    std::vector<double> caminoMin_prim;
    //Utilizo el i por si existen ciclos negativos, sino no cortaria nunca
    for(int i=0; i < N && caminoMin_prim != caminoMin; i++){
        caminoMin_prim = caminoMin;

        for(Edge e: edges) {
            int a = e.getB();
            if(a != vertice){
                int b = e.getA();
                double costo = distancias[b][a];

                if(!std::isinf(caminoMin_prim[b])){
                    if(std::isinf(caminoMin[a]))
                        caminoMin[a] = caminoMin_prim[b] + costo;
                    else
                        caminoMin[a] = std::min(caminoMin[a], caminoMin_prim[b] + costo);
                }
            }
        }
    }

    //Si quisiera saber si tiene ciclos negativos tendría que volver a recorrer las 
    //aristas y fijarme si encuentro un camino mas corto. Si lo encuentro es porque
    //hay ciclos negativos.

}
