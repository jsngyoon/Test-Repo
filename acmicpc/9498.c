#include <stdio.h>
 
char *grade = "FFFFFFDCBAA";
 
int main(void) {
    int score;
    scanf("%d", &score);
    printf("%c", grade[score/10]);
    return 0;
}
