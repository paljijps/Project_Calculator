#ifndef jaswinder

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "harmeet.h"
#include "base.h"
#define MAXITR1 30
#define MAXITR2 20
#define MAXITR3 25
#define MXDDON 9
#define MXDINT 20

void eqtop()
{
    printf("\n-------------------------------------------------------------\n");
    printf("| Sr. no.                   EQUATION                        |\n|                                                           |");
}

void eqend()
{
    printf("\n-------------------------------------------------------------\n");
    printf("\nEnter the corresponding Sr. no. to solve that equation:\t");
}
void eqns()
{
    eqtop();
    message(1, "f(x) = cos(x) - x*exp(x) = 0 ");
    message(2, "f(x) = x*log10(x) - 1.2 = 0 ");
    message(3, "f(x) = x - e^(-x) = 0 ");
    message(4, "f(x) = x^4 - x - 10 = 0 ");
    message(5, "f(x) = x - (1/5)*exp(x) = 0 ");
    message(6, "f(x) = x^3 - 4*x + 9 = 0 ");
    message(7, "f(x) = x*sin(x) - 1 = 0 ");
    message(8, "f(x) = cos(x) - 3*x + 1 = 0 ");
    message(9, "f(x) = 3*x + sin(x) - exp(x) = 0 ");
    message(10, "f(x) = x^3 - x^2 - x - 1 = 0 ");
    eqend();
}
// Equations
float f1(float x)
{
    return (cos(x) - x * exp(x));
}
float f2(float x)
{
    return (x * log10(x) - 1.2);
}
float f3(float x)
{
    return (x - exp(-x));
}
float f4(float x)
{
    return (x * x * x * x - x - 10);
}
float f5(float x)
{
    return (x - 0.2 * exp(x));
}
float f6(float x)
{
    return (x * x * x - 4 * x + 9);
}
float f7(float x)
{
    return (x * sin(x) - 1);
}
float f8(float x)
{
    return (cos(x) - 3 * x + 1);
}
float f9(float x)
{
    return (3 * x + sin(x) - exp(x));
}
float f10(float x)
{
    return (x * x * x - x * x - x - 1);
}

// First derivatives
float fd1(float x)
{
    return (-sin(x) - exp(x) - x * exp(x));
}
float fd2(float x)
{
    return (log10(x) + 0.434294481);
}
float fd3(float x)
{
    return (1 + exp(-x));
}
float fd4(float x)
{
    return (4 * x * x * x - 1);
}
float fd5(float x)
{
    return (1 - 0.2 * exp(x));
}
float fd6(float x)
{
    return (3 * x * x - 4);
}
float fd7(float x)
{
    return (sin(x) + x * cos(x));
}
float fd8(float x)
{
    return (-sin(x) - 3);
}
float fd9(float x)
{
    return (3 + cos(x) - exp(x));
}
float fd10(float x)
{
    return (3 * x * x - 2 * x - 1);
}

// Second derivatives
float fdd1(float x)
{
    return (-cos(x) - 2 * exp(x) - x * exp(x));
}
float fdd2(float x)
{
    return (0.434294481/x);
}
float fdd3(float x)
{
    return (-exp(-x));
}
float fdd4(float x)
{
    return (12 * x * x);
}
float fdd5(float x)
{
    return (-0.2 * exp(x));
}
float fdd6(float x)
{
    return (6 * x);
}
float fdd7(float x)
{
    return (2 * cos(x) - x * sin(x));
}
float fdd8(float x)
{
    return (-cos(x));
}
float fdd9(float x)
{
    return (-sin(x) - exp(x));
}
float fdd10(float x)
{
    return (6 * x - 2);
}

// phi(x)

float phi1(float x)
{
    return ((exp(-x)) * cos(x));
}
float phi2(float x)
{
    return (1.2/log10(x));
}
float phi3(float x)
{
    return (exp(-x));
}
float phi4(float x)
{
    return (x * x * x * x - 10);
}
float phi5(float x)
{
    return (0.2 * exp(x));
}
float phi6(float x)
{
    return ((x * x * x + 9) / 4);
}
float phi7(float x)
{
    return (1 / sin(x));
}
float phi8(float x)
{
    return ((cos(x) + 1) / 3);
}
float phi9(float x)
{
    return ((exp(x) - sin(x)) / 3);
}
float phi10(float x)
{
    return (x * x * x - x * x - 1);
}

