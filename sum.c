#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double sum(double *array, int n) {

    int i ;
    double total ;

    total = 0.0 ;

    for (i=0; i<n; i++) {

        total += array[i] ;

    }

    return total ;

}