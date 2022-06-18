#ifndef harmeet

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MXR 5
#define MXC 5
#define pi 3.141592653589793238

void add()
{
    int n;
    double sum = 0;
    printf("\n Enter the number of elements to add : ");
    scanf("%d", &n);

    double arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("enter val no. [%d]: ", i);
        scanf("%lf", &arr[i]);
        sum = sum + arr[i];
    }

    printf("\n The sum  of %d numbers is : %lf ", n, sum);
    fflush(stdin); getchar();
}
void Diff()
{
    int n = 2;
    double diff = 0;
    printf("\n Enter the elements to subtract : \n");
    double arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("enter val no. [%d]: ", i);
        scanf("%lf", &arr[i]);
        diff = diff - arr[i];
    }

    printf("\n The difference of %d numbers is : %lf ", n, diff);
    fflush(stdin); getchar();
}
void Prod()
{
    int n;
    double prod = 1;
    printf("\n Enter the number of elements to multiply : ");
    scanf("%d", &n);
    double arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("enter val no. [%d]: ", i);
        scanf("%lf", &arr[i]);
        prod = prod * arr[i];
    }

    printf("\n The product of %d numbers is  : %lf ", n, prod);
    fflush(stdin); getchar();
}
void Quot()
{
    double n1, n2, quot;
    while (1 < 2)
    {
        printf("Enter the two elements to divide : ");
        scanf("%lf%lf", &n1, &n2);
        if (n2 == 0)
            printf("\n Answer is not defined so kindly \n Again ");
        else
            break;
    }
    quot = n1 / n2;

    printf("\n the Required  quotient is : %lf ", quot);
    fflush(stdin); getchar();
}

void degtorad()
{
    double num, NUM;
    printf("\n\n Enter the number to convert into radian : ");
    scanf("%lf", &num);
    NUM = (pi * num) / 180.0;
    printf("\n The converted number is %lf", NUM);
    fflush(stdin); getchar();
}

void sine()
{
    double num;
    printf("\nEnter the number whose sine value you want(in rad) :");
    scanf("%lf", &num);
    printf("the required value is %lf ", sin(num));
    fflush(stdin); getchar();
}

void cosine()
{
    double num;
    printf("\nEnter the number whose cosine value you want(in rad) : ");
    scanf("%lf", &num);
    printf("the required value is %lf ", cos(num));
    fflush(stdin); getchar();
}

void tangent()
{
    double num;
    printf("\n\nEnter the number whose tangent value you want(in rad) : ");
    scanf("%lf", &num);
    printf("the required value is %lf ", tan(num));
    fflush(stdin); getchar();
}

void cotangent()
{
    double num;
    printf("\n\nEnter the number whose cotangent value you want(in rad) : ");
    scanf("%lf", &num);
    printf("the required value is %lf ", 1 / tan(num));
    fflush(stdin); getchar();
}

void secant()
{
    double num;
    printf("\n\nEnter the number whose secant value you want(in rad) : ");
    scanf("%lf", &num);
    printf("the required value is %lf ", 1 / cos(num));
    fflush(stdin); getchar();
}

void cosecant()
{
    double num;
    printf("\n\nEnter the number whose cosecant value you want(in rad) : ");
    scanf("%lf", &num);
    printf("the required value is %lf ", 1 / sin(num));
    fflush(stdin); getchar();
}

void sineinv()
{
    double num;
    printf("\n\nEnter the number whose sine inevrse value you want(in rad) : ");
    scanf("%lf", &num);
    printf("the required value is %lf ", asin(num));
    fflush(stdin); getchar();
}

void cosineinv()
{
    double num;
    printf("\n\nEnter the number whose cosine inevrse value you want(in rad) : ");
    scanf("%lf", &num);
    printf("the required value is %lf ", acos(num));
    fflush(stdin); getchar();
}

void taninv()
{
    double num;
    printf("\n\nEnter the number whose tangent inevrse value you want(in rad) : ");
    scanf("%lf", &num);
    printf("the required value is %lf ", atan(num));
    fflush(stdin); getchar();
}

void cotinv()
{
    double num;
    printf("\n\nEnter the number whose cotangent inevrse value you want(in rad) : ");
    scanf("%lf", &num);
    printf("the required value is %lf ", (pi / 2) - atan(num));
    fflush(stdin); getchar();
}

