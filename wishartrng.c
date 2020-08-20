#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include "RNG.h"

double wishartrng(int p, double *G, double *GT, double *L, double *z, int n) {

    static int wish_flag ;
    static double *S ;

    int i ;
    int j ;

    double *zero ;

    if (wish_flag == 0) {

        for (i=0; i<n; i++) {

            for (j=0; j<p; j++) {

                G[i*p + j] = mvnormalrng(p, zero, L, z) ;

            }

        }

        transpose(G, GT, p) ;

        double *GTG = (double *) malloc((size_t) ( (n*n) * sizeof(double) ) ) ;

        matrix_mult(GT, G, GTG, n) ;

        S = GTG ;

        wish_flag++ ;

        double first_output = S[0] ;

        free( GTG ) ;

        return first_output ;

    } else if (wish_flag == p*p) {

        wish_flag = 0 ;

        double last_output = S[p*p - 1] ;

        free( S ) ;

        return last_output ;

    } else {

        wish_flag++ ;

        return S[wish_flag - 1] ;

    }

}