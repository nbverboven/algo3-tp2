#ifndef PARSER_H_
#define PARSER_H_

#include <vector>
#include "Edge.h"

/**
 * Clase para parsear los parametros del problema 2.
 */
class Parser {
public:
    /**
    * Constructor.
    */
    Parser();
    /**
     * Destructor.
    */
    ~Parser();
    /**
     * Lee standard input y guarda la cantidad de ciudades,
     * la cantidad de rutas y las rutas con sus costos.
     */
    void parsearArgumentos();
    /**
     * Devuelve las rutas.
     */
    std::vector<Edge>& obtenerRutas();
    /**
     * Devuelve la cantidad de ciudades.
     */
    int obtenerCiudades();
    /**
     * Devuelve un vector con el costo de la nafta
     * en cada ciudad.
     */
    std::vector<int>& obtenerCostos();

private:
    int n_, m_;
    std::vector<int> costs_;
    std::vector<Edge> edges_;
};

#endif
