#include "AEstrella.h"
#include <cmath>
#include <set>
#include <algorithm>

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

    std::vector<std::vector<double>> resultado(n, std::vector<double>(n, 0));

    double subestimacion_distancia = rutas[0].obtenerLitros();
    for(auto &r : rutas){
        if (r.obtenerLitros() < subestimacion_distancia) {
            subestimacion_distancia = r.obtenerLitros();
        }
    }

    for (int inicio=0; inicio < n; ++inicio) {
        for (int fin = inicio+1; fin < n; ++fin) {
        resultado[inicio][fin] = AEstrellaAux(rutas, costos, subestimacion_distancia,
                     inicio, fin, n);
        }
    }

    return resultado;
}

/**
 * Funcion auxiliar que corre A* sobre un vertice. Se usa para
 * correr A* secuencialmente sobre todos los vertices del grafo.
 */
double AEstrella::AEstrellaAux(std::vector<Ruta>& rutas, std::vector<int>& costos,
                  double subestimacion, int inicio, int fin, int n) {

    std::set<int> nodos_evaluados;
    std::set<int> nodos_no_evaluados;
    nodos_no_evaluados.insert(inicio);

    std::vector<double> caminoMin(n, std::numeric_limits<double>::max());
    caminoMin[inicio] = 0;

    std::vector<double> subestimacion_distancia(n, std::numeric_limits<double>::max());
    subestimacion_distancia[inicio] = subestimacion;

    while (!nodos_no_evaluados.empty()) {

        // el nodo a evaluar será el de menor distancia subestimada hacia el nodo final, dentro de los nodos no evaluados
        int nodo_actual = -1;
        double min_distancia = std::numeric_limits<double>::max();
        for (int nodo: nodos_no_evaluados) {
            if (subestimacion_distancia[nodo] < min_distancia) {
                nodo_actual = nodo;
                min_distancia = subestimacion_distancia[nodo];
            }
        }
        if (nodo_actual == fin) {
            // llegue al destino
            return caminoMin[fin];
        }

        nodos_no_evaluados.erase(nodo_actual); // Borro al nodo actual de los no evaluados
        nodos_evaluados.insert(nodo_actual); // Marco al nodo actual como evaluado

        for (auto &r : rutas) {
            // para cada vecino de nodo_actual
            int ciudadA = r.obtenerCiudadA();
            int ciudadB = r.obtenerCiudadB();
            if (ciudadA == nodo_actual || ciudadB == nodo_actual){
                // logica extra para ver cual es el vecino
                int vecino;
                if (ciudadA == nodo_actual) {
                    vecino = ciudadB;
                } else {
                    vecino = ciudadA;
                }

                if (nodos_evaluados.count(vecino) == 0) {
                    nodos_no_evaluados.insert(vecino);
                    double distancia_tentativa = caminoMin[nodo_actual] + r.obtenerLitros()*costos[vecino];
                    if (distancia_tentativa < caminoMin[vecino]){
                        caminoMin[vecino] = distancia_tentativa; //Costo de ir hasta vecino
                        subestimacion_distancia[vecino] = caminoMin[vecino] + subestimacion; //Subestimacion de distancia hasta la ciudad B
                    }
                }
            }
        }
    }
    // este return nunca se ejecuta, se pone para evitar warnings del gcc
    return caminoMin[fin];
}
