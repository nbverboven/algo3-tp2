#include "../Algoritmos.h"

double subestimacionDistancia(int &inicio, int &final){


}

int AEstrellaAux(int &inicio, int &final, Grafo &grafo){

    int m = grafo.getCantAristas();
    int n = grafo.getCantVertices();
    auto aristas = grafo.getAristas();
    set nodos_evaluados;
    set nodos_no_evaluados;
    nodos_no_evaluados.insert(inicio);

    vector<int> distancia(n, numeric_limits<int>::max());
    distancia[inicio] = 0;

    vector<double> subestimacion_distancia;
    subestimacion_distancia[inicio] = subestimacionDistancia(inicio, final);

    int nodo_actual;
    int distancia_temp;

    while(!nodos_no_evaluados.empty()){
        nodo_actual = distance(subestimacion_distancia.begin(),
                               min_element(subestimacion_distancia.begin(), subestimacion_distancia.end()));
        nodos_no_evaluados.erase(nodo_actual);
        nodos_evaluados.insert(nodo_actual);

        for(tuple<int,int> &a : aristas){
            if(get<0>(a) == nodo_actual){
                if(not nodos_evaluados.find(get<1>(a)) and not nodos_no_evaluados.find(get<1>(a))){
                    nodos_no_evaluados.insert(get<1>(a));
                }

                distancia_temp = distancia[nodo_actual] + getCostoArista(get<0>(a), get<1>(a));
                if(distancia_temp < distancia[get<1>(a)]){
                    distancia[get<1>(a)] = distancia_temp;
                    subestimacion_distancia[get<1>(a)] = distancia_temp + subestimacionDistancia(get<1>(a), final);
                }
            }
        }
    }

    return distancia[final];
}

void AEstrella(vector<vector<int>> &dist_matrix, const Grafo &grafo){

    for(int inicio=0; inicio < n; ++inicio){
        for(int final=0; final < n; ++final){
            if(inicio != final){
                dst_matrix[inicio][final] = AEstrellaAux(inicio, final, grafo);
            } else {
                dst_matrix[inicio][final] = 0;
            }
        }
    }
}

