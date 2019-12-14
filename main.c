#include <stdio.h>

int main()
{
    int n, g = 0;
    scanf("%d", &n);
    int A[n][n];
    int upsn, upsnb, x = 0, y = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) scanf("%d", &A[i][j]);
    }
    printf("\n");
    while (g < ((n * n)/2 - (n/2)+n)){

        for(upsn = 1; upsn <= n; upsn++) {

            if (upsn%2!=0) {
                for (upsnb = 0; upsnb < upsn; upsnb++) {
                    if(x!= 0 || y!= 0) {
                        printf("%d ",A[y][x]);
                        if(x!=0) {
                            x--;
                            y--;
                        }
                        else y--;
                        g++;
                    }
                    else {
                        printf("%d ",A[y][x]);
                        y++;
                        g++;
                    }
                }
            }

            else {
                for (upsnb = 0; upsnb < upsn; upsnb++) { if(x!= n-1 || y!= n-1) {
                        printf("%d ",A[y][x]);
                        if(y!=n-1) {
                            x++;
                            y++;
                        }
                        else x++;
                        g++;
                    }
                    else {
                        printf("%d ",A[y][x]);
                        y--;
                        g++;

                    }
                }
            }
        }
    }
    while (g < n*n) {

        for(upsn = n-1; upsn > 0; upsn--) {

            if (upsn%2!=0) {

                for (upsnb = 0; upsnb < upsn; upsnb++) { printf("%d ",A[y][x]);
                    if(y!=0) {
                        x--;
                        y--;
                    }
                    else x++;
                    g++;

                }
            }

            else {

                for (upsnb = 0; upsnb < upsn; upsnb++) {
                    printf("%d ",A[y][x]);
                    if(x!=n-1) {
                        x++;
                        y++;
                    }
                    else y--;
                    g++;
                }
            }

        }
    }
}