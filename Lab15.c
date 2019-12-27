//
// Created by Semka on 21-Dec-19.
//

#include <stdio.h>

int main()
{
    int n;
    int nmin = 0;
    int nmax = 0;
    int pos = 0;
    int min = 1;
    int max = 1;
    int nm = 1;
    int a[9][9];
    scanf("%d",&n);
    if (n>9)
    {
        printf("Too big value");
        return 0;
    }
    for(int i=0;i<n; i++){
        for(int j=0;j<n; j++) {
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<n; i++){
        for(int j=0;j<n; j++) {
            printf("%d",a[i][j] );
            printf("  ");
        }
        printf("\n");
    }
    for(int j=0;j<n;j++){
        for(int i=0;i<n;i++)
        {
            if (j==0){
                max =max* a[i][j];
                min = max;
            }
            if(j>0){
                nm = nm*a[i][j];
            }
        }
    if(j!=0 && max<nm){
        nmax = j;
        max = nm;
    }

        if(j!=0 && min>nm){
            nmin = j;
            min = nm;
        }
       nm = 1;
    }


for(int i=0;i<n;i++){
    pos = a[nmin][i];
    a[nmin][i]= a[nmax][i];
    a[nmax][i] = pos;
}
    for(int j=0;j<n; j++){
        for(int i=0;i<n; i++) {
            printf("%d",a[j][i] );
            printf("  ");
        }
        printf("\n");
    }
    return 0;
}




