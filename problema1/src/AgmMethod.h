#include <vector>
#include "Agm.h"
#include "Edge.h"

#ifndef AGM_METHOD_H
#define AGM_METHOD_H

class AgmMethod {
public:
    virtual ~AgmMethod() {};
    virtual Agm getAGM()=0;
};

#endif
