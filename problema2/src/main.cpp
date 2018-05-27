#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <chrono>
#include <limits>
#include <cstring>

#include "Parser.h"
#include "ShortestPathFactory.h"


int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cout << "uso: " << argv[0] << " dijkstra|dijkstra-pq|a|bellmanFord|floydWarshall|dantzig|aEstrella" << std::endl;
        return 1;
    }

    // obtiene los parametros del problema
    Parser p;
    p.parsearArgumentos();
    std::vector<Ruta>& rutas = p.obtenerRutas();
    std::vector<int>& costos = p.obtenerCostos();
    int n = p.obtenerCiudades();
    std::unique_ptr<ShortestPath> algoritmo(ShortestPathFactory::crearAlgoritmo(argv[1]));

    // usa la matriz de distancias para reportar los costos minimos
    std::vector<std::vector<double>> distancias = algoritmo->resolver(rutas, costos, n);
    for (int i = 0; i < n; ++i) {
        // i:= identificador de ciudad
        for (int j = i+1; j < n; ++j) {
            if(std::strcmp(argv[1], "aEstrella")) {
                // j:= identificador de la otra ciudad
                double minimoCosto = std::numeric_limits<int>::max();
                for (int nivel = 0; nivel < 61; ++nivel) {
                    double candidato = distancias[i * 61][(j * 61) + nivel];
                    minimoCosto = std::min(minimoCosto, candidato);
                }
                std::cout << i << " " << j << " " << minimoCosto << std::endl;
            } else {
                std::cout << i << " " << j << " " << distancias[i][j] << std::endl;
            }
        }
    }

    return 0;
}

