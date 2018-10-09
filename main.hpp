#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "gmp.h"


#define RADIO 10
#define N 8
#define D 120

int** rotation_matrix(int*);

// Computes (1/det)* A * v  
double* matrix_vector_den(int**, int*, int);

int * move (int *);


bool is_in(int* p);

void print_matrix(int** p);
void print_point(int* p);
void print_point(double* p);


