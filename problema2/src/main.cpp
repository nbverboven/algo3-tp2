#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <chrono>

#include "Parser.h"
#include "ShortestPathFactory.h"


int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cout << "uso: " << argv[0] << " dijkstra|dijkstra-pq|a|bellmanFord|floydWarshall|dantzig" << std::endl;
        return 1;
    }

    Parser p;
    p.parsearArgumentos();

    std::vector<Ruta>& rutas = p.obtenerRutas();
    std::vector<int>& costos = p.obtenerCostos();
    int n = p.obtenerCiudades();
    std::unique_ptr<ShortestPath> algoritmo(ShortestPathFactory::crearAlgoritmo(argv[1]));

    return 0;
}

