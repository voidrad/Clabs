//
// Created by Semka on 07-Dec-19.
//

#include <stdio.h>
#define i0 26
#define j0 8
#define l0 -3

//Задаем функцию эллипса
int func(int x, int y)
{
    return ((x - 20) * (x - 20) + 4*y*y)/100 < 1;
}

//Задаем функцию знака от числа
int sign(int x)
{
    if (x >= 0)
    {
        return 1;
    }
    else return -1;
}

//Задаем функцию минимального значения из двух
int min(int x, int y)
{
    return (x < y) ? x : y;
}

//Задаем функцию максимального значения из двух
int max(int x, int y)
{
    return (x > y) ? x : y;
}


int main()
{
    int i, j, l, k;
    int i_last = i0, j_last = j0, l_last = l0;

    for (k = 1; k <= 50; k++)
    {
        i =
        j =
        l =

        i_last = i;
        j_last = j;
        l_last = l;

        if (func(i, j))
        {
            printf("The point is inside the ellipse\n");
            printf("k = %d\n", k);
            printf("i = %d, j = %d, l = %d\n", i, j, l);
            break;
        }
        if (k == 50 && !func(i, j))
        {
            printf("No right answer\n");
        }
    }
    return 0;
}