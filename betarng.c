#include <stdlib.h>
#include <math.h>

#include "RNG.h"

double betarng(int a, int b) {

    double x = gammarng(a, 1.0);
    double y = gammarng(b, 1.0);

    return x/(x+y) ;
}