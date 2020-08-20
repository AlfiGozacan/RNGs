#include <stdlib.h>
#include <math.h>

#include "RNG.h"

double chisquarerng(double k) {
    
    return gammarng(k*0.5, 0.5) ;

}