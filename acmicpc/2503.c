#include <stdio.h>
#define MAX_DIM 100
char guess[MAX_DIM + 1][4];
int strike[MAX_DIM + 1];
int ball[MAX_DIM + 1];
 
int calc_strike(char *guess, char *real) {
    int i, count = 0;
    for (i = 0; i < 3; i++) if (guess[i] == real[i]) count++;
    return count;
}
 
int calc_ball(char *guess, char *real) {
    int i, count = 0;
    for (i = 0; i < 3; i++) if (guess[i] == real[(i + 1) % 3] || guess[i] == real[(i + 2) % 3]) count++;
    return count;
}
 
int main(void) {
    int N, count=0, check;
    int i, j, k, l;
    char cand[4];
 
    scanf("%d", &N);
    for (i = 0; i < N; i++) scanf(" %s %d %d", guess[i], &strike[i], &ball[i]);
    if (strike[0] == 3) {
        printf("1");
        return 0;
    }
    for (i = '1'; i <= '9'; i++) {
        for (j = '1'; j <= '9'; j++) {
            if (j == i) continue;
            for (k = '1'; k <= '9'; k++) {
                if (k == i || k == j) continue;
                cand[0] = i;
                cand[1] = j;
                cand[2] = k;
                for (l = 0, check = 1; l < N; l++) {
                    if (strike[l] != calc_strike(guess[l], cand) || ball[l] != calc_ball(guess[l], cand)) {
                        check = 0;
                        break;
                    }
                }
                if (check == 1) count++;
            }
        }
    }
    printf("%d", count);    return 0;
}

