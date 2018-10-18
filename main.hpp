#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include "gmpxx.h"

#define N 334
#define LENGTH 8

mpz_class ** rotation_matrix(mpz_class *);
int ** vertex_matrix(int *);

mpz_class * matrix_vector(mpz_class **, int *);
mpz_class * poly_mult(mpz_class *, int *);



int * push (int *, int *, bool);
void fall (int *);
int * fall_orth (int *);

int norm_percent(int *);
int norm(int *);

int * add(int *, int *);
int * neg(int *);
void set(int *, int *);

bool is_in(int *);
bool is_already_visited(int *);

bool is_far(int *);
bool equals(int *, int *);

bool victory(int *);

void print_matrix(int **);
void print_matrix(mpz_class **);
void print_point(int *);
void print_point(mpz_class *);
void print_visited();