void secantinv()
{
    double num;
    printf("\n\nEnter the number whose secant inevrse value you want(in rad) : ");
    scanf("%lf", &num);
    printf("the required value is %lf ", acos(1 / num));
    fflush(stdin); getchar();
}

void cosecantinv()
{
    double num;
    printf("\n\nEnter the number whose cosecant inevrse value you want(in rad) : ");
    scanf("%lf", &num);
    printf("the required value is %lf ", asin(1 / num));
    fflush(stdin); getchar();
}

void sineh()
{
    double num;
    printf("\n\nEnter the number whose sine hyperbolic value you want(in rad) : ");
    scanf("%lf", &num);
    printf("the required value is %lf ", sinh(num));
    fflush(stdin); getchar();
}

void cosineh()
{
    double num;
    printf("\n\nEnter the number whose cosine hyperbolic value you want(in rad) : ");
    scanf("%lf", &num);
    printf("the required value is %lf ", cosh(num));
    fflush(stdin); getchar();
}

void tangenth()
{
    double num;
    printf("\n\nEnter the number whose tangent hyperbolic value you want(in rad) : ");
    scanf("%lf", &num);
    printf("the required value is %lf ", tanh(num));
    fflush(stdin); getchar();
}

void cotangenth()
{

    double num;
    printf("\n\nEnter the number whose cotangent hyperbolic value you want(in rad) : ");
    scanf("%lf", &num);
    printf("the required value is %lf ", 1 / tanh(num));
    fflush(stdin); getchar();
}

void secanth()
{
    double num;
    printf("\n\nEnter the number whose secant hyperbolic value you want(in rad) : ");
    scanf("%lf", &num);
    printf("the required value is %lf ", 1 / cosh(num));
    fflush(stdin); getchar();
}

void cosecanth()
{
    double num;
    printf("\n\nEnter the number whose cosecant hyperbolic value you want(in rad) : ");
    scanf("%lf", &num);
    printf("the required value is %lf ", 1 / sinh(num));
    fflush(stdin); getchar();
}

long double factorial(long double n)
{
    int i;
    long double f1 = 1;
    for (i = 1; i <= n; i++)
    {
        f1 = f1 * i;
    }
    return (f1);
}
void fact()
{
    long double f1, f2 = 1;
    int i;
    long double n;
    while (1)
    {
        printf("\n Enter a whole number (max 25) whose factorial and double factorial you want : ");
        scanf("%Lf", &n);
        if (n<=25 && n>=0)
        {
            break;
        }
        else
        {
            printf("Please Enter whole number <= 25 !!!\n");
        }
    }

    printf(" n is %.0Lf", n);
    f1 = factorial(n);

    for (i = n; i >= 1; i = i - 2)
    {
        f2 = f2 * i;
    }
    printf("\n Factorial of %.0Lf is :  %Lf\n", n, f1);
    printf("\n Double Factorial of %.0Lf is :  %Lf", n, f2);
    fflush(stdin); getchar();
}
void perm()
{
    int i;
    long double n, r, nf = 1, rf = 1, df = 1, nCr, nPr;
    printf("\n Enter the value of n and r : ");
    scanf("%Lf%Lf", &n, &r);
    // to find n!
    for (i = 1; i <= n; i++)
    {
        nf = i * nf;
    }
    // to find r!
    for (i = 1; i <= r; i++)
    {
        rf = i * rf;
    }
    // to find (n-r)!
    for (i = 1; i <= (n - r); i++)
    {
        df = i * df;
    }
    nPr = nf / (df);
    printf("\n The value of %Lf_P_%Lf is %Lf ", n, r, nPr);
    fflush(stdin); getchar();
}

void comb()
{
    int i;
    long double n, r, nf = 1, rf = 1, df = 1, nCr, nPr;

    printf("\n Enter the value of n and r : ");
    scanf("%Lf%Lf", &n, &r);
    // to find n!
    for (int i = 1; i <= n; i++)
    {
        nf = i * nf;
    }
    // to find r!
    for (i = 1; i <= r; i++)
    {
        rf = i * rf;
    }
    // to find (n-r)!
    for (i = 1; i <= (n - r); i++)
    {
        df = i * df;
    }
    nCr = nf / (rf * df);

    printf("\n The value of %Lf_C_%Lf is %Lf ", n, r, nCr);
    fflush(stdin); getchar();
}

