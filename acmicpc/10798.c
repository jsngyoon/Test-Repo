#include <stdio.h>
char board[5][16];
int length[5];
 
int main(void) {
    int i, j;
    int max_length=0;
 
    for (i = 0; i < 5; i++) {
        scanf("%s", board[i]);
        length[i] = 0;
        while (board[i][length[i]] != '\0') length[i]++;
        if (length[i] > max_length) max_length = length[i];
    }
 
    for (i = 0; i < max_length; i++) {
        for (j = 0; j < 5; j++) {
            if (i < length[j]) printf("%c", board[j][i]);
        }
    }
     
    return 0;
}

