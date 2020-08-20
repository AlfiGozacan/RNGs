#include <stdlib.h>
#include <math.h>

#include "RNG.h"

int i ;
int sum1 ;
int x ;
double u ;

int binomialrng(int n, double p) {

    for (i=0; i<n; i++) {

        x = 0 ;

        u = uniformrng() ;

        if (u < p) {
            x = 1 ;
        }

        sum1 += x ;

    }

    return sum1 ;

}