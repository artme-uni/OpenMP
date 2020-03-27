#include "scaning.h"

int scaning(char* file_name, double* matrix, double *column, int size)
{
    FILE *fp;
    if ((fp = fopen(file_name, "r")) == NULL)
    {
        fprintf(stderr, "Не удалось открыть файл");
        exit(-1);
    }

    char buffer[10];

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size - 1; ++j)
        {
            fscanf(fp, "%s ", buffer);
            matrix[i + size * j] = atof(buffer);
        }

        fscanf(fp, "%s\n", buffer);
        matrix[i + size * (size - 1)] = atof(buffer);
    }

    fputs(buffer, fp);

    for (int k = 0; k < size; ++k)
    {
        fscanf(fp, "%s\n", buffer);
        column[k] = atof(buffer);
    }

    fclose(fp);

    return 0;
}