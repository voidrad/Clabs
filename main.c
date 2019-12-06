#include <stdio.h>

int main()
{
    int a[7][7], n, i, j, q, p,k;
    printf("Input your number:");
    scanf("%d", &n);
        if(n%2 == 1)
        {
            k=n/2;
        }else k=n/2 - 1;
    q=0;
    p=n-2;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            a[i][j]=(i+1)*10+(j+1);
        }
    }

    printf("Matrix :\n");

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%3d",a[i][j]);
        }
        printf("\n");
    }

    printf("Line :\n");


    for (int t=n-1;t>=0; t--)
    {
//        if(i==k && j==k){
//            break;
//        }
        for(i=q;i<=t;i++)
        {
            j=t;
            if((i!=k) || (j!= k))
            {printf("%3d",a[i][j]);}
            else { printf("%3d",a[i][j]); return 0;}

        }
        for(j=t-1;j>=0;j--)
        {
            i=t;
            if((i!=k) || (j!= k))
            {printf("%3d",a[i][j]);}
            else { printf("%3d",a[i][j]); return 0;}
        }
        for(i=p;i>=0;i--)
        {
            j=0;
            printf("%3d",a[i][j]);
        }
        for(j=q+1;j<t;j++)
        {
            i=0;
            printf("%3d",a[i][j]);
        }
        q++;
        p--;
    }
    return 0;
}
