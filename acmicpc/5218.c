#include <stdio.h>
char x[21], y[21];
 
int main(void) {
    int i, d;
    int N, length;
 
    scanf("%d", &N);
    while (N--) {
        scanf("%s %s", x, y);
        length = 0;
        while (x[length] != '\0') length++;
 
        printf("Distances: ");
        for (i = 0; i < length; i++) {
            d = y[i] - x[i];
            if (d < 0) d += 26;
            printf("%d ", d);
        }
        printf("\n");
    }
 
     
    return 0;
}