void bisection()
{
    system("cls");
    topic("Bisection Method");
    FILE *fp;
    fp = fopen("bisection.txt", "a");
    if (fp == NULL)
    {
        puts("Can't open file");
        exit(0);
    }
    fprintf(fp, "******************************************************************************\n");

    int j, k = 0;
    float i, n1, n2, gap;
    double m, a0, b0, a, b, y, e;

    float (*f)(float);
    int let = 0;
    while ((let < 1) || (let > 10))
    {
        eqns();
        fflush(stdin);
        scanf("%d", &let);
        switch (let)
        {
        case 1:
            f = &f1;
            fprintf(fp, "cos(x) - x*exp(x) = 0 \n");
            printf("cos(x) - x*exp(x) = 0 \n");
            break;
        case 2:
            f = &f2;
            fprintf(fp, "x*log10(x) - 1.2 = 0 \n");
            printf("x*log10(x) - 1.2 = 0 \n");
            break;
        case 3:
            f = &f3;
            fprintf(fp, "x - e^(-x) = 0 \n");
            printf("x - e^(-x) = 0 \n");
            break;
        case 4:
            f = &f4;
            fprintf(fp, "x^4 - x - 10 = 0 \n");
            printf("x^4 - x - 10 = 0 \n");
            break;
        case 5:
            f = &f5;
            fprintf(fp, "x - (1/5)*exp(x) = 0 \n");
            printf("x - (1/5)*exp(x) = 0 \n");
            break;
        case 6:
            f = &f6;
            fprintf(fp, "x^3 - 4*x + 9 = 0 \n");
            printf("x^3 - 4*x + 9 = 0 \n");
            break;
        case 7:
            f = &f7;
            fprintf(fp, "x*sin(x) - 1 = 0 \n");
            printf("x*sin(x) - 1 = 0 \n");
            break;
        case 8:
            f = &f8;
            fprintf(fp, "cos(x) - 3*x + 1 = 0 \n");
            printf("cos(x) - 3*x + 1 = 0 \n");
            break;
        case 9:
            f = &f9;
            fprintf(fp, "3*x + sin(x) - exp(x) = 0 \n");
            printf("3*x + sin(x) - exp(x) = 0 \n");
            break;
        case 10:
            f = &f10;
            fprintf(fp, "x^3 - x^2 - x - 1 = 0 \n");
            printf("x^3 - x^2 - x - 1 = 0 \n");
            break;
        default:
            printf("Invalid Option \n");
        }
    }

    j = 0;

    while (j == 0)
    {
        printf(" Enter the range and increment: ");
        scanf("%f %f %f", &n1, &n2, &gap);
        for (i = n1; i < n2; i = i + gap)
        {
            if ((f(i) * f((i + gap))) < 0)
            {
                printf("\n Interval is f(%f,%f) (%f,%f)", f(i), f((i + gap)), i, (i + gap));
                j = 1;
            }
        }
        if (j == 0)
            printf("\n No root in this range \n Again");
    }

    while (1 < 3)
    {
        printf("\n Enter two initial approximations: ");
        scanf("%lf %lf", &a0, &b0);
        if ((f(a0) * f(b0)) < 0)
            break;
    }

    a = a0;
    b = b0;
    printf("Enter error tolerance: ");
    scanf("%lf", &e);
    char str[7][12] = {"k", "a", "b", "m", "f(m)", "y"};
    fprintf(fp, "\n %3s %12s %12s %12s %13s %12s\n", str[0], str[1], str[2], str[3], str[4], str[5]);
    fprintf(fp, "------------------------------------------------------------------------------");
    while (k < MAXITR1)
    {
        k = k + 1;
        m = ((a + b) / 2);
        y = (f(m) * f(a));
        fprintf(fp, "\n %3d | %12.9lf | %12.9lf | %12.9lf | %12.9lf | %12.9lf", k, a, b, m, f(m), y);
        if (y < 0)
            b = m;
        else
            a = m;
        if (fabs(f(m)) < e)
        {
            fprintf(fp, "\n Converging and number of iterations by method are %d", k);
            fprintf(fp, "\n n>= %f", (log(b0 - a0) - log(e)) / log(2));
            fprintf(fp, "\n Root is %12.9lf\n", (y < 0 ? ((a + m) / 2) : ((b + m) / 2)));
            break;
        }
    } // end of while

    if ((k == MAXITR1) && (fabs(f(m)) >= e))
    {
        fprintf(fp, "\n Not Converging and number of iterations by method are %d", k);
        fprintf(fp, "\n n>= %f", (log(b0 - a0) - log(e)) / log(2));
        fprintf(fp, "\n Root is %12.9lf\n", (y < 0 ? ((a + m) / 2) : ((b + m) / 2)));
    }
    fprintf(fp, "******************************************************************************\n");
    fprintf(fp, "\n");
    fclose(fp);
    filegame("bisection");
    carryon();
    fflush(stdin); getchar();
}

void secantr()
{
    system("cls");
    topic("Secant Method");
    int j, k = 0;
    float i, n1, n2, gap;
    double x0, x1, x2, y, e;

    float (*f)(float);
    int let = 0;
    while ((let < 1) || (let > 10))
    {
        eqns();
        fflush(stdin);
        scanf("%d", &let);
        switch (let)
        {
        case 1:
            f = &f1;
            printf("cos(x) - x*exp(x) = 0 \n");
            break;
        case 2:
            f = &f2;
            printf("x^2 + 4*sin(x) \n");
            break;
        case 3:
            f = &f3;
            printf("x - e^(-x) = 0 \n");
            break;
        case 4:
            f = &f4;
            printf("x^4 - x - 10 = 0 \n");
            break;
        case 5:
            f = &f5;
            printf("x - (1/5)*exp(x) = 0 \n");
            break;
        case 6:
            f = &f6;
            printf("x^3 - 4*x + 9 = 0 \n");
            break;
        case 7:
            f = &f7;
            printf("x*sin(x) - 1 = 0 \n");
            break;
        case 8:
            f = &f8;
            printf("cos(x) - 3*x + 1 = 0 \n");
            break;
        case 9:
            f = &f9;
            printf("3*x + sin(x) - exp(x) = 0 \n");
            break;
        case 10:
            f = &f10;
            printf("x^3 - x^2 - x - 1 = 0 \n");
            break;
        default:
            printf("Invalid Option \n");
        }
    }

    j = 0;

    while (j == 0)
    {
        printf(" Enter the range and increment: ");
        scanf("%f %f %f", &n1, &n2, &gap);
        for (i = n1; i < n2; i = i + gap)
        {
            if ((f(i) * f((i + gap))) < 0)
            {
                printf("\n Interval is f(%f,%f) (%f,%f)", f(i), f((i + gap)), i, (i + gap));
                j = 1;
            }
        }
        if (j == 0)
            printf("\n No root in this range \n Again");
    }

    do
    {
        printf("\n Enter initial Approx ");
        scanf("%lf %lf", &x0, &x1);
    } while ((f(x0) * f(x1)) > 0);

    printf("Enter error tolerance: ");
    scanf("%lf", &e);
    if (let == 2 && e < 0.000001)
    {
        e = 0.000001;
        printf("error tolerance changed to %f to avoid unexpected results", e);
    }

    printf("\n \t x0 \t\t x1 \t\t x2 \t\t f(x2) \n");
    printf("---------------------------------------------------------------- \n");

    while (k < MAXITR2)
    {
        k++;
        x2 = x1 - ((x1 - x0) / (f(x1) - f(x0))) * f(x1);
        printf(" %2d | %12.9lf | %12.9lf | %12.9lf | %12.9lf \n", k, x0, x1, x2, f(x2));
        x0 = x1;
        x1 = x2;
        if (fabs(f(x2)) < e)
        {
            printf("\n Converging and root after %d iterations is %12.9lf", k, x2);
            break;
        }
    }

    if ((k == MAXITR2) && (fabs(f(x2)) >= e))
    {
        printf("\n Not converging and root after %d iterations is %12.9lf", k, x2);
    }
    carryon();
    fflush(stdin); fflush(stdin); getchar();
}

