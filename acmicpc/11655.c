#include <stdio.h>
#define MAX_DIM 100
 
char S[MAX_DIM + 1];
 
int main(void) {
    int i=0;
     
    gets(S);
    while (S[i] != '\0') {
        if ((S[i] >= 'A') && (S[i] <= 'Z')) {
            S[i] = (S[i] + 13 > 'Z') ? S[i] - 13 : S[i] + 13;
        }
        else if ((S[i] >= 'a') && (S[i] <= 'z')){
            S[i] = (S[i] + 13 > 'z') ? S[i] - 13 : S[i] + 13;
        }
        i++;
    }
    puts(S);
    return 0;
}

