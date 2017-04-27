#include <stdio.h>
#define MAX_DIM 10000000
char card[2 * MAX_DIM + 1];
 
int main(void) {
    int N, M;
    int i, num;
 
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &num);
        num += MAX_DIM;
        card[num] = '1';
    }
 
    scanf("%d", &M);
    for (i = 0; i < M; i++) {
        scanf("%d", &num);
        num += MAX_DIM;
        if (card[num] == '1') printf("1 ");
        else printf("0 ");
    }
    return 0;
}
