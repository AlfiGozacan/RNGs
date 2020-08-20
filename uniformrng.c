/*
 * uniformrng.c
 *
 *  Created on: 29 Jun 2020
 *      Author: georgios
 */




/* declare the headers */

#include <stdlib.h>
#include <math.h>

#include "RNG.h"

/* initializes a seed */

void setseedrng(unsigned long s)
{
	srand( s ) ;
}

/* DEFAULT : generates a random number on (0,1)-real-interval */

double uniformrng(void)
{
	double rnd ;

	do {
		rnd = (double) ( rand() / ( RAND_MAX + 1.0 ) ) ;
	} while ( rnd == 0.0 || rnd == 1.0 ) ;

	return rnd ;
}

/* DEFAULT : generates a random number on [a,b]-real-interval */

int integerrng(int a, int b)
{
	return a +floor(uniformrng()*(b-a+1)) ;
}




