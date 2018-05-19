#ifndef RUTA_H
#define RUTA_H

/**
 * Una ruta del mapa. Guarda las dos ciudades que esta
 * conectando y el costo en litros de recorrerla
 */
class Ruta {
public:

    /**
     * Constructor.
     */
    Ruta(int ciudadA, int ciudadB, int litros);

    /**
     * Destructor.
     */
    ~Ruta();

    /**
     * Devuelve la primera ciudad de la ruta.
     */
    int obtenerCiudadA();

    /**
     * Devuelve la segunda ciudad de la ruta.
     */
    int obtenerCiudadB();

    /**
     * Devuelve la cantidad necesaria de litros para recorrer la ruta.
     */
    int obtenerLitros();

private:
    int a_;
    int b_;
    int l_;
};

#endif