void regula()
{
    system("cls");
    topic("Regula Falsi Method");
    int j, k = 0;
    float i, n1, n2, gap;
    double x0, x1, x2, y, e;

    float (*f)(float);
    int let = 0;
    while ((let < 1) || (let > 10))
    {
        eqns();
        fflush(stdin);
        scanf("%d", &let);
        switch (let)
        {
        case 1:
            f = &f1;
            printf("cos(x) - x*exp(x) = 0 \n");
            break;
        case 2:
            f = &f2;
            printf("x^2 + 4*sin(x) \n");
            break;
        case 3:
            f = &f3;
            printf("x - e^(-x) = 0 \n");
            break;
        case 4:
            f = &f4;
            printf("x^4 - x - 10 = 0 \n");
            break;
        case 5:
            f = &f5;
            printf("x - (1/5)*exp(x) = 0 \n");
            break;
        case 6:
            f = &f6;
            printf("x^3 - 4*x + 9 = 0 \n");
            break;
        case 7:
            f = &f7;
            printf("x*sin(x) - 1 = 0 \n");
            break;
        case 8:
            f = &f8;
            printf("cos(x) - 3*x + 1 = 0 \n");
            break;
        case 9:
            f = &f9;
            printf("3*x + sin(x) - exp(x) = 0 \n");
            break;
        case 10:
            f = &f10;
            printf("x^3 - x^2 - x - 1 = 0 \n");
            break;
        default:
            printf("Invalid Option \n");
        }
    }

    j = 0;

    while (j == 0)
    {
        printf(" Enter the range and increment: ");
        scanf("%f %f %f", &n1, &n2, &gap);
        for (i = n1; i < n2; i = i + gap)
        {
            if ((f(i) * f(i + gap)) < 0)
            {
                printf("\n Interval is f(%f,%f) (%f,%f)", f(i), f(i + gap), i, (i + gap));
                j = 1;
            }
        }
        if (j == 0)
            printf("\n No root in this range \n Again");
    }

    do
    {
        printf("\n Enter initial Approx ");
        scanf("%lf %lf", &x0, &x1);
    } while ((f(x0) * f(x1)) > 0);

    printf("Enter error tolerance: ");
    scanf("%lf", &e);
    printf("\n k \t xk \t\t x(k+1) \t x(k+2)      f(x(k+2)) \n");
    printf("------------------------------------------------------------------ \n");

    while (k < MAXITR3)
    {
        // k++;
        x2 = (x0 * f(x1) - x1 * f(x0)) / (f(x1) - f(x0));
        printf(" %2d | %12.9lf | %12.9lf | %12.9lf | %12.9lf \n", k, x0, x1, x2, f(x2));
        k++;

        if (f(x0) * f(x2) < 0)
            x1 = x2;
        else
            x0 = x2;

        if (fabs(f(x2)) < e)
        {
            printf("\n Converging and root after %d iterations is %12.9lf", k, x2);
            break;
        }
    }

    if ((k == MAXITR3) && (fabs(f(x2)) >= e))
    {
        printf("\n Not converging and root after %d iterations is %12.9lf", k, x2);
    }
    carryon();
    fflush(stdin); getchar();
}

void newtonr()
{
    system("cls");
    topic("Newton Raphson Method");
    int j, k = 0;
    float n1, n2, g, i;
    double x0, x1, e;

    float (*f)(float);
    float (*fd)(float);
    int let = 0;
    while ((let < 1) || (let > 10))
    {
        eqns();
        fflush(stdin);
        scanf("%d", &let);
        switch (let)
        {
        case 1:
            f = &f1;
            fd = &fd1;
            printf("cos(x) - x*exp(x) = 0\n");
            break;
        case 2:
            f = &f2;
            fd = &fd2;
            printf("x*log10(x) - 1.2 = 0 \n");
            break;
        case 3:
            f = &f3;
            fd = &fd3;
            printf("x - e^(-x) \n");
            break;
        case 4:
            f = &f4;
            fd = &fd4;
            printf("x^4 - x - 10 \n");
            break;
        case 5:
            f = &f5;
            fd = &fd5;
            printf("x - (1/5)*exp(x) = 0 \n");
            break;
        case 6:
            f = &f6;
            fd = &fd6;
            printf("x^3 - 4*x + 9 = 0 \n");
            break;
        case 7:
            f = &f7;
            fd = &fd7;
            printf("x*sin(x) - 1 = 0 \n");
            break;
        case 8:
            f = &f8;
            fd = &fd8;
            printf("cos(x) - 3*x + 1 = 0 \n");
            break;
        case 9:
            f = &f9;
            fd = &fd9;
            printf("3*x + sin(x) - exp(x) = 0 \n");
            break;
        case 10:
            f = &f10;
            fd = &fd10;
            printf("x^3 - x^2 - x - 1 = 0 \n");
            break;
        default:
            printf("Invalid Option \n");
        }
    }

    j = 0;

    while (j == 0)
    {
        printf(" Enter the range and increment: ");
        scanf("%f %f %f", &n1, &n2, &g);
        for (i = n1; i < n2; i = i + g)
        {
            if ((f(i) * f(i + g)) < 0)
            {
                printf("\n Interval is f(%f,%f) (%f,%f)", f(i), f(i + g), i, (i + g));
                j = 1;
            }
        }
        if (j == 0)
            printf("\n No root in this range \n Again");
    }

    printf("\nEnter one initial approximation x0: ");
    scanf("%lf", &x0);
    printf("Enter error tolerance: ");
    scanf("%lf", &e);

    printf(" k \t xk \t \t x(k+1)      f(x(k+1)) \n");

    while (k < MAXITR2)
    {
        x1 = x0 - (f(x0) / fd(x0));
        printf("%2d | %12.9lf | %12.9lf | %12.9lf \n", k, x0, x1, f(x1));
        k++;
        x0 = x1;
        if (fabs(f(x1)) < e)
        {
            printf("Converging and root after %d iterations is %12.9lf \n", k, x1);
            break;
        }
    }

    if ((k == MAXITR2) && (fabs(f(x1)) >= e))
    {
        printf("Not Converging and root after %d iterations is %12.9lf", k, x1);
    }
    carryon();
    fflush(stdin); getchar();
}

