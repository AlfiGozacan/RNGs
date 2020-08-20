#include <stdlib.h>
#include <math.h>

#include "RNG.h"

double trng(int v) {

    double z = normalrng(0.0, 1.0);
    double U = chisquarerng(v);

    return z / (sqrt(U) / v);
}