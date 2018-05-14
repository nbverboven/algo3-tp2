#ifndef PARSER_H_
#define PARSER_H_

#include <vector>
#include "Edge.h"

/**
 * Clase extra para parsear los parametros del problema.
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
    void parseArguments();
    /**
     * Devuelve la cantidad de ciudades.
     */
    int getN();
    /**
     * Devuelve la cantidad de rutas potenciales.
     */
    int getM();
    /**
     * Devuelve las rutas potenciales.
     */
    std::vector<Edge>& getEdges();

private:
    int n_, m_;
    std::vector<Edge> edges_;
};

#endif
