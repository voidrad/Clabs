//
// Created by Semka on 07-Dec-19.
//
#include <stdio.h>
//#include <"Set.h">

int main(){
    unsigned int set = 0;
    char c;
    unsigned int U = (1u « 26) - 1;
    short int ans = 0;
    while((c = getchar()) != EOF){
        if(c <= 'Z' && c>= 'A'){
            c += 'a' - 'A';
        }
        if(c == 'a' || c == 'e' || c == 'y' || c == 'u' || c == 'i' || c == 'o'){
            continue;
        }
        if(c == ' '){
            set = 0;
        }

        if(c - 'a' >= 0) {
            if(set & (1u « (c - 'a'))){
                ans = 1;
            }
            set = set | (1u « (c - 'a'));
        }
    }
    if(ans){
        printf("Yes Yes Yes");
    }
    else{
        printf("No No No");
    }
    return 0;
}
