#include <stdlib.h>
#include <math.h>

#include "RNG.h"

double invgammarng(int alpha, double beta) {
    
    double x = gammarng(alpha, beta) ;

    return 1/x ;
}