void power()
{
    long double n, i, pow = 1;
    long double k;
    printf("\n Enter a number and power to which you want it to raise :  ");
    scanf("%Lf%Lf", &n, &k);
    for (i = 1; i <= k; i++)
    {
        pow = pow * n;
    }
    printf("\n %Lf raised to power %Lf is %Lf", n, k, pow);
    fflush(stdin); getchar();
}

void MATRIXADD()
{

    int nr, nc, row, col;
    int a[MXR][MXC], b[MXR][MXC], c[MXR][MXC];

    printf("\n Enter the number of rows and columns (max 5) :  ");
    scanf("%d%d", &nr, &nc);

    printf("\n Enter the first matrix:\n");
    for (row = 0; row < nr; row++)
    {
        for (col = 0; col < nc; col++)
        {
            printf("\n Enter a[%d][%d] element:- ", row, col);
            scanf("%d", &a[row][col]);
        }
    }

    // readinput(a, nr, nc);
    printf("\n The entered matrix is: \n");
    for (row = 0; row < nr; row++)
    {
        for (col = 0; col < nc; col++)
        {

            printf("%d\t", a[row][col]);
        }
        printf("\n");
    }

    // showoutput(a, nr, nc);

    printf("\n Enter the second matrix: ");
    for (row = 0; row < nr; row++)
    {
        for (col = 0; col < nc; col++)
        {
            printf("\n Enter b[%d][%d] element:- ", row, col);
            scanf("%d", &b[row][col]);
        }
    }

    // readinput(b, nr, nc);
    printf("\n The entered matrix is: \n");
    for (row = 0; row < nr; row++)
    {
        for (col = 0; col < nc; col++)
        {

            printf("%d\t", b[row][col]);
        }
        printf("\n");
    }

    // showoutput(b, nr, nc);

    // computesum(a, b, c, nr, nc);
    for (row = 0; row < nr; row++)
    {
        for (col = 0; col < nc; col++)
        {
            c[row][col] = a[row][col] + b[row][col];
        }
    }

    printf("\n The Sum of matrices is : \n");
    for (row = 0; row < nr; row++)
    {
        for (col = 0; col < nc; col++)
        {

            printf("%d\t", c[row][col]);
        }
        printf("\n");
    }
    // showoutput(c, nr, nc);
    fflush(stdin); getchar();
}

void MATRIXSUB()
{

    int nr, nc, row, col;
    int a[MXR][MXC], b[MXR][MXC], c[MXR][MXC];

    printf("\n Enter the number of rows and columns max 5:  ");
    scanf("%d%d", &nr, &nc);

    printf("\n Enter the first matrix:");
    for (row = 0; row < nr; row++)
    {
        for (col = 0; col < nc; col++)
        {
            printf("\n Enter a[%d][%d] element:- ", row, col);
            scanf("%d", &a[row][col]);
        }
    }

    // readinput(a, nr, nc);
    printf("\n The entered matrix is: \n");
    for (row = 0; row < nr; row++)
    {
        for (col = 0; col < nc; col++)
        {

            printf("%d\t", a[row][col]);
        }
        printf("\n");
    }

    // showoutput(a, nr, nc);

    printf("\n Enter the second matrix:");
    for (row = 0; row < nr; row++)
    {
        for (col = 0; col < nc; col++)
        {
            printf("\n Enter b[%d][%d] element:- ", row, col);
            scanf("%d", &b[row][col]);
        }
    }

    // readinput(b, nr, nc);
    printf("\n The entered matrix is: \n");
    for (row = 0; row < nr; row++)
    {
        for (col = 0; col < nc; col++)
        {

            printf("%d\t", b[row][col]);
        }
        printf("\n");
    }

    // showoutput(b, nr, nc);

    // computesum(a, b, c, nr, nc);
    for (row = 0; row < nr; row++)
    {
        for (col = 0; col < nc; col++)
        {
            c[row][col] = a[row][col] - b[row][col];
        }
    }

    printf("\n The difference of matrices is : \n");
    for (row = 0; row < nr; row++)
    {
        for (col = 0; col < nc; col++)
        {

            printf("%d\t", c[row][col]);
        }
        printf("\n");
    }
    // showoutput(c, nr, nc);
    fflush(stdin); getchar();
}

