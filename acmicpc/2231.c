#include <stdio.h>
#define MAX_DIM 1000000
 
int sum[MAX_DIM + 1];
 
int main(void) {
    int i, num;
    int N, creator;
 
    for (i = 1; i <= MAX_DIM; i++) {
        sum[i] += i;
        num = i;
        while (num) {
            sum[i] += num % 10;
            num /= 10;
        }
    }
    scanf("%d", &N);
    for (i = 1, creator = 0; i <= MAX_DIM; i++)
        if (sum[i] == N) {
            creator = i;
            break;
        }
    printf("%d", creator);
 
    return 0;
}
