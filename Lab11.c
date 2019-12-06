//
// Created by Semka on 29-Nov-19.
//
#include<stdio.h>
#define zero '0'
#define one '1'

int main()
{
    int bool = -1; int count=0;

    char c;

    while( (c =getchar()) != EOF){

        if(c>=zero && c<=one){
            if (bool ==-1){
                bool++;
            }
            bool++;
            continue;
        }else
        {if (bool ==-1){
                continue;
            }
            if(bool%4 ==0){
                count++;
            }
            bool=-1;
        }}
    printf("%d\n", count);
}