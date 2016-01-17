#include <stdio.h>
char star[300];
 
int main(void) {
    int N, i;
 
    scanf("%d", &N);
    for (i = 0; i < 2 * N - 1; i++) star[i] = '*';
    star[i] = '\0';
    for (i = 0; i < N; i++) {
        puts(star);
        star[i] = ' ';
        star[2 * N - 2 - i] = '\0';
    }
    return 0;
}

