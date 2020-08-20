#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include "RNG.h"

double mvtrng(int n, int v, double *m, double *A, double *z) {

    static int mvt_flag ;

    static double U ;

    if (mvt_flag == 0) {

        double Y = mvnormalrng(n, m, A, z) ;

        U = chisquarerng(v) ;

        return m[0] + Y * sqrt( v / U ) ;
        
    } else if (mvt_flag == n-1) {
        
        double Y = mvnormalrng(n, m, A, z) ;

        mvt_flag = 0 ;

        return m[n-1] + Y * sqrt( v / U ) ;

    } else {

        mvt_flag++ ;

        double Y = mvnormalrng(n, m, A, z) ;

        return m[mvt_flag-1] + Y * sqrt( v / U ) ;

    }

}