//
// Created by Semka on 14-Dec-19.
//

#include <stdio.h>
#include <math.h>

double func(double x)
{
    double res;
    res = log(2+x);
    return res;
}

int main()
{
    double x, d, S, eps = 1., a = -1, b = 1, h = (b - a) / 10;
    int n;
    while (1. + eps > 1.)
    {
        eps /= 2.;
    }
    printf("Machine epsilon = %.21f\n", eps);
    printf("-------------------------------------------------------\n");
    printf("|  x   |         S          |        F(x)        | n  |\n");
    printf("|------|--------------------|--------------------|----|\n");


//    S = log(2);
//    d = 1;
//    n = 1;
    for (x = a; x <= b; x += h)
    {
        S = log(2);
        d = 1;
        n = 1;
        while ((d > eps || d < -eps) && n <= 100)
        {
            if (n == 1) d = x/2;
            else
             d = d * ((-x*(n-1))/(2*n));
            S += d;
            n++;
        }
        printf("| %.2f | %.16f | %.16f | %2d |\n", x, S, func(x), n);
    }
    printf("-------------------------------------------------------\n");
    return 0;
}