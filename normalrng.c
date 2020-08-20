#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "RNG.h"

double normalrng(double mu, double sigma)
{
    static int flag = 0 ;

    double u1 ;
    double u2 ;

    double z1 ;
    static double z2 ;

    double pi = 3.14159265358979323 ;

    if  (flag == 0) {

        u1 = uniformrng() ;
        u2 = uniformrng() ;

        z1 = ( sqrt( -2*log(u1) ) )* cos(2*(pi)*u2) ;
        z2 = ( sqrt( -2*log(u1) ) )* sin(2*(pi)*u2) ;

        flag = 1 ;

        return z1*sigma + mu ;

    }

    else {

        flag = 0 ;

        return z2*sigma + mu ;
        
    }

}