void MATRIXMUL()
{

    int nr1, nc1, nr2, nc2, row, col, i, k, j;
    int a[MXR][MXC], b[MXR][MXC], c[MXR][MXC];

    while (1 < 3)
    {
        printf("\n Enter the number of rows and columns for matrix one  (max 5) :  ");
        scanf("%d%d", &nr1, &nc1);
        printf("\n Enter the number of rows and columns for matrix second (max 5) : ");
        scanf("%d%d", &nr2, &nc2);
        if (nc1 == nr2)
            break;
        else
            printf("\n again \n");
    }

    // readinput(a, nr1, nc1);
    for (row = 0; row < nr1; row++)
    {
        for (col = 0; col < nc1; col++)
        {
            scanf("%d", &a[row][col]);
        }
    }

    printf("\n Enter first matrix: ");
    printf("\n the entered matrix is\n ");
    // showoutput(a, nr1, nc1);
    {
        for (col = 0; col < nc1; col++)
        {
            printf("\n enter a[%d][%d] element  : ", row, col);
            printf("%d\t", a[row][col]);
        }
        printf("\n");
    }

    printf("\n Enter second matrix :");
    for (row = 0; row < nr1; row++)
        // readinput(b, nr2, nc2);
        for (row = 0; row < nr2; row++)
        {
            for (col = 0; col < nc2; col++)
            {
                printf("\n enter b[%d][%d] element : ", row, col);
                scanf("%d", &b[row][col]);
            }
        }

    printf("\n The entered matrix is \n");
    // showoutput(b, nr2, nc2);
    for (row = 0; row < nr2; row++)
    {
        for (col = 0; col < nc2; col++)
        {
            printf("%d\t", b[row][col]);
        }
        printf("\n");
    }

    // computeproduct(a, b, c, nr1, nc1, nr2, nc2);
    for (i = 0; i < nr1; i++)
    {
        for (j = 0; j < nc2; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < nc1; k++)
            {
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
            }
        }
    }

    printf("\n Multiplication of matrices is : \n");
    // showoutput(c, nr1, nc2);
    for (row = 0; row < nr1; row++)
    {
        for (col = 0; col < nc2; col++)
        {
            printf("%d\t", c[row][col]);
        }
        printf("\n");
    }
    fflush(stdin); getchar();
}

void MATRIXTRANSPOSE()
{

    int nr, nc, row, col;
    int a[MXR][MXC], b[MXR][MXC];

    printf("\n Enter the number of rows and columns max 5 ");
    scanf("%d%d", &nr, &nc);

    printf("\n Enter the  matrix:");
    // readinput(a, nr, nc);
    for (row = 0; row < nr; row++)
    {
        for (col = 0; col < nc; col++)
        {
            printf("\n Enter a [%d][%d] element : ", row, col);
            scanf("%d", &a[row][col]);
        }
    }

    printf("\n The entered matrix is: \n");
    // showoutput(a, nr, nc);
    for (row = 0; row < nr; row++)
    {
        for (col = 0; col < nc; col++)
        {

            printf("%d\t", a[row][col]);
        }
        printf("\n");
    }

    // transpose(a, b, nr, nc);
    for (row = 0; row < nr; row++)
    {
        for (col = 0; col < nc; col++)
        {

            b[row][col] = a[col][row];
        }
    }

    printf("\n The transpose of matrix is : \n");
    // showoutput(b, nr, nc);
    for (row = 0; row < nr; row++)
    {
        for (col = 0; col < nc; col++)
        {

            printf("%d\t", b[row][col]);
        }

        printf("\n");
    }
    fflush(stdin); getchar();
}
void MATRIXDIAGONALSUM()
{

    int nr, nc, row, col, S = 0;
    int a[MXR][MXC];
    printf("\n Enter the number of rows and columns (max 5) :  ");
    scanf("%d%d", &nr, &nc);

    printf("\n Enter the matrix:");
    for (row = 0; row < nr; row++)
    {
        for (col = 0; col < nc; col++)
        {
            printf("\n Enter a[%d][%d] element: ", row, col);
            scanf("%d", &a[row][col]);
        }
    }

    printf("\n The entered matrix is: \n");
    for (row = 0; row < nr; row++)
    {
        for (col = 0; col < nc; col++)
        {

            printf("%d\t", a[row][col]);
        }
        printf("\n");
    }

    for (row = 0; row < nr; row++)
    {
        S = S + a[row][row];
    }

    printf("\n The sum of diagonal entries  is  %d ", S);
    fflush(stdin); getchar();
}

