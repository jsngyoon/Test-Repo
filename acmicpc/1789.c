#include <stdio.h>
 
int main(void) {
    long long S, sum=0, i=1;
 
    scanf("%lld", &S);
    while (sum <= S) {
        sum += i;
        i++;
    }
    printf("%lld\n", i-2);
    return 0;
}
