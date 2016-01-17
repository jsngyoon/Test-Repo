#include <stdio.h>
int list[100];
 
int main(void) {
    int N, P;
    int num, count = 0;
 
    scanf("%d %d", &N, &P);
    num = N;
     
    num = (num * N) % P;
    while (list[num] == 0) {
        count++;
        list[num] = count;
        num = (num *N) % P;
    }
    printf("%d\n", count - list[num] +1);
 
    return 0;
}
