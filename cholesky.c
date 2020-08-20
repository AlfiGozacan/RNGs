#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double sum(double *array, int n) ;

int cholesky(double *matrix, double *L, int n) {

    int i ;
    int j ;
    int k ;

    double sum1 ;

    double *left_values ;

    for (i=0; i<n; i++) {
        
        for (j=0; j<n; j++) {

            if (i < j) {

                L[i*n + j] = 0.0 ;

            } else if (i > j) {

                for (k=0; k<i; k++) {

                    left_values[k] = L[i*n + k]*L[j*n + k] ;

                }

                sum1 = sum(left_values, i) ;

                L[i*n + j] = (1/L[j*n + j]) * ( matrix[i*n + j] - sum1 ) ;

            } else {

                for (k=0; k<i; k++) {

                    left_values[k] = L[i*n + k]*L[i*n + k] ;

                }

                sum1 = sum(left_values, i) ;

                L[i*n + i] = sqrt ( matrix[i*n + i] - sum1 ) ;

            }
        }

    }

    return 0 ;

}