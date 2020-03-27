#include "sole.h"
#include "matrix/column.h"
#include "matrix/matrix.h"

int sole_solution(const double *mat_A, const double *col_B, double *col_X, int size)
{
    col_set_zero(col_X, size);

    double B_module = 0;
    col_module(col_B, size, &B_module);

    double precision = 0.001;
    double diff = 0;

    int count = 0;

    double *col_Y = (double *) calloc(size, sizeof(double));
    double *col_AY = (double *) calloc(size, sizeof(double));
    double *col_AX = (double *) calloc(size, sizeof(double));
    double *col_Yt = (double *) calloc(size, sizeof(double));

    double t;
    double AY_dot_AY = 0;
    double Y_dot_AY = 0;
    double Y_module = 0;


#pragma omp parallel default(shared)
    {
        do
        {
            mat_mult_by_column(mat_A, col_X, col_AX, size); // AX = A*X

            col_subtraction(col_AX, col_B, col_Y, size); // Y = AX - B

            mat_mult_by_column(mat_A, col_Y, col_AY, size); // AY = A*Y

            col_dot_product(col_AY, col_AY, size, &AY_dot_AY);

            if (AY_dot_AY == 0)
            {
                t = 0;
            } else
            {
                col_dot_product(col_Y, col_AY, size, &Y_dot_AY);

                t = Y_dot_AY / AY_dot_AY;
            }

#pragma omp single
            count++;

            col_module(col_Y, size, &Y_module);

            diff = Y_module / B_module;

            col_mult_by_numb(col_Y, t, col_Yt, size);

            col_subtraction(col_X, col_Yt, col_X, size);

            col_print(" ", col_X, size);


        } while (diff >= precision);

#pragma omp single
        printf("Iteration count: %d\n", count);
    }

    free(col_Y);
    free(col_AY);
    free(col_AX);
    free(col_Yt);


    return 0;
}