void chebyshev()
{
    system("cls");
    topic("Chebyshev's Method");
    int j, k = 0;
    float n1, n2, g, i;
    double x0, x1, e;

    float (*f)(float);
    float (*fd)(float);
    float (*fdd)(float);
    int let = 0;
    while ((let < 1) || (let > 10))
    {
        eqns();
        fflush(stdin);
        scanf("%d", &let);
        switch (let)
        {
        case 1:
            f = &f1;
            fd = &fd1;
            fdd = &fdd1;
            printf("cos(x) - x*exp(x) = 0 \n");
            break;
        case 2:
            f = &f2;
            fd = &fd2;
            fdd = &fdd2;
            printf("x*log10(x) - 1.2 = 0 \n");
            break;
        case 3:
            f = &f3;
            fd = &fd3;
            fdd = &fdd3;
            printf("x - e^(-x) = 0 \n");
            break;
        case 4:
            f = &f4;
            fd = &fd4;
            fdd = &fdd4;
            printf("x^4 - x - 10 = 0 \n");
            break;
        case 5:
            f = &f5;
            fd = &fd5;
            fdd = &fdd5;
            printf("x - (1/5)*exp(x) = 0 \n");
            break;
        case 6:
            f = &f6;
            fd = &fd6;
            fdd = &fdd6;
            printf("x^3 - 4*x + 9 = 0 \n");
            break;
        case 7:
            f = &f7;
            fd = &fd7;
            fdd = &fdd7;
            printf("x*sin(x) - 1 = 0 \n");
            break;
        case 8:
            f = &f8;
            fd = &fd8;
            fdd = &fdd8;
            printf("cos(x) - 3*x + 1 = 0 \n");
            break;
        case 9:
            f = &f9;
            fd = &fd9;
            fdd = &fdd9;
            printf("3*x + sin(x) - exp(x) = 0 \n");
            break;
        case 10:
            f = &f10;
            fd = &fd10;
            fdd = &fdd10;
            printf("x^3 - x^2 - x - 1 = 0 \n");
            break;
        default:
            printf("Invalid Option \n");
        }
    }

    j = 0;

    while (j == 0)
    {
        printf(" Enter the range and increment: ");
        scanf("%f %f %f", &n1, &n2, &g);
        for (i = n1; i < n2; i = i + g)
        {
            if ((f(i) * f(i + g)) < 0)
            {
                printf("\n Interval is f(%f,%f) (%f,%f)", f(i), f(i + g), i, (i + g));
                j = 1;
            }
        }
        if (j == 0)
            printf("\n No root in this range \n Again");
    }

    printf("\nEnter one initial approximation x0: ");
    scanf("%lf", &x0);

    if (let == 9)
    {
        printf("\nError tolerance taken: 0.000001\n");
        e = 0.000001;
    }
    else
    {
        printf("\nEnter error tolerance: ");
        scanf("%f", &e);
    }

    printf(" k \t xk \t \t x(k+1)      f(x(k+1)) \n");

    while (k < MAXITR2)
    {
        x1 = x0 - (f(x0) / fd(x0)) - (f(x0) * f(x0) * fdd(x0)) / (2 * fd(x0) * fd(x0) * fd(x0));
        printf("%2d | %12.9lf | %12.9lf | %12.9lf \n", k, x0, x1, f(x1));
        k++;
        x0 = x1;
        if (fabs(f(x1)) < e)
        {
            printf("Converging and root after %d iterations is %12.9lf \n", k, x1);
            break;
        }
    }

    if ((k == MAXITR2) && (fabs(f(x1)) >= e))
    {
        printf("Not Converging and root after %d iterations is %12.9lf", k, x1);
    }
    carryon();
    fflush(stdin); getchar();
}

void muller()
{
    system("cls");
    topic("Muller Method");
    int j, k = 0;
    float i, n1, n2, g;
    double x0, x1, x2, x3, h1, h2, l2, l3, d2, c2, g2, e;

    float (*f)(float);
    int let = 0;
    while ((let < 1) || (let > 10))
    {
        eqns();
        fflush(stdin);
        scanf("%d", &let);
        switch (let)
        {
        case 1:
            f = &f1;
            printf("cos(x) - x*exp(x) = 0 \n");
            break;
        case 2:
            f = &f2;
            printf("x^2 + 4*sin(x) \n");
            break;
        case 3:
            f = &f3;
            printf("x - e^(-x) = 0 \n");
            break;
        case 4:
            f = &f4;
            printf("x^4 - x - 10 = 0 \n");
            break;
        case 5:
            f = &f5;
            printf("x - (1/5)*exp(x) = 0 \n");
            break;
        case 6:
            f = &f6;
            printf("x^3 - 4*x + 9 = 0 \n");
            break;
        case 7:
            f = &f7;
            printf("x*sin(x) - 1 = 0 \n");
            break;
        case 8:
            f = &f8;
            printf("cos(x) - 3*x + 1 = 0 \n");
            break;
        case 9:
            f = &f9;
            printf("3*x + sin(x) - exp(x) = 0 \n");
            break;
        case 10:
            f = &f10;
            printf("x^3 - x^2 - x - 1 = 0 \n");
            break;
        default:
            printf("Invalid Option \n");
        }
    }

    j = 0;

    while (j == 0)
    {
        printf(" Enter the range and increment: ");
        scanf("%f %f %f", &n1, &n2, &g);
        for (i = n1; i < n2; i = i + g)
        {
            if ((f(i) * f(i + g)) < 0)
            {
                printf("\n Interval is f(%f,%f) (%f,%f)", f(i), f(i + g), i, (i + g));
                j = 1;
            }
        }
        if (j == 0)
            printf("\n No root in this range \n Again");
    }

    while (1 < 3)
    {
        printf("\nEnter three initial approximations: ");
        scanf("%lf %lf %lf", &x0, &x1, &x2);
        if (f(x0) * f(x2) < 0)
        {
            break;
        }
    }

    printf("Enter error tolerance: ");
    scanf("%lf", &e);

    printf(" k \t xk  \t      x(k+1) \t     x(k+2) \t   x(k+3) \t f(x(k+3)) \n");
    printf("-------------------------------------------------------------------------------\n");

    while (k < MAXITR2)
    {
        h2 = x2 - x1;
        h1 = x1 - x0;
        l2 = h2 / h1;
        d2 = 1 + l2;
        c2 = l2 * (l2 * f(x0) - d2 * f(x1) + f(x2));
        g2 = l2 * l2 * f(x0) - d2 * d2 * f(x1) + (l2 + d2) * f(x2);
        if (g2 < 0)
        {
            l3 = (-2 * d2 * f(x2)) / (g2 - sqrt(g2 * g2 - 4 * d2 * f(x2) * c2));
        }
        else if (g2 > 0)
        {
            l3 = (-2 * d2 * f(x2)) / (g2 + sqrt(g2 * g2 - 4 * d2 * f(x2) * c2));
        }
        x3 = x2 + (x2 - x1) * l3;

        printf("%2d | %12.9lf | %12.9lf | %12.9lf | %12.9lf | %12.9lf \n", k, x0, x1, x2, x3, f(x3));
        k++;
        x0 = x1;
        x1 = x2;
        x2 = x3;
        if (fabs(f(x3)) < e)
        {
            printf("Converging and smallest +ve root after %d iterations is %12.9lf \n", k, x3);
            break;
        }
    }

    if ((k == MAXITR2) && (fabs(f(x3)) >= e))
    {
        printf("Not Converging and smallest +ve root after %d iterations is %12.9lf", k, x3);
    }
    carryon();
    fflush(stdin); getchar();
}

