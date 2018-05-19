#include "Parser.h"

/**
 * Constructor.
 */
Parser::Parser() {
}

/**
 * Destructor.
 */
Parser::~Parser() {
}

/**
 * Lee standard input y guarda la cantidad de ciudades,
 * la cantidad de rutas y las rutas con sus costos.
 */
void Parser::parsearArgumentos() {
    // parsea n y m
    std::cin >> this->n_;
    std::cin >> this->m_;
    // parsea los costos de las n ciudades
    for (int i = 0; i < this->n_; ++i) {
        int c_i;
        std::cin >> c_i;
        this->costs_.push_back(c_i);
    }

    for (int i = 0; i < this->m_; ++i) {
        int a_i, b_i, c_i;
        std::cin >> a_i;
        std::cin >> b_i;
        std::cin >> c_i;
        this->edges_.push_back(Edge(a_i, b_i, c_i));
    }
}

/**
 * Devuelve la cantidad de ciudades.
 */
int Parser::obtenerCiudades() {
    return this->n_;
}

/**
 * Devuelve las rutas.
 */
std::vector<Edge>& Parser::obtenerRutas() {
    return this->edges_;
}

/**
 * Devuelve un vector con el costo de la nafta
 * en cada ciudad.
 */
std::vector<int>& Parser::obtenerCostos() {
    return this->costs_;
}
