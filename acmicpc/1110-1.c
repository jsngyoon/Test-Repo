#include <stdio.h>
 
int main(void) {
    int num, new_num, count = 0;
     
    scanf("%d",&num);
    new_num = num;
    do {
        new_num = (new_num % 10)*10 + (new_num / 10 + new_num % 10) % 10;
        count++;
    } while (new_num != num);
 
    printf("%d\n", count);
    return 0;
}
