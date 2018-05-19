#include <iostream>

#ifndef EDGE_H_
#define EDGE_H_

/**
 * Representa una ruta. Tiene las dos ciudades
 * (a, b) y el costo de la ruta.
 */
class Edge {

public:
    /**
     * Constructor.
     */
    Edge(int src, int dst, int cost);
    /**
     * Destructor.
     */
    ~Edge();
    /**
     * Devuelve un extremo de la ruta.
     */
    int getA() const;
    /**
     * Devuelve el otro extremo de la ruta.
     */
    int getB() const;
    /**
     * Devuelve el costo de la ruta.
     */
    int getCost() const;
    /**
     * Fija el costo de la ruta.
     */
    void setCost(int cost);

private:
    int a_;
    int b_;
    int cost_;
};

/**
 * Operador de comparacion para usar una priority queue
 * con las aristas, segun su peso.
 */
bool operator<(const Edge& lhs, const Edge& rhs);

/**
 * Imprime al ostream la arista; util para debuggear.
 */
std::ostream& operator<<(std::ostream& os, const Edge& e);

#endif
