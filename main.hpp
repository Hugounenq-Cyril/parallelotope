#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "gmp.h"


#define RADIO 10
#define N 8
#define D 120

int** rotation_matrix(int*);

// Computes (1/den)* A * v  
double* matrix_vector_den(int**, int*, int);
void print_matrix(int** p);



bool is_in(int* p);

double* half(double* , double* );

//bool diff(int*, int*);
bool diff(double*, double*);
		
double* binary_move(double* , double*);

double * fall(double *,double *);
double * fallnew(double *,double *);


double* normalized(int* p);
double* normalized(double* p);

double * next_dir(double *);
double * next_point(double *);
double * next_point_static(double *);

void print_point(int* p);
void print_point(double* p);

double** gram_schmidt(double* dir);
double** gram_schmidt_orth(double* dir);

double inner_prod(double* u, double* v);

bool is_orthonormal(double **m);

int test_neighbour(double * point, double * dir);

double norm(double* u);

