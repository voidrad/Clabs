//
// Created by Semka on 27-Dec-19.
//

#include <stdio.h>
#include <math.h>
#define eps 0.00001
#define e 2.718281828459

double f1(double x)
{
    return sin(log(x)) - cos(log(x)) + 2*log(x);
}
double f2(double x)
{
    return x - 2 + sin(1/x);
}
double f3(double x)
{
    return pow(e, x) + log(x) - 10*x;
}
double p1(double x)
{
    return (2+cos(log(x))+sin(log(x))/x);
}
double p2(double x)
{
    return 1-cos(1/x)/(x*x);
}
double p3(double x)
{
    return pow(e, x) + 1/x - 10;
}
double F1(double x)
{
    return pow(e, (cos(log(x))-sin(log(x)))/2);
}
double F2(double x)
{
    return 2 - sin(1/x);
}
double F3(double x)
{
    return log(10*x-log(x));
}
//ÐœÐµÑ‚Ð¾Ð´ Ð´ÐµÐ»ÐµÐ½Ð¸Ñ Ð¿Ð¾Ð¿Ð¾Ð»Ð°Ð¼
double Delp( double f(double), double a, double b)
{
    double c;
    while (fabs(a - b) > eps) {
        c = (a + b) / 2.0;
        if (f(a) * f(c) > 0) a = c;
        else b = c;}
    return c;
}
//ÐœÐµÑ‚Ð¾Ð´ Ð¸Ñ‚ÐµÑ€Ð°Ñ†Ð¸Ð¸
double Iter(double F(double), double a, double b)
{
    double c = (a + b) / 2.;
    while (fabs(c - F(c)) > eps) {
        c = F(c);
    }
    return c;
}
//ÐœÐµÑ‚Ð¾Ð´ ÐÑŒÑŽÑ‚Ð¾Ð½Ð°
double New(double f(double), double p(double), double a, double b)
{
    double x0 = (a + b) / 2.0;
    double x1 = 0;
    while (fabs(x1 - x0) > eps) {
        x1 = x0;
        x0 -= f(x0) / p(x0);
    }
    return x0;
}
//ÐœÐµÑ‚Ð¾Ð´ Ñ…Ð¾Ñ€Ð´
double Hord(double f(double), double a, double b)
{
    double x = a, x1 = b;
    while(fabs(x-x1)>=eps)
    {
        x1 = x; x = (b*f(a)-a*f(b))/(f(a)-f(b));
        if(f(a)*f(b)>0)
        {
            a = x;
        } else b = x;
    }
    return x;
}

int main()
{
    printf("Function 1: sin(log(x)) - cos(log(x)) + 2*log(x)\n");
    printf("Function 1: dichotomy method = %.4f\n", Delp(f1,1,3));
    printf("Function 1: iteration method = %.4f\n", Iter(F1,1,3));
    printf("Function 1: Newton method = %.4f\n", New(f1,p1,1,3));
    printf("Function 1: hord method = %.4f\n", Hord(f1,1,3));
    printf("\n");
    printf("Function 2: x - 2 + sin(1/x)\n");
    printf("Function 2: dichotomy method = %.4f\n", Delp(f2,1.2,2));
    printf("Function 2: iteration method = %.4f\n", Iter(F2,1.2,2));
    printf("Function 2: Newton method = %.4f\n", New(f2,p2,1.2,2));
    printf("Function 2: hord method = %.4f\n", Hord(f2,1.2,2));
    printf("\n");
    printf("Function 3: e^x + ln(x) - 10x\n");
    printf("Function 3: dichotomy method = %.4f\n", Delp(f3,3,4));
    printf("Function 3: iteration method = %.4f\n", Iter(F3,3,4));
    printf("Function 3: Newton method = %.4f\n", New(f3,p3,3,4));
    printf("Function 3: hord method = %.4f\n", Hord(f3,3,4));
    printf("\n");
    return 0;
}