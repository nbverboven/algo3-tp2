#include "Ruta.h"

/**
 * Constructor.
 */
Ruta::Ruta(int ciudadA, int ciudadB, int litros):a_(ciudadA),b_(ciudadB),l_(litros) {

}

/**
 * Destructor.
 */
Ruta::~Ruta() {

}

/**
 * Devuelve la primera ciudad de la ruta.
 */
int Ruta::obtenerCiudadA() {
    return this->a_;
}

/**
 * Devuelve la segunda ciudad de la ruta.
 */
int Ruta::obtenerCiudadB() {
    return this->b_;

}

/**
 * Devuelve la cantidad necesaria de litros para recorrer la ruta.
 */
int Ruta::obtenerLitros() {
    return this->l_;
}