void LAR_SMALL_MATRIX()
{

    int nr, nc, row, col, S, L;
    int a[MXR][MXC];
    printf("\n Enter the number of rows and columns (max 5) :  ");
    scanf("%d%d", &nr, &nc);

    printf("\n Enter the matrix:");
    for (row = 0; row < nr; row++)
    {
        for (col = 0; col < nc; col++)
        {
            printf("\n Enter a[%d][%d] element: ", row, col);
            scanf("%d", &a[row][col]);
        }
    }

    printf("\n The entered matrix is: \n");
    for (row = 0; row < nr; row++)
    {
        for (col = 0; col < nc; col++)
        {

            printf("%d\t", a[row][col]);
        }
        printf("\n");
    }

    L = a[0][0];
    S = a[0][0];

    for (row = 0; row < nr; row++)
    {
        for (col = 0; col < nc; col++)
        {
            if (a[row][col] < S)
                S = a[row][col];

            if (a[row][col] > L)
                L = a[row][col];
        }
    }

    printf("\n The largest element is %d ", L);
    printf("\n The smallest element is %d ", S);
    fflush(stdin); getchar();
}

void LOGCAL()
{

    double num, bs, logcal;
    printf("\n Enter the number and base whose log u want : ");
    scanf("%lf%lf", &num, &bs);
    logcal = (log10(num)) / (log10(bs));
    printf("The required answer i.e. log(%lf,%lf) is %lf ", num, bs, logcal);
    fflush(stdin); getchar();
}

void circle()
{
    double r, sa, p;
    printf("Enter radius of circle : ");
    scanf("%lf", &r);
    sa = pi * r * r;
    p = 2 * pi * r;
    printf("\n Area of circle is %lf ", sa);
    printf("\n Perimeter of circle is %lf ", p);
    fflush(stdin); getchar();
}

void triangle()
{
    double a, b, c, area, H, s;
    printf("\n Enter 3 sides of triangle : ");
    scanf("%lf%lf%lf", &a, &b, &c);
    s = (a + b + c) / 3;
    H = s * (s - a) * (s - b) * (s - c);
    area = sqrt(H);
    printf("\n Area of the triangle is : %lf ", area);
    printf("\n Perimeter of the triangle is : %lf ", (a + b + c));
    fflush(stdin); getchar();
}

void square()
{
    double side, area, peri;
    printf("\n Enter side of square : ");
    scanf("%lf", &side);
    area = side * side;
    peri = 4 * side;
    printf("\n Area and perimeter of square are : %lfand %lf", area, peri);
    fflush(stdin); getchar();
}

void rect()
{
    double l, b, area, peri;
    printf("\n Enter length and breadth of rectangle : ");
    scanf("%lf%lf", &l, &b);
    area = l * b;
    peri = 2 * (l + b);
    printf("\n Area and perimeter of square are : %lfand %lf", area, peri);
    fflush(stdin); getchar();
}

void trape()
{
    double a, b, c, d, h, area, s;
    printf("\n Enter 2 sides of trapezium which are parallel : ");
    scanf("%lf%lf", &a, &b);
    printf("\n Enter other 2 non paralle sides of trapezium : ");
    scanf("%lf%lf", &c, &d);
    printf("\n enter the distance between parallel sides :");
    scanf("%lf", &h);
    s = (a + b + c + d);
    area = ((a + b) * h) / 2;
    printf("\n Area of the trapezium is : %lf ", area);
    printf("\n Perimeter of the trapezium is : %lf ", s);
    fflush(stdin); getchar();
}
void sector()
{
    double theta, r, arc, area, peri;
    printf("\n enter radius of circle and angle(in radians) subtended at the center  : ");
    scanf("%lf%lf", &r, &theta);
    area = (theta * pi * r * r) / 360;
    arc = (theta * 2 * pi * r) / 360;
    peri = arc + r + r;
    printf("\n Area of the sector is : %lf ", area);
    printf("\n Perimeter of the sector is : %lf ", peri);
    fflush(stdin); getchar();
}