void aitken()
{
    system("cls");
    topic("Aitken's Delta Square Method");
    int j, k = 0;
    float n1, n2, g, i;
    double x0, x0s, x1, x2, e;

    float (*f)(float);
    float (*phi)(float);
    int let = 0;
    while ((let < 1) || (let > 10))
    {
        eqns();
        fflush(stdin);
        scanf("%d", &let);
        switch (let)
        {
        case 1:
            f = &f1;
            phi = &phi1;
            printf("cos(x) - x*exp(x) = 0 \n");
            break;
        case 2:
            f = &f2;
            phi = &phi2;
            printf("x*log10(x) - 1.2 = 0 \n");
            break;
        case 3:
            f = &f3;
            phi = &phi3;
            printf("x - e^(-x) = 0 \n");
            break;
        case 4:
            f = &f4;
            phi = &phi4;
            printf("x^4 - x - 10 = 0 \n");
            break;
        case 5:
            f = &f5;
            phi = &phi5;
            printf("x - (1/5)*exp(x) = 0 \n");
            break;
        case 6:
            f = &f6;
            phi = &phi6;
            printf("x^3 - 4*x + 9 = 0 \n");
            break;
        case 7:
            f = &f7;
            phi = &phi7;
            printf("x*sin(x) - 1 = 0 \n");
            break;
        case 8:
            f = &f8;
            phi = &phi8;
            printf("cos(x) - 3*x + 1 = 0 \n");
            break;
        case 9:
            f = &f9;
            phi = &phi9;
            printf("3*x + sin(x) - exp(x) = 0 \n");
            break;
        case 10:
            f = &f10;
            phi = &phi10;
            printf("x^3 - x^2 - x - 1 = 0 \n");
            break;
        default:
            printf("Invalid Option \n");
        }
    }

    j = 0;

    while (j == 0)
    {
        printf(" Enter the range and increment: ");
        scanf("%f %f %f", &n1, &n2, &g);
        for (i = n1; i < n2; i = i + g)
        {
            if ((f(i) * f(i + g)) < 0)
            {
                printf("\n Interval is f(%f,%f) (%f,%f)", f(i), f(i + g), i, (i + g));
                j = 1;
            }
        }
        if (j == 0)
            printf("\n No root in this range \n Again");
    }

    printf("\nEnter one initial approximation x0: ");
    scanf("%lf", &x0);
    printf("Enter error tolerance: ");
    scanf("%lf", &e);

    printf(" k \t x0 \t \t x1 \t\t x2 \t    x0* \t f(x0*) \n");
    printf("-----------------------------------------------------------------------------\n");

    while (k < MAXITR2)
    {
        x1 = phi(x0);
        x2 = phi(x1);
        x0s = x0 - ((x1 - x0) * (x1 - x0) / (x2 - 2 * x1 + x0));
        printf("%2d | %12.9lf | %12.9lf | %12.9lf | %12.9lf | %12.9lf \n", k, x0, x1, x2, x0s, f(x0s));
        k++;
        x0 = x0s;

        if (fabs(f(x0s)) < e)
        {
            printf("Converging and root after %d iterations is %12.9lf \n", k, x0s);
            break;
        }
    }

    if ((k == MAXITR2) && (fabs(f(x0s)) >= e))
    {
        printf("Not Converging and root after %d iterations is %12.9lf", k, x1);
    }
    carryon();
    fflush(stdin); getchar();
}

float u(float x, float y)
{
    return (x * x * x - 3 * x * y * y + 1);
}
float v(float x, float y)
{
    return (3 * x * x * y - y * y * y);
}
float ux(float x, float y)
{
    return (3 * x * x - 3 * y * y);
}
float uy(float x, float y)
{
    return (-6 * x * y);
}
float vx(float x, float y)
{
    return (6 * x * y);
}
float vy(float x, float y)
{
    return (3 * x * x - 3 * y * y);
}

void binewton(float x0, float y0, float e)
{
    float x1, y1, u0, v0, ux0, vx0, uy0, vy0;
    int k = 0;
    char str[20][20] = {"k", "xk", "yk", "x(k+1)", "y(k+1)", "u(x(k+1) , y(k+1))", "v(x(k+1) , y(k+1))"};
    printf("\n%2s | %12s | %12s | %12s | %12s | %18s | %18s", str[0], str[1], str[2], str[3], str[4], str[5], str[6]);
    printf("\n------------------------------------------------------------------------------------------------------------");
    while (k < MAXITR2)
    {
        u0 = u(x0, y0);
        v0 = v(x0, y0);
        ux0 = ux(x0, y0);
        uy0 = uy(x0, y0);
        vx0 = vx(x0, y0);
        vy0 = vy(x0, y0);
        x1 = x0 - ((u0 * ux0 + v0 * vx0) / (ux0 * ux0 + vx0 * vx0));
        y1 = y0 - ((v0 * ux0 - u0 * vx0) / (ux0 * ux0 + vx0 * vx0));
        printf("\n%2d | %12.9f | %12.9f | %12.9f | %12.9f | %18.12f | %18.12f", k, x0, y0, x1, y1, u(x1, y1), v(x1, y1));
        k++;
        if ((fabs(x1 - x0) < e) && (fabs(y1 - y0) < e))
        {
            printf("\nConverging and root after %d iterations is %12.9f + %12.9f i", k, x1, y1);
            break;
        }
        x0 = x1;
        y0 = y1;
    }
    if (k == MAXITR2)
    {
        printf("\nNot Converging and root after %d iterations is %12.9f + %12.9f i", k, x1, y1);
    }
}

void twonewton()
{
    system("cls");
    topic("Method for Complex Roots\nNewton Raphson Method for two variables");
    printf("z^3 + 1 = 0");

    float x0, y0, e;
    int k = 0;
    printf("\nEnter initial approx x0,y0: ");
    scanf("%f %f", &x0, &y0);
    printf("Enter error tolerance: ");
    scanf("%f", &e);
    binewton(x0, y0, e);
    carryon();
    fflush(stdin); getchar();
}

void synthetic(float x[], float b[], float c[], int n, float p, float q)
{
    int i;
    b[0] = x[0];
    b[1] = x[1] - p * b[0];
    c[0] = b[0];
    c[1] = b[1] - p * c[0];

    for (i = 2; i <= n; i++)
    {
        b[i] = b[i - 1] * (-p) + x[i] + (-q) * b[i - 2];
        c[i] = (-p) * c[i - 1] + b[i] + (-q) * c[i - 2];
    }
    b[0] = x[0];
}

void croots(float a, float b, float c)
{
    float d, r1, r2, rr, ri;
    d = b * b - 4 * a * c;

    if (d >= 0)
    {
        r1 = (-b + sqrt(d)) / (2 * a);
        r2 = (-b - sqrt(d)) / (2 * a); // real roots
        printf("\nRequired roots are \n %f \n %f", r1, r2);
    }
    else
    {
        rr = -b / (2 * a);
        ri = sqrt(-d) / (2 * a);
        printf("\nThe roots are complex and are given by \n %f + %f i \n %f - %f i ", rr, ri, rr, ri);
    }
}

