#include "AgmMethodFactory.h"
#include "Prim.h"
#include "Kruskal.h"
#include "KruskalPathCompression.h"

AgmMethod* AgmMethodFactory::createAgmMethod(const std::string& method, int n, int m, std::vector<Edge>& edges) {
    if (method == "prim") {
        return new Prim(n, m, edges);
    } else if (method == "kruskal") {
        return new Kruskal(n, m, edges);
    } else if (method == "kruskalCompression") {
        return new KruskalPathCompression(n, m, edges);
    }
    return NULL;
}
