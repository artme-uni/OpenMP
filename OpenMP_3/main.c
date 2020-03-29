#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#include "matrix/scaning.h"
#include "sole.h"
#include "matrix/column.h"

#define SIZE 1000
#define COUNT 999

int main()
{
    omp_set_num_threads(COUNT);

#pragma omp parallel
    {
        printf("%d\n", omp_get_num_threads());
    };

    printf("Matrix size: %d\n", SIZE);

    double* mat_A = (double*) calloc(SIZE * SIZE, sizeof(double));
    double* col_B = (double*) calloc(SIZE, sizeof(double));
    double* col_X = (double*) calloc(SIZE, sizeof(double));

    scaning("input.txt", mat_A, col_B, SIZE);

    double start = omp_get_wtime();
    sole_solution(mat_A, col_B, col_X, SIZE);
    double end = omp_get_wtime();

    double seconds = end - start;
    printf("Time taken: %f seconds\n", seconds);

    col_print("output.txt", col_X, SIZE);

    free(mat_A);
    free(col_B);
    free(col_X);

    return 0;
}