void bairstow()
{
    system("cls");
    topic("Bairstow Method");
    int i, j, k, n;
    k = 0;
    float p, q, p1, q1, e;
    printf("Enter degree of polynomial: ");
    scanf("%d", &n);
    float x[n + 1], b[n + 1], c[n];

    for (i = 0; i <= n; i++)
    {
        printf("Enter coeff of x[%d]: ", n - i);
        scanf("%f", &x[i]);
    }

    printf("Enter initial approx.\n");
    printf("p0 = ");
    scanf("%f", &p);
    printf("q0 = ");
    scanf("%f", &q);
    printf("Enter Error Tolerance: ");
    scanf("%f", &e);
    while (k < MAXITR2)
    {
        synthetic(x, b, c, n, p, q);
        for (i = 0; i <= n; i++)
        {
            printf("b[%d]\t\t", i);
        }
        printf("\n");

        for (i = 0; i <= n; i++)
        {
            printf("%f\t", b[i]);
        }
        printf("\n");
        for (i = 0; i < n; i++)
        {
            printf("c[%d]\t\t", i);
        }
        printf("\n");
        for (i = 0; i < n; i++)
        {
            printf("%f\t", c[i]);
        }
        printf("\n");

        p1 = p + (b[n - 1] * c[n - 2] - b[n] * c[n - 3]) / (c[n - 2] * c[n - 2] + b[n - 1] * c[n - 3] - c[n - 1] * c[n - 3]);
        q1 = q + (b[n] * c[n - 2] + b[n - 1] * b[n - 1] - c[n - 1] * b[n - 1]) / (c[n - 2] * c[n - 2] + b[n - 1] * c[n - 3] - c[n - 1] * c[n - 3]);
        k++;
        printf("\np[%d] = %f\n", k, p1);
        printf("q[%d] = %f\n", k, q1);
        if ((fabs(p - p1) < e) && (fabs(q - q1) < e))
        {
            printf("\nConverging");
            printf("\nThe required quadraric factor is:\n");
            printf("x^2 + %fx + %f", p1, q1);
            croots(1, p1, q1);
            break;
        }
        p = p1;
        q = q1;
    }
    if (k == MAXITR2)
    {
        printf("\nNot Converging");
        printf("\nThe required quadraric factor is:\n");
        printf("x^2 + %fx + %f", p1, q1);
        croots(1, p1, q1);
    }
    carryon();
    fflush(stdin); getchar();
}

void horner(float x[], float b[], float c[], int n, float p)
{
    int i;
    b[0] = x[0];
    c[0] = b[0];

    for (i = 1; i <= n; i++)
    {
        b[i] = p * b[i - 1] + x[i];
        c[i] = p * c[i - 1] + b[i];
    }
    b[0] = x[0];
}

void birge()
{
    system("cls");
    topic("Birge Vieta Method");
    FILE *fp;
    fp = fopen("birge.txt", "w");
    if (fp == NULL)
    {
        puts("Can't open file");
        exit(0);
    }

    int i, j, k, n;
    k = 0;
    float p, q, p1, q1, e;
    printf("Enter degree of polynomial: ");
    scanf("%d", &n);
    float x[n + 1], b[n + 1], c[n];

    for (i = 0; i <= n; i++)
    {
        printf("Enter coeff of x[%d]: ", n - i);
        scanf("%f", &x[i]);
    }

    printf("Enter initial approx.\n");
    printf("p0 = ");
    scanf("%f", &p);

    printf("Enter Error Tolerance: ");
    scanf("%f", &e);

    fprintf(fp, "\np[0]= %f\n", p);
    while (k < MAXITR2)
    {
        horner(x, b, c, n, p);
        for (i = 0; i <= n; i++)
        {
            fprintf(fp, "b[%d]\t\t", i);
        }
        fprintf(fp, "\n");

        for (i = 0; i <= n; i++)
        {
            fprintf(fp, "%f\t", b[i]);
        }
        fprintf(fp, "\n");
        for (i = 0; i < n; i++)
        {
            fprintf(fp, "c[%d]\t\t", i);
        }
        fprintf(fp, "\n");
        for (i = 0; i < n; i++)
        {
            fprintf(fp, "%f\t", c[i]);
        }
        fprintf(fp, "\n");

        p1 = p - (b[n] / c[n - 1]);
        k++;
        fprintf(fp, "\np[%d] = %f\n", k, p1);

        if ((fabs(p - p1) < e))
        {
            fprintf(fp, "\nConverging");
            fprintf(fp, "\nThe required linear factor is:\n");
            fprintf(fp, "x - %f", p1);
            fprintf(fp, "\nRequired Root = %f", p1);
            break;
        }
        p = p1;
    }
    if (k == MAXITR2)
    {
        fprintf(fp, "\nNot Converging");
        fprintf(fp, "\nThe required linear factor is:\n");
        fprintf(fp, "x - %f", p1);
        fprintf(fp, "\nRequired Root = %f", p1);
    }
    filegame("birge");
    fclose(fp);
    carryon();
    fflush(stdin); getchar();
}

float lagrangeInter(float x[], float f[], int n, float k)
{
    int i, j;
    float prod;
    float fx = 0;
    for (i = 0; i <= n; i++)
    {
        prod = 1;
        for (j = 0; j <= n; j++)
        {
            if (i != j)
            {
                prod = prod * (k - x[j]) / (x[i] - x[j]);
            }
        }
        fx += (prod * f[i]);
    }
    return (fx);
}

void lagrange()
{
    system("cls");
    topic("Lagrange Interpolation");
    FILE *fp;
    fp = fopen("lagrange.txt", "r");
    if (fp == NULL)
    {
        puts("Can't open file");
        exit(0);
    }

    float k;
    float fk;
    int i, j, n;
    float x[MXDDON], f[MXDDON];
    // float x[] = {0, 1, 3};
    // float f[] = {1, 3, 55};

    fscanf(fp, "%d", &n);
    // printf("Enter xi's and corresponding fi's: \n");
    for (i = 0; i <= n; i++)
    {
        // printf("Enter x%d = ",i);
        fscanf(fp, "%f", &x[i]);
        // printf("Enter f%d = ",i);
        fscanf(fp, "%f", &f[i]);
    }
    char str[][5] = {"x", "f(x)"};
    printf("%9s %9s \n", str[0], str[1]);
    for (i = 0; i <= n; i++)
    {
        printf("%9.4f %9.4f \n", x[i], f[i]);
    }

    // printf("Enter the point k for which you want to determine f(k): ");
    fscanf(fp, "%f", &k);
    fk = lagrangeInter(x, f, n, k);
    printf("\nP(%f) = %7.3f", k, fk);
    fclose(fp);
    carryon();
    fflush(stdin); getchar();
}

float multerm(int i, float k, float x[])
{
    float prod = 1;
    for (int j = 0; j < i; j++)
    {
        prod = prod * (k - x[j]);
    }
    return (prod);
}

// divided difference table
void divided(float x[], float y[][10], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            y[j][i] = (y[j][i - 1] - y[j + 1][i - 1]) / (x[j] - x[i + j]);
        }
    }
}

// Newton's divided difference formula
float newtondiv(float value, float x[], float y[][10], int n)
{
    float sum = y[0][0];

    for (int i = 1; i < n; i++)
    {
        sum = sum + (multerm(i, value, x) * y[0][i]);
    }
    return (sum);
}

