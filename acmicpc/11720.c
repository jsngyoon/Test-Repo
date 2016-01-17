#include <stdio.h>
 
int main(void) {
    int N, i, sum;
    char number[101];
     
    scanf("%d", &N);
    scanf("%s", number);
    sum=0;
    for (i=0; i<N; i++) {
        sum += number[i] - '0';
    }
    printf("%d",sum);
    return 0;
     
}
