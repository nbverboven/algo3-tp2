#include "Dantzig.h"
#include <cmath>

/**
 * Constructor.
 */
Dantzig::Dantzig() {

}

/**
 * Destructor.
 */
Dantzig::~Dantzig() {

}

/**
 * Metodo para resolver camino minimo usando Dantzig.
 */
std::vector<std::vector<double>> Dantzig::resolver(std::vector<Ruta>& rutas, std::vector<int> costos, int n) {
    std::vector<std::vector<double>> L = this->armarGrafoEnNiveles(rutas, costos, n);
    int N = n*61; // el tamaño de la matriz L es n*61, por los niveles

    for (int k=0; k < N-1; ++k) {
        for (int i=0; i <= k; i++) {
            double minimum_one = std::numeric_limits<double>::max();
            double minimum_two = std::numeric_limits<double>::max();
            for (int j=0; j <= k; j++) {
                if (!std::isinf(L[i][j]) && !std::isinf(L[j][k+1])) {
                    double value = L[i][j] + L[j][k+1];
                    minimum_one = std::min(minimum_one, value);
                }
                if (!std::isinf(L[k+1][j]) && !std::isinf(L[j][i])) {
                    double value = L[k+1][j] + L[j][i];
                    minimum_two = std::min(minimum_two, value);
                }
            }
            L[i][k+1] = minimum_one;
            L[k+1][i] = minimum_two;
        }

        //veo que la diagonal no sea negativa
        double t = std::numeric_limits<double>::max();
        for (int i=0; i<=k; ++i) {
            if (!std::isinf(L[k+1][i]) && !std::isinf(L[i][k+1])) {
                double value = L[k+1][i] + L[i][k+1];
                t = std::min(t, value);
            }
            if (t < 0) {
                throw "hay ciclos de longitud negativa"; //paro aca, hay circuitos de longitud negativa
            }
        }

        for (int i=0; i <= k; ++i) {
            for (int j=0; j <= k; ++j) {
                if (!std::isinf(L[i][k+1]) && !std::isinf(L[k+1][j])) {
                    double value = L[i][k+1] + L[k+1][j];
                    L[i][j] = std::min(L[i][j], value);
                }
            }
        }

    }
    return L;
}

/*
para k desde 1 a n−1 hacer
    para i desde 1 a k hacer
        Li,k+1 := min 1≤j≤k (Li,j + Lj,k+1)
        Lk+1,i := min 1≤j≤k (Lk+1,j +Lj,i)
    fin para
    t := min 1≤i≤k( Lk+1,i +Li,k+1)
    si t < 0 entonces
        retornar "Hay circuitos de longitud negativa"
    fin si
    para i desde 1 a k hacer
        para j desde 1 a k hacer
            Li,j := min( Li,j , Li,k+1 + Lk+1,j )
            fin para
    fin para
fin para
retornar L
*/
