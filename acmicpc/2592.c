#include <stdio.h>
#define MAX_DIM 100
 
int counter[MAX_DIM + 1];
 
int main(void) {
    int Innum, avg, freq, most;
    int i;
     
    for (i = 0; i <= MAX_DIM; i++) counter[i] = 0;
    for (i = 0, avg=0; i < 10; i++) {
        scanf("%d", &Innum);
        avg += Innum;
        counter[Innum / 10]++;
    }
    for (i = 0, freq = 0; i <= MAX_DIM; i++) {
        if (counter[i] > freq) {
            freq = counter[i];
            most = i;
        }
    }
    avg /= 10;
    most *= 10;
    printf("%d\n%d", avg, most);
    return 0;
}