void annulus()
{
    double r, R, area, peri;
    printf("\n Enter inner (r) and outer radius (R) r<R : ");
    scanf("%lf%lf", &r, &R);
    area = pi * (R * R - r * r);
    peri = 2 * pi * (r + R);
    printf("\n Area of the annulus is : %lf ", area);
    printf("\n Perimeter of the annulus is : %lf ", peri);
    fflush(stdin); getchar();
}
void cuboid()
{
    double l, b, h, tsa, csa, vol;
    printf("\n Enter length ,breadth,and height of cuboid : ");
    scanf("%lf%lf%lf", &l, &b, &h);
    tsa = 2 * (l * b + b * h + l * h);
    csa = 2 * h * (l + b);
    vol = l * b * h;
    printf("\n total surface area is %lf \n Lateral surface area is %lf \n Volume is %lf", tsa, csa, vol);
    fflush(stdin); getchar();
}
void cube()
{
    double a, tsa, csa, vol;
    printf("\n Enter side of cube (a) : ");
    scanf("%lf", &a);
    tsa = 6 * a * a;
    csa = 4 * a * a;
    vol = a * a * a;
    printf("\n total surface area is %lf \n Lateral surface area is %lf \n Volume is %lf", tsa, csa, vol);
    fflush(stdin); getchar();
}

void rccylinder()
{
    double r, h, tsa, csa, vol;
    printf("\n Enter radius (r) and height  (h) of right circular cylinder : ");
    scanf("%lf%lf", &r, &h);
    tsa = 2 * pi * r * (r + h);
    csa = 2 * pi * r * h;
    vol = pi * r * r * h;
    printf("\n total surface area is %lf \n Lateral surface area is %lf \n Volume is %lf", tsa, csa, vol);
    fflush(stdin); getchar();
}

void rccone()
{
    double r, h, l, tsa, csa, vol;
    printf("\n Enter radius (r),slant height (l) and height (h) of right circular cone : ");
    scanf("%lf%lf%lf", &r, &l, &h);
    tsa = pi * r * (r + l);
    csa = pi * r * l;
    vol = (pi * r * r * h) / 3;
    printf("\n total surface area is %lf \n Lateral surface area is %lf \n Volume is %lf", tsa, csa, vol);
    fflush(stdin); getchar();
}

void sphere()
{

    double r, tsa, vol;
    printf("\n Enter radius of sphere (r): ");
    scanf("%lf", &r);
    tsa = 4 * pi * r * r;
    vol = (4 * pi * r * r * r) / 3;
    printf("\n total surface area is %lf \n Volume is %lf", tsa, vol);
    fflush(stdin); getchar();
}

void hemisphre()
{
    double r, tsa, csa, vol;
    printf("\n Enter radius (r): ");
    scanf("%lf", &r);
    tsa = 3 * pi * r * r;
    csa = 2 * pi * r * r;
    vol = (2 * pi * r * r * r) / 3;
    printf("\n total surface area is %lf \n Lateral surface area is %lf \n Volume is %lf", tsa, csa, vol);
    fflush(stdin); getchar();
}

void frustum()
{
    double r, R, s, S, h, tsa, csa, vol;
    printf("\n Enter radius of upper base (r): ");
    scanf("%lf", &r);
    printf("\n Enter radius of lower base (R) : ");
    scanf("%lf", &R);
    printf("\n Enter  height (h): ");
    scanf("%lf", &h);

    S = (R - r) * (R - r) + h * h;
    s = sqrt(S);

    tsa = pi * (r + R) * s + pi * (r * r + R * R);
    csa = pi * (r + R) * s;
    vol = pi * h * (r * r + r * R + R * R) / 3;
    printf("\n total surface area is %lf \n Lateral surface area is %lf \n Volume is %lf", tsa, csa, vol);
    fflush(stdin); getchar();
}

#define harmeet
#endif