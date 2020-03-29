#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#include "matrix/scaning.h"
#include "sole.h"
#include "matrix/column.h"

#define SIZE 1000

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        printf("Expected: ./prog count\n");
        return -1;
    }

    omp_set_num_threads(atoi(argv[1]));

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
