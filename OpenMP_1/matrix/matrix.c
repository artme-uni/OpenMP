#include "matrix.h"

int mat_print(char *output, double *matrix, int size)
{
    FILE *fp;
    if ((fp = fopen(output, "w")) == NULL)
    {
        printf("Не удалось открыть файл");
        getchar();
        return -1;
    }

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            fprintf(fp, "%lf ", matrix[i + size * j]);
        }

        fprintf(fp, "\n");
    }

    fprintf(fp, "\n");

    fclose(fp);

    return 0;
}

int mat_mult_by_column(const double *matrix, const double *column, double*result, int size)
{
    for (int i = 0; i < size; ++i)
    {
        result[i] = 0;

        for (int j = 0; j < size; ++j)
        {
           result[i] += matrix[i + size * j] * column[j];
        }
    }

    return 0;
}