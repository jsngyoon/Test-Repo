#include <stdio.h>
 
int main(void) {
    char s_num[3], s_newnum[3];
    int d, count = 0;
 
    scanf("%d", &d);
    s_num[0] = d / 10 + '0';
    s_num[1] = d % 10 + '0';
    s_newnum[0] = s_num[0];
    s_newnum[1] = s_num[1];
    while (1) {
        d = (s_newnum[0] - '0' + s_newnum[1] - '0') % 10;
        s_newnum[0] = s_newnum[1];
        s_newnum[1] = d + '0';
        count++;
        //printf("%c%c\n", s_newnum[0], s_newnum[1]);
        if (s_newnum[0] == s_num[0] && s_newnum[1] == s_num[1]) break;
    }
    printf("%d", count);
    return 0;
}
