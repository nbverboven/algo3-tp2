#include "Parser.h"
#include <iostream>

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
void Parser::parseArguments() {
    std::cin >> this->n_;
    std::cin >> this->m_;
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
int Parser::getN() {
    return this->n_;
}

/**
 * Devuelve la cantidad de rutas potenciales.
 */
int Parser::getM() {
    return this->m_;
}

/**
 * Devuelve las rutas potenciales.
 */
std::vector<Edge>& Parser::getEdges() {
    return this->edges_;
}
