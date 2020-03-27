#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "matrix/scaning.h"
#include "sole.h"
#include "matrix/column.h"

#define SIZE 1000

int main()
{
    printf("Matrix size: %d\n", SIZE);

    double* mat_A = (double*) calloc(SIZE * SIZE, sizeof(double));
    double* col_B = (double*) calloc(SIZE, sizeof(double));
    double* col_X = (double*) calloc(SIZE, sizeof(double));

    scaning("input.txt", mat_A, col_B, SIZE);

    clock_t start = clock();
    sole_solution(mat_A, col_B, col_X, SIZE);
    clock_t end = clock();

    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", seconds);

    col_print("output.txt", col_X, SIZE);

    free(mat_A);
    free(col_B);
    free(col_X);

    return 0;
}
