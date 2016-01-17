#include <stdio.h>
char day[][4] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
int month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
 
int main(void) {
    int x, y;
    int i, count = 0;
 
    scanf("%d %d", &x, &y);
    for (i = 1; i < x; i++) count += month[i];
    count += y;
    count %= 7;
    printf("%s", day[count]);
     
    return 0;
}
