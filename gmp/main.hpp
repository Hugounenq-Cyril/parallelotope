#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include "gmp.h"
#include <limits>

#define N 16

long long ** rotation_matrix(long long *);
int ** rotation_matrix(int *);

long long * matrix_vector(long long**, int*);

// Computes (1/det)* A * v  
double* matrix_vector_den(int**, int*, int);


void move (int *);
void fall (int *);
int norm(int *);

int * add(int *, int *);
int * neg(int *);


bool is_in(int *);
bool is_already_visited(int *);

bool is_far(int *);
bool equals(int *, int *);

bool victory(int *);

void print_matrix(int **);
void print_matrix(long long **);
void print_point(int *);
void print_point(long long *);
void print_visited();

