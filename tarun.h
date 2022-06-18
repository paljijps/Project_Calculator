#ifndef tarun

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MXCOO 9
#define MXROO 9

void read_argmat(float a[][MXCOO], int n, FILE *fp)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < (n + 1); j++)
        {
            // printf("Enter [%d][%d] element of the matrix: ", i + 1, j + 1);
            fscanf(fp, "%f", &a[i][j]);
        }
    }
}

void show_argmat(float a[][MXCOO], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < (n + 1); j++)
        {
            printf("%f \t", a[i][j]);
        }
        printf("\n");
    }
}

void upper(float a[][MXCOO], int n)
{
    int i, j, k;
    float r;
    for (j = 0; j < n; j++)
    {
        for (i = 0; i < n; i++)
        {
            if (i > j)
            {
                r = a[i][j] / a[j][j];

                for (k = 0; k < (n + 1); k++)
                    a[i][k] -= a[j][k] * r; // a[i][k] = a[i][k] - a[j][k]*r;
            }
        }
    }
}

void backward(float a[][MXCOO], float x[], int n)
{
    int i, j;
    float s;
    x[n - 1] = a[n - 1][n] / a[n - 1][n - 1];
    for (i = n - 2; i >= 0; i--)
    {
        s = 0;
        for (j = i + 1; j < n; j++)
        {
            s += (a[i][j] * x[j]);
            x[i] = (a[i][n] - s) / a[i][i];
        }
    }
    printf("\nSolution using Backward Substitution is :\n");
    for (i = 0; i < n; i++)
    {
        printf("\nx[%d] = %f", i + 1, x[i]);
    }
}

void elimination()
{
    FILE *fp;
    fp = fopen("gelimination.txt", "r");
    if (fp == NULL)
    {
        puts("Can't open file");
        exit(0);
    }

    int i, j, n;
    float a[MXROO][MXCOO];
    float x[MXCOO];

    fscanf(fp, "%d", &n); // Number of unknowns
    // printf("Enter Argumented Matrix A row-wise:\n");
    read_argmat(a, n, fp);

    printf("A:b = \n");
    show_argmat(a, n);
    upper(a, n);
    printf("\nReduced Upper triangular form is: \n");
    show_argmat(a, n);
    backward(a, x, n);
    fclose(fp);
}

void diag_mat(float a[][MXCOO], int n)
{
    int i, j, k;
    float r;
    for (j = 0; j < n; j++)
    {
        for (i = 0; i < n; i++)
        {
            if (i != j)
            {
                r = a[i][j] / a[j][j];

                for (k = 0; k < (n + 1); k++)
                    a[i][k] -= a[j][k] * r; // a[i][k] = a[i][k] - a[j][k]*r;
            }
        }
    }
}

void diag_soln(float a[][MXCOO], float x[], int n)
{
    int i, j;
    float s;
    for (i = 0; i < n; i++)
    {
        x[i] = a[i][n] / a[i][i];
    }

    printf("Required Solution is:\n");
    for (i = 0; i < n; i++)
    {
        printf("x[%d] = %f\n", i + 1, x[i]);
    }
}

void jordan()
{
    FILE *fp;
    fp = fopen("gelimination.txt", "r");
    if (fp == NULL)
    {
        puts("Can't open file");
        exit(0);
    }

    int i, j, n;
    float a[MXROO][MXCOO];
    float x[MXCOO];

    fscanf(fp, "%d", &n); // Number of unknowns
    // printf("Enter Argumented Matrix A row-wise:\n");
    read_argmat(a, n, fp);

    printf("A:b = \n");
    show_argmat(a, n);
    diag_mat(a, n);
    printf("\nReduced Diagonal form is: \n");
    show_argmat(a, n);
    diag_soln(a, x, n);
    fclose(fp);
}

#define tarun
#endif