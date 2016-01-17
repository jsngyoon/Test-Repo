#include <stdio.h>
 
 
int main(void) {
    int N, X;
    int incoming;
 
    scanf("%d %d", &N, &X);
    while (N--) {
        scanf("%d", &incoming);
        if (incoming < X) printf("%d ", incoming);
    }
 
    return 0;
}

