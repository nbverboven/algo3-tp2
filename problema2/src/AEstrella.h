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
    double AEstrellaAux(std::vector<Ruta>& rutas, std::vector<int>& costos,
                      double subestimacion, int inicio, int fin, int n);

};

#endif
