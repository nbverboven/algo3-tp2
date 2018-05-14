#include "Edge.h"

/**
 * Constructor.
 */
Edge::Edge(int a, int b, int cost):a_(a), b_(b), cost_(cost) {
}

/**
 * Destructor.
 */
Edge::~Edge() {
}

/**
 * Devuelve un extremo de la ruta.
 */
int Edge::getA() const {
    return this->a_;
}

/**
 * Devuelve el otro extremo de la ruta.
 */
int Edge::getB() const {
    return this->b_;
}

/**
 * Devuelve el costo de la ruta.
 */
int Edge::getCost() const {
    return this->cost_;
}

/**
 * Fija el costo de la ruta.
 */
void Edge::setCost(int cost) {
    this->cost_ = cost;
}

/**
 * Operador de comparacion para usar una priority queue
 * con las aristas, segun su peso.
 */
bool operator<(const Edge& lhs, const Edge& rhs) {
    return lhs.getCost() > rhs.getCost();
}

/**
 * Imprime al ostream la arista; util para debuggear.
 */
std::ostream& operator<<(std::ostream& os, const Edge& e) {
    os << e.getA() << " " << e.getB() << " " << e.getCost();
    return os;
}
