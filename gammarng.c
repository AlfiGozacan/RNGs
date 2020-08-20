#include <stdlib.h>
#include <math.h>

#include "RNG.h"

double sum1 ;
int i ;
int intpart ;
double decpart ;

double u ;
double v ;
double w ;

double xi = 0 ;
double eta = 0 ;

double e = 2.718282 ;

double gammarng(double alpha, double beta)
{
    intpart = (int)alpha ;
    decpart = alpha - intpart ;

    sum1 = 0 ;

    for (i=0; i<intpart; i++) {

        sum1 += exponentialrng(1.0) ;

    }

    while (1) {

        u = uniformrng() ;
        v = uniformrng() ;
        w = uniformrng() ;

        if ( u < (e / (e + decpart)) ) {

            xi = pow(v, 1/decpart) ;
            eta = w*pow(xi, decpart-1) ;

        } else {

            xi = 1 - log(v) ;
            eta = w*pow(e, -1*xi) ;

        }

        if (eta >= pow(xi, decpart-1)*pow(e, -xi)) {
            break ;
        }
    
    }

    sum1 += xi ;
    
    return sum1 / beta ;
}