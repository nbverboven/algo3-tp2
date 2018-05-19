#include "FloydWarshall.h"

/**
 * Constructor.
 */
FloydWarshall::FloydWarshall() {

}

/**
 * Destructor.
 */
FloydWarshall::~FloydWarshall() {

}

/**
 * Metodo polimorfico para resolver el problema
 * de camino minimo. Las clases que implementen esta interfaz
 * deben implementar este metodo.
 */
std::vector<std::vector<int>> FloydWarshall::resolver(std::vector<Ruta>& rutas, std::vector<int> costos, int n) {
    std::vector<std::vector<int>> L = this->armarGrafoEnNiveles(rutas, costos, n);
    int N = n*61; // el tamaño de la matriz L es n*61, por los niveles

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (j != k && j != i) {
                    L[i][j] = std::min(L[i][j], L[i][k]+L[k][j]);
                }
            }
        }
    }
    return L;
}