// show divided diff table
void difftable(float y[][10], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            printf("%9.4f\t", y[i][j]);
        }
        printf("\n");
    }
}

void newt_div()
{
    system("cls");
    topic("Newton's Divided Difference Interpolation");
    int n, i;
    char str[6][6] = {"x", "f(x)"};
    printf("How many values: \n");
    scanf("%d", &n);
    float point, sum, y[10][10];

    float x[10];
    for (i = 0; i < n; i++)
    {
        printf("Enter x[%d] value: ", i);
        scanf("%f", &x[i]);
        printf("Enter function f[%d] value: ", i);
        scanf("%f", &y[i][0]);
        printf("\n");
    }

    printf("%9s\t%9s\n", str[0], str[1]);
    for (i = 0; i < n; i++)
    {
        printf("%9.4f\t%9.4f\n", x[i], y[i][0]);
    }

    // divided difference table
    divided(x, y, n);
    printf("\nThe Divided Difference Table is:\n");
    // printing divided difference table
    difftable(y, n);

    printf("Enter x for which you want to find f(x): ");
    scanf("%f", &point);

    // printing interpolated value
    printf("\nP(%f) = %9.4f\n", point, newtondiv(point, x, y, n));
    carryon();
    fflush(stdin); getchar();
}

float u_calf(float u, int n)
{
    float prod = u;
    for (int i = 1; i < n; i++)
    {
        prod = prod * (u - i);
    }
    return (prod);
}

float u_calb(float u, int n)
{
    float prod = u;
    for (int i = 1; i < n; i++)
    {
        prod = prod * (u + i);
    }

    return (prod);
}

float interpolatef(float x[], float f[][MXDDON], int n, float value)
{
    float sum = f[0][0];
    float u = (value - x[0]) / (x[1] - x[0]);
    for (int i = 1; i <= n; i++)
    {
        sum = sum + (u_calf(u, i) * f[0][i]) / factorial(i);
    }
    return (sum);
}

float interpolateb(float x[], float f[][MXDDON], int n, float value)
{
    float sum = f[n - 1][0];
    float u = (value - x[n - 1]) / (x[1] - x[0]);
    for (int i = 1; i <= n; i++)
    {
        sum = sum + (u_calb(u, i) * f[n - 1][i]) / factorial(i);
    }
    return (sum);
}

void newton_forward()
{
    system("cls");
    topic("Gregory Newton's Forward Interpolation");
    char str[6][16] = {"x", "f(x)", "Differences"};
    int n, i, j;
    float f[MXDDON][MXDDON], x[MXDDON];
    float v1, v2;
    FILE *fp;
    fp = fopen("newtinter.txt", "r");
    if (fp == NULL)
    {
        puts("Can't open file");
        exit(0);
    }
    fscanf(fp, "%d", &n); // reading value of n from file

    for (i = 0; i <= n; i++) // reading data from file
    {
        fscanf(fp, "%f", &x[i]);
        fscanf(fp, "%f", &f[i][0]);
    }

    // Calculating the forward difference table
    for (i = 1; i <= n; i++)
    {
        for (j = 0; j <= n - i; j++)
        {
            f[j][i] = f[j + 1][i - 1] - f[j][i - 1];
        }
    }

    // Displaying the forward difference table
    printf("Newton's Forward difference table is:\n");
    printf("%7s %14s %26s \n", str[0], str[1], str[2]);
    printf("-----------------------------------------------------------------------------------------\n");
    for (i = 0; i <= n; i++)
    {
        printf("%9.4f\t", x[i]);
        for (j = 0; j <= n - i; j++)
        {
            printf("%9.4f\t", f[i][j]);
        }
        printf("\n");
    }
    fscanf(fp, "%f %f", &v1, &v2); // Reading values to interpolate from file

    printf("\nP(%f) = %f\n", v1, interpolatef(x, f, n, v1));
    printf("P(%f) = %f\n", v2, interpolatef(x, f, n, v2));
    fclose(fp);
    carryon();
    fflush(stdin); getchar();
}

void newton_backward()
{
    system("cls");
    topic("Gregory Newton's Backward Interpolation");
    char str[6][16] = {"x", "f(x)", "Differences"};
    int n, i, j;
    float f[MXDDON][MXDDON], x[MXDDON];
    float v1, v2;
    FILE *fp;
    fp = fopen("newtinter.txt", "r");
    if (fp == NULL)
    {
        puts("Can't open file");
        exit(0);
    }
    fscanf(fp, "%d", &n); // reading value of n from file

    for (i = 0; i <= n; i++) // reading data from file
    {
        fscanf(fp, "%f", &x[i]);
        fscanf(fp, "%f", &f[i][0]);
    }

    // Calculating the backward difference table
    for (i = 1; i <= n; i++)
    {
        for (j = n; j >= i; j--)
        {
            f[j][i] = f[j][i - 1] - f[j - 1][i - 1];
        }
    }

    // Displaying the backward difference table
    printf("Newton's Backward difference table is:\n");
    printf("%7s %14s %26s \n", str[0], str[1], str[2]);
    printf("--------------------------------------------------------------------------------------\n");
    for (i = 0; i <= n; i++)
    {
        printf("%9.4f\t", x[i]);
        for (j = 0; j <= i; j++)
        {
            printf("%9.4f\t", f[i][j]);
        }
        printf("\n");
    }
    fscanf(fp, "%f %f", &v1, &v2);

    printf("\nP(%f) = %f\n", v1, interpolateb(x, f, n, v1));
    printf("P(%f) = %f\n", v2, interpolateb(x, f, n, v2));
    fclose(fp);
    carryon();
    fflush(stdin); getchar();
}
float g(float x)
{
    return (1 / (1 + x));
}
float integralTrape(float f[], float h, float n)
{
    float sum = 0;
    int i;
    float ans;
    for (i = 1; i <= n - 1; i++)
    {
        sum = sum + f[i];
    }
    ans = h * (f[0] + 2 * sum + f[(int)n]) / 2;
    return (ans);
}
void comptrape()
{
    system("cls");
    topic("Composite Trapezoidal Rule");
    printf("Integration (0 to 1) (1/(1+x))\n");
    float x[MXDINT], f[MXDINT];
    float h, a, b, n;
    int i;
    a = 0;
    b = 1;

    printf("Enter number of sub-intervals (max 20): ");
    scanf("%f", &n);
    h = (b - a) / n;
    x[0] = a;
    for (i = 1; i <= n; i++)
    {
        x[i] = x[0] + i * h;
    }
    printf("Nodes are: \n");
    for (i = 0; i <= n; i++)
    {
        printf("%f \t", x[i]);
        f[i] = g(x[i]);
    }

    printf("\nfunction values at these nodes\n");
    for (i = 0; i <= n; i++)
    {
        printf("%f \t", f[i]);
    }
    printf("\nRequired value of integral by composite Trapezoidal rule is: %12.9f", integralTrape(f, h, n));
    carryon();
    fflush(stdin); getchar();
}

