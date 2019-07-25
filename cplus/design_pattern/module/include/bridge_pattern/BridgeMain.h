#ifndef DESIGNPATTERN_BRIDGEMAIN_H
#define DESIGNPATTERN_BRIDGEMAIN_H

#include "refined_abstraction.h"
#include "concrete_implementor.h"

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=nullptr;} }
#endif

void BridgeMain();

#endif //DESIGNPATTERN_BRIDGEMAIN_H
