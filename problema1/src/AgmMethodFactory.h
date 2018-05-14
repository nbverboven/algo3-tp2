#include <string>
#include "AgmMethod.h"
#include "Edge.h"

#ifndef AGM_METHOD_FACTORY_H
#define AGM_METHOD_FACTORY_H

class AgmMethodFactory {
public:
    static AgmMethod* createAgmMethod(
        const std::string& method, int n,
        int m,
        std::vector<Edge>& edges
    );
};

#endif
