#include "ShortestPath.h"

#ifndef A_ESTRELLA_H
#define A_ESTRELLA_H

class AEstrella : public ShortestPath {
public:

    /**
     * Constructor.
     */
    AEstrella();

    /**
     * Destructor.
     */
    virtual ~AEstrella();

    /**
     * Metodo para resolver camino minimo usando A*.
     */
    virtual std::vector<std::vector<double>> resolver(std::vector<Ruta>& rutas, std::vector<int> costos,
                                                      int n);

private:
    void AEstrellaAux(std::vector<double>& caminoMin, std::vector<Ruta>& rutas, std::vector<int>& costos,
                      double& subestimacion, int& vertex, int& n);

};

#endif
