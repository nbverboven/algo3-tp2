#include "AEstrella.h"
#include <cmath>
#include <set>

/**
 * Constructor.
 */
AEstrella::AEstrella() {

}

/**
 * Destructor.
 */
AEstrella::~AEstrella() {

}

/**
 * Metodo para resolver camino minimo usando A*.
 */
std::vector<std::vector<double>> AEstrella::resolver(std::vector<Ruta>& rutas, std::vector<int> costos, int n){

    std::vector<std::vector<double>> resultado(n, std::vector<double>(n, std::numeric_limits<double>::max()));

    double subestimacion_distancia = rutas[0].obtenerLitros();
    for(auto &r : rutas){
        if(r.obtenerLitros() < subestimacion_distancia)
            subestimacion_distancia = r.obtenerLitros();
    }

    for(int vertex=0; vertex < n; ++vertex){
        AEstrellaAux(resultado[vertex], rutas, costos, subestimacion_distancia,
                     vertex, n);
    }

    return  resultado;
}

/**
 * Funcion auxiliar que corre A* sobre un vertice. Se usa para
 * correr A* secuencialmente sobre todos los vertices del grafo.
 */
void AEstrella::AEstrellaAux(std::vector<double>& caminoMin, std::vector<Ruta>& rutas, std::vector<int>& costos,
                  double& subestimacion, int& vertex, int& n){

    std::set<int> nodos_evaluados;
    std::set<int> nodos_no_evaluados;
    nodos_no_evaluados.insert(vertex);

    caminoMin[vertex] = 0;

    int nodo_actual;
    double distancia_temp;

    std::vector<double> subestimacion_distancia(n, std::numeric_limits<double>::max());
    subestimacion_distancia[vertex] = subestimacion;
    while(!nodos_no_evaluados.empty()){
        //El nodo a evaluar será el de menor distancia subestimada hacia el nodo final, dentro de los nodos no evaluados
        nodo_actual = distance(subestimacion_distancia.begin(),
                               min_element(subestimacion_distancia.begin(), subestimacion_distancia.end()));
        nodos_no_evaluados.erase(nodo_actual); //Borro al nodo actual de los no evaluados
        nodos_evaluados.insert(nodo_actual); //Marco al nodo actual como evaluado

        for(auto &r : rutas){
            int ciudadA = r.obtenerCiudadA();
            int ciudadB = r.obtenerCiudadB();
            if(ciudadA == nodo_actual){
                if(!nodos_evaluados.count(ciudadB) and !nodos_no_evaluados.count(ciudadB)){
                    nodos_no_evaluados.insert(ciudadB);

                    distancia_temp = caminoMin[nodo_actual] + r.obtenerLitros()*costos[ciudadB];
                    if(distancia_temp < caminoMin[ciudadB]){
                    caminoMin[ciudadB] = distancia_temp; //Costo de ir hasta la ciudad B
                    subestimacion_distancia[ciudadB] = caminoMin[ciudadB] + subestimacion; //Subestimacion de distancia hasta la ciudad B
                    }
                }
            }
        }
        subestimacion_distancia[nodo_actual] = std::numeric_limits<double>::max(); //Para que no se vuelva a elegir como nodo actual
    }
}
