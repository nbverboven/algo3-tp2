#include "Agm.h"

/**
 * Constructor.
 */
Agm::Agm(std::vector<Edge>& edges, double weight):edges_(edges), weight_(weight) {
}

/**
 * Destructor.
 */
Agm::~Agm() {

}

/**
 * Devuelve las aristas del AGM.
 */
std::vector<Edge>& Agm::getEdges() {
    return edges_;
}

/**
 * Devuelve el peso del AGM.
 */
double Agm::getWeight() {
    return weight_;
}
