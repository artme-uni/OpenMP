#ifndef OPENMP_1_COLUMN_H
#define OPENMP_1_COLUMN_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int col_print(char *output, double *column, int size);

int col_set_zero(double *column, int size);

int col_dot_product(const double *left, const double *right, int size, double* sum);

int col_mult_by_numb(const double *column, double rate, double *result, int size);

int col_module(const double *column, int size, double* sum);

double col_subtraction(const double *left, const double *right, double *result, int size);

#endif //OPENMP_1_COLUMN_H
