//
// Created by Semka on 30-Nov-19.
//
#include<stdio.h>

int main(){

        long a = 0;
        long izn = 0;
        int ch = 0;
        int kolch = 0;
        int kolnc = 0;
        int nc = 0;
        long end = 0;
        scanf("%d", &a);

        izn = a;

        while(a>0){
            ch = a%10;
            a= a/10;
            if(ch%2 ==0){
                int i;
                long step =10;
                for (i = kolch;i>0;i--){
                    step = step*10;
                }
                 nc = end%(step/10);
                end = end/(step/10);
                end = end*10+ch;
                end = end*(step/10)+nc;
                nc = 0;
                 kolch++;

            }else{
                long step = 1;
                int i;
                for (i = (kolnc+kolch);i>0;i--){
                    step = step*10;
                }
                nc =end%step;
                end = end/step;
                end = end*10+ch;
                end = end*step+nc;
                kolnc++;
                nc = 0;
            }
        }
        printf("%d\n",end );
};


