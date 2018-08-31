#include <iostream>
#include <stdlib.h>
#include <math.h>

#define RADIO 10
#define N 32
#define D 120


bool is_in(double* p);

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
void print_matrix(double** p);

double** gram_schmidt(double* dir);
double** gram_schmidt_orth(double* dir);

double inner_prod(double* u, double* v);

bool is_orthonormal(double **m);

int test_neighbour(double * point, double * dir);

double norm(double* u);

