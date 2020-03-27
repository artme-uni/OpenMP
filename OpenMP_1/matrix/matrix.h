#ifndef OPENMP_1_MATRIX_H
#define OPENMP_1_MATRIX_H

#include <stdio.h>
#include <stdlib.h>

int mat_print(char *output, double* matrix, int size);

int mat_mult_by_column(const double *matrix, const double *column, double*result, int size);

#endif //OPENMP_1_MATRIX_H