float integralSimp(float f[], float h, float n)
{
    float sumo = 0, sume = 0;
    int i;
    float ans;
    for (i = 1; i <= n - 1; i++)
    {
        if (i % 2 == 0)
        {
            sume = sume + f[i];
        }
        else if (i % 2 != 0)
        {
            sumo = sumo + f[i];
        }
    }
    ans = h * (f[0] + 4 * sumo + 2 * sume + f[(int)n]) / 3;
    return (ans);
}
void compsimp()
{
    system("cls");
    topic("Composite Simpson's Rule");
    printf("Integration (0 to 1) (1/(1+x))\n");
    float x[MXDINT], f[MXDINT];
    float h, a, b, n;
    int i;
    a = 0;
    b = 1;

    printf("Enter number of sub-intervals: ");
    scanf("%f", &n);
    h = (b - a) / n;
    x[0] = a;
    for (i = 1; i <= n; i++)
    {
        x[i] = x[0] + i * h;
    }
    printf("Nodes are: \n");
    for (i = 0; i <= n; i++)
    {
        printf("%f \t", x[i]);
        f[i] = g(x[i]);
    }

    printf("\nfunction values at these nodes\n");
    for (i = 0; i <= n; i++)
    {
        printf("%f \t", f[i]);
    }
    printf("\nRequired value of integral by composite Simpson's rule is: %12.9f", integralSimp(f, h, n));
    carryon();
    fflush(stdin); getchar();
}

void cmp_newtcheby()
{
    system("cls");
    topic("Comparison between Newton Raphson and Chebyshev Method");
    char str[10][10] = {"k", "xk", "x(k+1)", "f(x(k+1))"};
    int j, k1, k2, k = 0;
    float n1, n2, g, i;
    double x0, t0, x1, e;

    float (*f)(float);
    float (*fd)(float);
    float (*fdd)(float);
    int let = 0;
    while ((let < 1) || (let > 10))
    {
        eqns();
        fflush(stdin);
        scanf("%d", &let);
        switch (let)
        {
        case 1:
            f = &f1;
            fd = &fd1;
            fdd = &fdd1;
            printf("cos(x) - x*exp(x) = 0 \n");
            break;
        case 2:
            f = &f2;
            fd = &fd2;
            fdd = &fdd2;
            printf("x*log10(x) - 1.2 = 0 \n");
            break;
        case 3:
            f = &f3;
            fd = &fd3;
            fdd = &fdd3;
            printf("x - e^(-x) = 0 \n");
            break;
        case 4:
            f = &f4;
            fd = &fd4;
            fdd = &fdd4;
            printf("x^4 - x - 10 = 0 \n");
            break;
        case 5:
            f = &f5;
            fd = &fd5;
            fdd = &fdd5;
            printf("x - (1/5)*exp(x) = 0 \n");
            break;
        case 6:
            f = &f6;
            fd = &fd6;
            fdd = &fdd6;
            printf("x^3 - 4*x + 9 = 0 \n");
            break;
        case 7:
            f = &f7;
            fd = &fd7;
            fdd = &fdd7;
            printf("x*sin(x) - 1 = 0 \n");
            break;
        case 8:
            f = &f8;
            fd = &fd8;
            fdd = &fdd8;
            printf("cos(x) - 3*x + 1 = 0 \n");
            break;
        case 9:
            f = &f9;
            fd = &fd9;
            fdd = &fdd9;
            printf("3*x + sin(x) - exp(x) = 0 \n");
            break;
        case 10:
            f = &f10;
            fd = &fd10;
            fdd = &fdd10;
            printf("x^3 - x^2 - x - 1 = 0 \n");
            break;
        default:
            printf("Invalid Option \n");
        }
    }

    j = 0;

    while (j == 0)
    {
        printf(" Enter the range and increment: ");
        scanf("%f %f %f", &n1, &n2, &g);
        for (i = n1; i < n2; i = i + g)
        {
            if ((f(i) * f(i + g)) < 0)
            {
                printf("\n Interval is f(%f,%f) (%f,%f)", f(i), f(i + g), i, (i + g));
                j = 1;
            }
        }
        if (j == 0)
            printf("\n No root in this range \n Again");
    }

    printf("\nEnter one initial approximation x0: ");
    scanf("%lf", &x0);
    printf("\nChoose lower error tolerance for better results");
    if (let == 9)
    {
        printf("\nError tolerance taken: 0.000001");
        e = 0.000001;
    }
    else
    {
        printf("\nEnter error tolerance: ");
        scanf("%f", &e);
    }

    t0 = x0;
    topic("Newton Raphson Method");
    printf("\n%2s | %12s | %12s | %12s", str[0], str[1], str[2], str[3]);

    while (k < MAXITR2)
    {
        x1 = x0 - (f(x0) / fd(x0));
        printf("\n%2d | %12.9lf | %12.9lf | %12.9lf", k, x0, x1, f(x1));
        x0 = x1;
        k++;
        if (fabs(f(x1)) < e)
        {
            printf("\nConverging and root after %d iterations is %12.9lf ", k, x1);
            break;
        }
    }

    if ((k == MAXITR2) && (fabs(f(x1)) >= e))
    {
        printf("\nNot Converging and root after %d iterations is %12.9lf", k, x1);
    }
    k1 = k;
    k = 0;
    x0 = t0;
    topic("Chebyshev's Method");
    while (k < MAXITR2)
    {
        x1 = x0 - (f(x0) / fd(x0)) - (pow(f(x0), 2) * fdd(x0) / (2 * pow(fd(x0), 3)));
        printf("\n%2d | %12.9lf | %12.9lf | %12.9lf", k, x0, x1, f(x1));
        x0 = x1;
        k++;

        if (fabs(f(x1)) < e)
        {
            printf("\nConverging and root after %d iterations is %12.9lf ", k, x1);
            break;
        }
    }

    if ((k == MAXITR2) && (fabs(f(x1)) >= e))
    {
        printf("\nNot Converging and root after %d iterations is %12.9lf", k, x1);
    }
    k2 = k;
    printf("\nConclusion:");
    printf("\nNewton Raphson Method takes %d iterations", k1);
    printf("\nChebyshev's Method takes %d iterations", k2);
    if (k1 < k2)
    {
        printf("\nHence Newton Raphson Method performed better\n");
    }
    else if (k1 > k2)
    {
        printf("\nHence Chebyshev's Method performed better\n");
    }
    else
    {
        printf("\nBoth Methods are equally good\n");
    }
    carryon();
    fflush(stdin); getchar();
}

#define jaswinder
#endif