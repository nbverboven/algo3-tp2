#include "Dantzig.h"

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
std::vector<std::vector<int>> Dantzig::resolver(std::vector<Ruta>& rutas, std::vector<int> costos, int n) {
    std::vector<std::vector<int>> L = this->armarGrafoEnNiveles(rutas, costos, n);
    int N = n*61; // el tamaño de la matriz L es n*61, por los niveles

    for (int k=1; k < N; ++k) {
        for (int i=1; i <= k; i++) {
            for (int j=1; j <= k; i++) {
                L[i][k+1] = std::min(L[i][j], L[j][k+1]);
                L[k+1][i] = std::min(L[k+1][j], L[j][i]);
            }
        }

        //veo que la diagonal no sea negativa
        for (int i=1; i<=k; ++i) {
            if (std::min(L[k+1][i], L[i][k+1]) < 0) {
                throw "hay ciclos de longitud negativa"; //paro aca, hay circuitos de longitud negativa
            }
        }

        for (int i=1; i <= k; ++i) {
            for (int j=1; j <= k; ++i) {
                L[i][j] = std::min(L[i][j], L[i][k+1] + L[k+1][j]);
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
