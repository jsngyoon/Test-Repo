#include <stdio.h>
 
int main(void) {
    int N, num, len=0, i, d, NN=1;
    char B[50];
 
    scanf("%s %d", B, &N);
    while (B[len]) len++;
    for (num = 0, i = len - 1; i >= 0; i--) {
        d = (B[i] >= 'A') ? B[i] - 'A' + 10 : B[i] - '0';
        num += d * NN;
        NN *= N;
    }
    printf("%d\n", num);
    return 0;
}
