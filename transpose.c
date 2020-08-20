#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int transpose(double *matrix, double *L, int n) {

    int i ;
    int j ;

    for (i=0; i<n; i++) {

        for (j=0; j<n; j++) {

            L[i*n + j] = matrix[j*n + i] ;

        }

    }

}