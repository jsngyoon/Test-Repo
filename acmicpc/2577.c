#include <stdio.h>
int count[10];
 
int main(void) {
    int A, B, C, D, d;
    int i;
 
    scanf("%d%d%d", &A, &B, &C);
    D = A*B*C;
    while (D > 0) {
        d = D % 10;
        count[d]++;
        D /= 10;
    }
    for (i = 0; i < 10; i++) printf("%d\n", count[i]);
 
    return 0;
}
