#include "ShortestPath.h"

/**
 * Constructor.
 */
ShortestPath::ShortestPath() {

}

/**
 * Destructor.
 */
ShortestPath::~ShortestPath() {

}

/**
 * Metodo auxiliar para armar el grafo en niveles en base a las rutas existentes
 * y los costos de la nafta en cada ciudad.
 */
std::vector<std::vector<double>> ShortestPath::armarGrafoEnNiveles(std::vector<Ruta>& rutas,
    std::vector<int> costos,
    int n) {

    // es de n*61 porque hay 61 copias de cada ciudad,
    // correspondientes a los 61 niveles
    std::vector<std::vector<double>> distancias(n*61, std::vector<double>(n*61, std::numeric_limits<double>::infinity()));

    // pone ceros en las diagonales
    for (int i = 0; i < n*61; ++i) {
        distancias[i][i] = 0;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 60; ++j){
            // agrega los costos de cargar nafta entre una ciudad de un nivel
            // y la misma ciudad de un nivel mas arriba
            distancias[(i*61)+j][(i*61)+j+1] = costos[i];
        }
    }

    for (Ruta& r: rutas) {
        int a_i = r.obtenerCiudadA();
        int b_i = r.obtenerCiudadB();
        int litros = r.obtenerLitros();
        for (int nivel = 0; nivel < 61; ++nivel) {
            if (nivel - litros >= 0) {
                // agrega el costo del viaje entre dos ciudades, para
                // el caso en que la nafta alcance (se agrega en las dos
                // posiciones de la matriz en esta representacion)
                distancias[(a_i*61)+nivel][(b_i*61)+nivel-litros] = 0;
                distancias[(b_i*61)+nivel][(a_i*61)+nivel-litros] = 0;
            }
        }
    }

    return distancias;
}

/**
 * Metodo auxiliar para armar el grafo en niveles como la lista de todas las aristas,
 * necesario para implementar las dos versiones de Dijkstra.
 */
std::vector<Edge> ShortestPath::armarGrafoEnNivelesComoListaDeAristas(std::vector<Ruta>& rutas,
    std::vector<int> costos,
    int n) {

    std::vector<Edge> aristas;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 60; ++j){
            // agrega los costos de cargar nafta entre una ciudad de un nivel
            // y la misma ciudad de un nivel mas arriba
            aristas.push_back(Edge((i*61)+j, (i*61)+j+1, costos[i]));
        }
    }

    for (Ruta& r: rutas) {
        int a_i = r.obtenerCiudadA();
        int b_i = r.obtenerCiudadB();
        int litros = r.obtenerLitros();
        for (int nivel = 0; nivel < 61; ++nivel) {
            if (nivel - litros >= 0) {
                // agrega el costo del viaje entre dos ciudades, para
                // el caso en que la nafta alcance
                aristas.push_back(Edge((a_i*61)+nivel, (b_i*61)+nivel-litros, 0));
                aristas.push_back(Edge((b_i*61)+nivel, (a_i*61)+nivel-litros, 0));
            }
        }
    }


    return aristas;
}
