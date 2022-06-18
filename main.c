#include "base.h"
#include "harmeet.h"
#include "hitika.h"
#include "satyam.h"
#include "siddhant.h"
#include "jaswinder.h"
#include "tarun.h"
void main()
{

    system("cls");
    int i, j, k;                    // switch level variables
    int p = 0, q = 0, r = 0, t = 0; // directional variables (back / exit )
    do
    {
        system("cls");
        // system("color 02");
        printf("\n         *********** CALCULATOR PROJECT ***********\n\n");
        top();
        message(1, "Mathematical Calculations");
        message(2, "Statistical Calculations");
        message(3, "Numerical Methods");
        message(0, "Exit");
        end();
        fflush(stdin);
        scanf("%d", &i);

        switch (i) // Level 1
        {
        case 1:
            do
            {

                top();
                head("Basic Arithmetic");
                message(1, "Addition");
                message(2, "Subtraction");
                message(3, "Multiplication");
                message(4, "Division");
                head("Trignometric manipulation");
                message(5, "Degree to Radian");
                message(6, "Sine (Radian)");
                message(7, "Cosine (Radian)");
                message(8, "Tangent (Radian)");
                message(9, "Cotangent (Radian)");
                message(10, "Secant (Radian)");
                message(11, "Cosecant (Radian)");
                message(12, "Sine inv (Radian)");
                message(13, "Cosine inv (Radian)");
                message(14, "Tangent inv (Radian)");
                message(15, "Cotangent inv (Radian)");
                message(16, "Secant inv (Radian)");
                message(17, "Cosecant inv (Radian)");
                message(18, "Sinh (Radian)");
                message(19, "Cosh (Radian)");
                message(20, "Tanh (Radian)");
                message(21, "Coth (Radian)");
                message(22, "Sech (Radian)");
                message(23, "Cosech (Radian)");
                printf("\n");
                message(24, "Factorial");
                message(25, "Permutation");
                message(26, "Combination");
                message(27, "x^n (power)");
                message(28, "logarithm");
                head("Area - Perimeter - Volume");
                sub_head("Two dimensional shape");
                message(29, "Circle");
                message(30, "Triangle");
                message(31, "Square");
                message(32, "Rectangle");
                message(33, "Trapezium");
                message(34, "Sector Of A Circle");
                message(35, "Annulus");
                sub_head("Three dimensional shape");
                message(36, "Cuboid");
                message(37, "Cube");
                message(38, "Right Circular Cylinder");
                message(39, "Right Circular Cone");
                message(40, "Sphere");
                message(41, "Hemisphere ");
                message(42, "Frustum");
                head("Matrices");
                message(43, "Matrix Addition");
                message(44, "Matrix Subtraction");
                message(45, "Matrix Multiplication");
                message(46, "Matrix Transpose");
                message(47, "Sum of diagonal entries");
                message(48, "Finding Largest and Smallest Entry");
                message(49, "Matrix Determinant");
                head("Sequence manipulation");
                message(50, "Ascending");
                message(51, "Descending");
                message(52, "Min");
                message(53, "Max");
                message(54, "Search a number");
                printf("\n");
                message(55, "LCM");
                message(56, "GCD");
                printf("\n");
                message(0, "Previous");
                message(-1, "Exit");
                end();
                fflush(stdin);
                scanf("%d", &j);

                switch (j) // Level 2
                {
                case -1:
                    exit(0); // Exit Program from outer Mathematical when user press -1.
                    break;
                case 0:
                    r = 1;
                    break;
                case 1:
                    topic("Addition");
                    add();
                    break;
                case 2:
                    topic("Subtraction");
                    Diff();
                    break;
                case 3:
                    topic("Multiplication");
                    Prod();
                    break;
                case 4:
                    topic(" Division");
                    Quot();
                    break;
                case 5:
                    topic(" Degree to radian");
                    degtorad();
                    break;
                case 6:
                    topic("Sine (radians)");
                    sine();
                    break;
                case 7:
                    topic(" Cosine (radians)");
                    cosine();
                    break;
                case 8:
                    topic(" Tangent (radians)");
                    tangent();
                    break;
                case 9:
                    topic("Cotangent (radians)");
                    cotangent();
                    break;
                case 10:
                    topic("Secant (radians)");
                    secant();
                    break;
                case 11:
                    topic("Cosecant (radians)");
                    cosecant();
                    break;
                case 12:
                    topic("Sine inv (radians)");
                    sineinv();
                    break;
                case 13:
                    topic("Cosine inv (radians)");
                    cosineinv();
                    break;
                case 14:
                    topic("Tangent inv (radians)");
                    taninv();
                    break;

                    topic("Cotangent inv (radians)");
                    cotinv();
                    break;
                case 16:
                    topic("Secant inv (radians)");
                    secantinv();
                    break;
                case 17:
                    topic("Cosecant inv (radians)");
                    cosecantinv();
                    break;
                case 18:
                    topic(" Sinh (radians)");
                    sineh();
                    break;
                case 19:
                    topic(" Cosh (radians)");
                    cosineh();
                    break;
                case 20:
                    topic("Tanh (radians)");
                    tangenth();
                    break;
                case 21:
                    topic("Coth (radians)");
                    cotangenth();
                    break;
                case 22:
                    topic("Sech (radians)");
                    secanth();
                    break;
                case 23:
                    topic("Cosech (radians)");
                    cosecanth();
                    break;
                case 24:
                    topic("Factorial");
                    fact();
                    break;
                case 25:
                    topic("Permutation");
                    perm();
                    break;
                case 26:
                    topic("Combination");
                    comb();
                    break;
                case 27:
                    topic(" x^n (power)");
                    power();
                    break;

                case 28:
                    topic(" Logarithm");
                    LOGCAL();
                    break;
                case 29:
                    topic(" Circle");
                    circle();
                    break;

                case 30:
                    topic(" Triangle");
                    triangle();
                    break;

                case 31:
                    topic("Square");
                    square();
                    break;

                case 32:
                    topic("Rectangle");
                    rect();
                    break;

                case 33:
                    topic("Trapezium");
                    trape();
                    break;

                case 34:
                    topic("Sector of circle");
                    sector();
                    break;

                case 35:
                    topic("Annulus");
                    annulus();
                    break;
                case 36:
                    topic("Cuboid");
                    cuboid();
                    break;
                case 37:

                    topic("Cube");
                    cube();
                    break;

                case 38:
                    topic("Right Circular Cylinder");
                    rccylinder();
                    break;

                case 39:
                    topic("Right Circular Cone");
                    rccone();
                    break;

                case 40:
                    topic("Sphere");
                    sphere();
                    break;

                case 41:
                    topic("Hemisphere");
                    hemisphre();
                    break;

                case 42:
                    topic("Frustum");
                    frustum();
                    break;

                case 43:
                    topic("Matrix addition");
                    MATRIXADD();
                    break;
                case 44:
                    topic("Matrix Subtraction");
                    MATRIXSUB();
                    break;
                case 45:
                    topic("Matrix Multiplication");
                    MATRIXMUL();
                    break;
                case 46:
                    topic("Matrix transpose");
                    MATRIXTRANSPOSE();
                    break;
                case 47:
                    topic("Sum of Diagonal Entries");
                    MATRIXDIAGONALSUM();
                    break;
                case 48:
                    topic("Finding Largest and Smallest Entry");
                    LAR_SMALL_MATRIX();
                    break;
                case 49:
                    topic("Matrix Determinant ");
                    matrix();
                    break;
                case 50:
                    topic("Ascending");
                    seq(1);
                    break;
                case 51:
                    topic("Descending");
                    seq(0);
                    break;
                case 52:
                    topic("Min");
                    seq(3);
                    break;
                case 53:
                    topic("Max");
                    seq(4);
                    break;
                case 54:
                    topic("Search");
                    search();
                    break;
                case 55:
                    topic("LCM");
                    lcm();
                    break;
                case 56:
                    topic("GCD");
                    gcd();
                    break;
                default:
                    printf("Invalid");
                    break;
                }
            } while (r == 0);
            break;

        case 2:
            do
            {
                printf("\nIn Statistical Calculations"); // Rock here Satyam Siddhant
                top();
                message(1, "Statistics 1");
                message(2, "Statistics 2");
                message(0, "Previous");
                message(-1, "exit");
                end();
                fflush(stdin);
                scanf("%d", &j);
                switch (j)
                {
                case 0:
                    t = 1;
                    break;
                case -1:
                    exit(0);
                    break;
                case 1:
                    input();
                    break;
                case 2:
                    input2();
                    break;

                default:
                    break;
                }

            } while (t == 0);
            break;

        case 3:
            system("cls");
            do
            {
                printf("\nIn Numerical Methods\n");
                top();
                head("Iterative Methods for roots");
                message(1, "Bisection Method");
                message(2, "Secant Method");
                message(3, "Regula Falsi Method");
                message(4, "Newton Raphson Method");
                message(5, "Chebyshev's Method");
                message(6, "Muller Method");
                message(7, "Aitken's Delta Square Method");
                message(8, "Method for Complex Roots");
                message(9, "Bierge-Vieta Method");
                message(10, "Bairstow Method");
                head("Interpolation");
                message(11, "Lagrange Interpolation");
                message(12, "Divided Difference Interpolation");
                message(13, "Newton's Forward Interpolation");
                message(14, "Newton's Backward Interpolation");
                head("Direct Methods for linear system");
                message(15, "Gauss Elimination Method");
                message(16, "Gauss Jordan Method");
                head("Numerical Integration");
                message(17,"Composite Trapezoidal Rule");
                message(18,"Composite Simpson's Rule");
                head("Comparisons");
                message(19,"Newton vs Chebyshev");
                head(" ");
                message(0, "Previous");
                message(-1, "Exit");
                end();
                fflush(stdin);
                scanf("%d", &j);
                switch (j) // Level 2
                {
                case 0:
                    q = 1; // Back from Numerical to Main Menu when user press 0.
                    break;
                case -1:
                    exit(0); // Exit Program from Numerical when user press -1.
                    break;
                case 1:
                    bisection();
                    break;
                case 2:
                    secantr();
                    break;
                case 3:
                    regula();
                    break;
                case 4:
                    newtonr();
                    break;
                case 5:
                    chebyshev();
                    break;
                case 6:
                    muller();
                    break;
                case 7:
                    aitken();
                    break;
                case 8:
                    twonewton();
                    break;
                case 9:
                    birge();
                    break;
                case 10:
                    bairstow();
                    break;
                case 11:
                    lagrange();
                    break;
                case 12:
                    newt_div();
                    break;
                case 13:
                    newton_forward();
                    break;
                case 14:
                    newton_backward();
                    break;
                case 15:
                    printf("In Gauss Elimination Method\n");
                    elimination();
                    break;
                case 16:
                    printf("In Gauss Jordan Method\n");
                    jordan();
                    break;
                case 17:
                    comptrape();
                    break;
                case 18:
                    compsimp();
                    break;
                case 19:
                    cmp_newtcheby();
                    break;
                default:
                    printf("Invalid\n");
                    break;
                }
            } while (q == 0);

            break;
        case 0:
            exit(0); // Exit program from Main Menu when user press 0. (As no sense of back in main menu)
            break;
        default:
            printf("Invalid");
        }
    } while (p == 0);
}