#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include "RNG.h"

double mvnormalrng(int n, double *m, double *A, double *z) {

    int i ;
    int j ;

    static int mvn_flag ;

    static double *x ;

    if (mvn_flag == 0) {

         for (i=0; i<n; i++) {

            z[i*n] = normalrng(0.0, 1.0) ;

            for (j=1; j<n; j++) {

                z[i*n + j] = 0.0 ;

            }

        }

        double *Az = (double *) malloc((size_t) ( (n*n) * sizeof(double) ) ) ;

        matrix_mult(A, z, Az, n) ;

        x = (double *) malloc((size_t) ( (n) * sizeof(double) ) ) ;

        for (i=0; i<n; i++) {

            x[i] = Az[i*n] + m[i] ;

        }

        free( Az ) ;

        mvn_flag = 1 ;

        return x[0] ;

    } else if (mvn_flag == n-1) {

        mvn_flag = 0 ;

        double last_output = x[n-1] ;

        free( x ) ;

        return last_output ;

    } else {

        mvn_flag++ ;

        return x[mvn_flag-1] ;

    }

}