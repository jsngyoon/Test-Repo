#include <stdio.h>
char star[300];
 
int main(void) {
    int N, i;
 
    scanf("%d", &N);
    for (i = 0; i < 2 * N; i++) star[i] = ' ';
    star[i] = '\0';
    for (i = 0; i < N; i++) {
        star[i] = '*';
        star[2 * N - 1 - i] = '*';
        puts(star);
    }
    for (i = N - 1; i > 0; i--) {
        star[i] = ' ';
        star[2 * N - 1 - i] = ' ';
        puts(star);
    }
    return 0;
}
