#include <stdio.h>
 
 
int main(void) {
    int N, car=5;
    int incoming, count = 0;
 
    scanf("%d", &N);
    while (car--) {
        scanf("%d", &incoming);
        if (incoming == N) count++;
    }
    printf("%d", count);
    return 0;
}
