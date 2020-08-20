#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include "RNG.h"

int matrix_mult(double *matrix1, double *matrix2, double *L, int n) {

    int i ;
    int j ;
    int k ;

    double sum1 ;

    double *summands ;

    for (i=0; i<n; i++) {

        for (j=0; j<n; j++) {

            for (k=0; k<n; k++) {

                summands[k] = matrix1[i*n + k] * matrix2[k*n + j] ;

            }

            sum1 = sum(summands, n) ;

            L[i*n + j] = sum1 ;

        }

    }

    return 0 ;

}


//TEST//

// void main() {

//     int i ;
//     int j ;

//     double m1[4] = {2.0, 0.0, 2.0, 3.0} ;
//     double m2[4] = {2.0, 2.0, 0.0, 3.0} ;

//     double *output = (double *) malloc(4 * sizeof(double)) ;

//     matrix_mult(m1, m2, output, 2) ;

//     for (i=0; i<2; i++) {

//         for (j=0; j<2; j++) {

//             printf("%lf ", output[i*2 + j]) ;

//         }

//         printf("\n") ;

//     }

// }