#include <vector>
#include "Edge.h"

#ifndef AGM_H
#define AGM_H

class Agm {
public:

    /**
     * Constructor.
     */
    Agm(std::vector<Edge>& edges, double weight);

    /**
     * Destructor.
     */
    ~Agm();

    /**
     * Devuelve las aristas del AGM.
     */
    std::vector<Edge>& getEdges();

    /**
     * Devuelve el peso del AGM.
     */
    double getWeight();

private:
    std::vector<Edge> edges_;
    double weight_;
};

#endif
