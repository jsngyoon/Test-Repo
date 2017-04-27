#include <stdio.h>
#define MAX_DIM 50
 
int N;
int bio[MAX_DIM + 1][2];
 
int main(void) {
    int i, j, count;
 
    scanf("%d", &N);
    for (i = 0; i < N; i++) scanf("%d%d", &bio[i][0], &bio[i][1]);
 
    for (i = 0; i < N; i++) {
        for (j = 0, count = 0; j < N; j++) {
            if (j == i) continue;
            if (bio[i][0] < bio[j][0] && bio[i][1] < bio[j][1]) count++;
        }
        printf("%d ", count+1);
    }
 
    return 0;
}
