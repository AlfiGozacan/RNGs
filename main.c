/*
 * main.c
 *
 *  Created on: 29 Jun 2020
 *      Author: georgios
 */




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <rng.h>
#include <time.h>


#define MAX(x,y) (((x)>(y))?(x):(y))
#define MIN(x,y) (((x)<(y))?(x):(y))


int main(void){

	/*DECLARE VARIABLES -------------------------------------------------- */
	printf("\n DECLARE VARIABLES \n") ;

	double rnd ;
	double un ;

	int N  ;

	N = 1000 ;

	int i ;
	int j ;

	double lambda = 2.0 ;

	double mu = 1.0 ;
	double sigma = 2.0 ;

	double alpha = 4.9 ;
	double beta = 5.0 ;

	double k = 3.9 ;

	int a = 1 ;
	int b = 2 ;

	int v = 3 ;

	int n = 10 ;
	double p = 0.6 ;

	double Sigma[9] = {25.0, 15.0, -5.0, 
                        15.0, 18.0, 0.0, 
                        -5.0, 0.0, 11.0} ;
	double Mu[3] = {1.0, 3.0, 4.0} ;
	int dim = 3 ;

	double *A = (double *) malloc((size_t) ( (dim*dim) * sizeof(double) ) );

	double *z = (double *) malloc((size_t) ( (dim*dim) * sizeof(double) ) );

	cholesky(Sigma, A, dim) ;

	double *G = (double *) malloc((size_t) ( (4*4) * sizeof(double) ) );

	double *GT = (double *) malloc((size_t) ( (4*4) * sizeof(double) ) );

	double *vec ;

	double *vec2 ;

	double *vec3 ;

	double *vec4 ;

	double *vec5 ;

	double *vec6 ;

	double *vec7 ;

	int *vec8 ;

	double *vec9 ;

	double *vec10 ;

	double *vec11 ;

	FILE *ins_sample = NULL ;

	FILE *ins_sample2 = NULL ;

	FILE *ins_sample3 = NULL ;

	FILE *ins_sample4 = NULL ;

	FILE *ins_sample5 = NULL ;

	FILE *ins_sample6 = NULL ;

	FILE *ins_sample7 = NULL ;

	FILE *ins_sample8 = NULL ;

	FILE *ins_sample9 = NULL ;

	FILE *ins_sample10 = NULL ;

	FILE *ins_sample11 = NULL ;

	/*OPEN A WRITABLE FILE -------------------------------------------------- */
	printf("\n OPEN A WRITABLE FILE \n") ;

	ins_sample = fopen( "./outputfolder/expnumbers.txt" , "w" ) ;

	ins_sample2 = fopen( "./outputfolder/normnumbers.txt" , "w" ) ;

	ins_sample3 = fopen( "./outputfolder/gamnumbers.txt" , "w" ) ;

	ins_sample4 = fopen( "./outputfolder/invgamnumbers.txt" , "w" ) ;

	ins_sample5 = fopen( "./outputfolder/chisqnumbers.txt" , "w" ) ;

	ins_sample6 = fopen( "./outputfolder/betanumbers.txt" , "w" ) ;

	ins_sample7 = fopen( "./outputfolder/tnumbers.txt" , "w" ) ;

	ins_sample8 = fopen( "./outputfolder/binnumbers.txt" , "w" ) ;

	ins_sample9 = fopen( "./outputfolder/mvnnumbers.txt" , "w" ) ;

	ins_sample10 = fopen( "./outputfolder/mvtnumbers.txt" , "w" ) ;

	ins_sample11 = fopen( "./outputfolder/wishnumbers.txt" , "w" ) ;

	/*INITIALIZE THE RNG -------------------------------------------------- */
	printf("\n INITIALIZE THE RNG \n") ;

	setseedrng( (unsigned long) time(NULL) ) ;
	for ( i=1 ; i<=10 ; i++ ) {
		un = uniformrng() ;
	}

	/*ALLOCATE VECTOR SPACE -------------------------------------------------- */
	printf("\n ALLOCATE SPACE \n") ;

	vec = (double *) malloc((size_t) ( (N) * sizeof(double) ) );

	vec2 = (double *) malloc((size_t) ( (N) * sizeof(double) ) );

	vec3 = (double *) malloc((size_t) ( (N) * sizeof(double) ) );

	vec4 = (double *) malloc((size_t) ( (N) * sizeof(double) ) );

	vec5 = (double *) malloc((size_t) ( (N) * sizeof(double) ) );

	vec6 = (double *) malloc((size_t) ( (N) * sizeof(double) ) );

	vec7 = (double *) malloc((size_t) ( (N) * sizeof(double) ) );

	vec8 = (int *) malloc((size_t) ( (N) * sizeof(double) ) );

	vec9 = (double *) malloc((size_t) ( (N) * sizeof(double) ) );
	
	vec10 = (double *) malloc((size_t) ( (N) * sizeof(double) ) );

	vec11 = (double *) malloc((size_t) ( (N) * sizeof(double) ) );

	/*SAMPLE THE RNG -------------------------------------------------- */
	printf("\n SAMPLE THE RNG \n") ;

	for ( i=0 ; i<=(N-1) ; i++ ) {
		vec[i] = exponentialrng( lambda ) ;
		vec2[i] = normalrng( mu, sigma ) ;
		vec3[i] = gammarng( alpha, beta ) ;
		vec4[i] = invgammarng( alpha, beta ) ;
		vec5[i] = chisquarerng( k ) ;
		vec6[i] = betarng( a, b ) ;
		vec7[i] = trng( v ) ;
		vec8[i] = binomialrng( n, p ) ;
		vec9[i] = mvnormalrng(dim, Mu, A, z) ;
	}

	for (i=0; i<(dim - N%dim); i++) {

		mvnormalrng(dim, Mu, A, z) ;

	}

	for (i=0; i<=(N-1); i++) {

		vec10[i] = mvtrng(dim, v, Mu, A, z) ;

	}

	for (i=0; i<(dim - N%dim); i++) {

		mvnormalrng(dim, Mu, A, z) ;

	}

	for (i=0; i<=(N-1); i++) {

		vec11[i] = wishartrng(dim, G, GT, A, z, 4) ;

	}

	/*SAVE THE RNG -------------------------------------------------- */
	printf("\n SAVE THE RNG \n") ;

	for ( i=0 ; i<=(N-1) ; i++ ) {
		fprintf(ins_sample, "%f\n", vec[i]) ;
		fprintf(ins_sample2, "%f\n", vec2[i]) ;
		fprintf(ins_sample3, "%f\n", vec3[i]) ;
		fprintf(ins_sample4, "%f\n", vec4[i]) ;
		fprintf(ins_sample5, "%f\n", vec5[i]) ;
		fprintf(ins_sample6, "%f\n", vec6[i]) ;
		fprintf(ins_sample7, "%f\n", vec7[i]) ;
		fprintf(ins_sample8, "%f\n", vec8[i]) ;
		fprintf(ins_sample9, "%f\n", vec9[i]) ;
		fprintf(ins_sample10, "%f\n", vec10[i]) ;
		fprintf(ins_sample11, "%f\n", vec11[i]) ;
	}

	/*FREE THE SPACE ALLOCATED -------------------------------------------------- */
	printf("\n FREE THE SPACE ALLOCATED \n") ;

	free( vec ) ;

	free( vec2 ) ;

	free( vec3 ) ;

	free( vec4 ) ;

	free( vec5 ) ;

	free( vec6 ) ;

	free( vec7 ) ;

	free( vec8 ) ;

	free( vec9 ) ;

	free( vec10 ) ;

	free( vec11 ) ;

	free( A ) ;

	free( z ) ;

	free( G ) ;

	free( GT ) ;

	/*DONE -------------------------------------------------- */
	printf("\n DONE \n") ;

	return(0) ;
}


