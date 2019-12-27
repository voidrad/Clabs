//
// Created by Semka on 14-Dec-19.
//

#include <stdio.h>
#include <math.h>

double func(double x)
{
    double res;
    res = log(x+2);
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
    printf("|  x   |         S          |       F            | n  |\n");
    printf("|------|--------------------|--------------------|----|\n");
    for (x = a; x <= b+0.001; x += h)
    {
        S = log(2);
        d = 1;
        n = 1;
       int  znk = -1;
        double znm =1.;
        double xn = 1.;
        while ((d > eps || d < -eps) && n <= 100)
        {
            int i;
            for(i = 0;i<=n; i++){
                xn *= x;
                znk *= -1;
                znm *= 2 ;
            }

             d = znk*xn/(n*znm );
            S += d;
            n++;
            znk = -1;
            znm =1;
            xn = 1;
        }
        printf("| %.2f | %.16f | %.16f | %2d |\n", x, S, func(x), n);
    }
    printf("-------------------------------------------------------\n");
    return 0;
}