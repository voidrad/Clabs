//
// Created by Semka on 07-Dec-19.
//
#include <stdio.h>
//#include <"Set.h">

int main(){
    unsigned int set = 0;
    char c;
    unsigned int U = (1u << 26) - 1;
    short int ans = 0;
    short i = 0;
    char this[20] = {0} ;
    while((c = getchar()) != EOF){
        this[i]= c;
        i++;
        if(c <= 'Z' && c>= 'A'){
            c += 'a' - 'A';
        }
        if(c == 'a' || c == 'e' || c == 'y' || c == 'u' || c == 'i' || c == 'o'){
            continue;
        }
        if(c == ' '){
            if (ans){
//                int  j;
//                for (j=0;j<=i-1;j++){
//                    printf('%c',this[j] );
//                }
                printf("%s", this);
//                ans = 0;
            }
            ans = 0;
            set = 0;
            i = 0;
            int p;
            for (p=0;p<=20;p++){
                this[p] = '\0';
            }
        }

        if(c - 'a' >= 0) {
            if(set & (1u << (c - 'a'))){
                ans = 1;
            }
            set = set | (1u << (c - 'a'));
        }
    }
//    if(ans){
//        printf("Yes");
//    }
//    else{
//        printf("No");
//    }
    return 0;
}
