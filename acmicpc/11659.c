#include <stdio.h>
#define MAX_DIM 100000
 
int narr[MAX_DIM + 1];
int N, M;
 
int main(void) {
    int i, j;
    int num, begin, end, sum;
 
    scanf("%d %d", &N, &M);
    for (i = 1; i <= N; i++) {
        scanf("%d", &num);
        narr[i] = num + narr[i - 1];
    }
    for (i = 1; i <= M; i++) {
        scanf("%d %d", &begin, &end);
        sum = narr[end] - narr[begin - 1];
        printf("%d\n", sum);
    }
    return 0;
}
