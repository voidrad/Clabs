//
// Created by Semka on 21-Dec-19.
//
#include <stdio.h>

int main()
{
    int n;
    int a[9][9];
    scanf("%d",&n);
    if (n>9)
    {
        printf("Too big value");
        return 0;
    }
    for(int i=0;i<n; i++){
        printf("\n");
        for(int j=0;j<n; j++) {
            a[i][j] = (i+1)*10+j+1;
            printf("%d ", a[i][j]);
        }
    }
    printf("\n");
    printf("\n");
        short i,j;
        for (i=0;i<n;i++) {
            for (j=0;j<=i;j++) {
                printf("%d ", a[i-j][j]);
            }
        }
        for (j=1;j<n;j++) {
            for (i=0;i<=n-1-j;i++) {
                printf("%d ",a[n-1-i][j+i]);
            }
        }
            printf("\n");
        return 0;
    }






