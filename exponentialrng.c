/*
 * exponentialrng.c
 *
 *  Created on: 29 Jun 2020
 *      Author: georgios
 */


/* declare the headers */

#include <stdlib.h>
#include <math.h>

#include "RNG.h"

/* DEFAULT : generates a random number on (0,1)-real-interval */

double exponentialrng(double lambda)
{
	double rnd ;

	rnd = uniformrng() ;

	rnd = -1.0 / lambda *log(1.0-rnd) ;

	return rnd ;
}



