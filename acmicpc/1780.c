#include <stdio.h>

#define MAX_DIM 2200
int N;
int paper[MAX_DIM][MAX_DIM];
int neg, zero, pos;

int all_neg(int sx, int sy, int ex, int ey) {
	int i, j;
	for (i = sx; i <= ex; i++) {
		for (j = sy; j <= ey; j++) {
			if (paper[i][j] != -1) return 0;
		}
	}
	return 1;
}

int all_zero(int sx, int sy, int ex, int ey) {
	int i, j;
	for (i = sx; i <= ex; i++) {
		for (j = sy; j <= ey; j++) {
			if (paper[i][j] != 0) return 0;
		}
	}
	return 1;
}

int all_pos(int sx, int sy, int ex, int ey) {
	int i, j;
	for (i = sx; i <= ex; i++) {
		for (j = sy; j <= ey; j++) {
			if (paper[i][j] != 1) return 0;
		}
	}
	return 1;
}

void check_paper(int sx, int sy, int ex, int ey) {
	int delta;
	int i, j;

	if (all_neg(sx, sy, ex, ey) == 1) {
		neg++;
		return;
	}
	if (all_zero(sx, sy, ex, ey) == 1) {
		zero++;
		return;
	}
	if (all_pos(sx, sy, ex, ey) == 1) {
		pos++;
		return;
	}
	delta = (ex-sx+1)/3;
	for (i = sx; i <= ex; i += delta) {
		for (j = sy; j <= ey; j += delta) {
			check_paper(i, j, i + delta - 1, j + delta - 1);
		}
	}
}

int main(void) {
	int i, j;

	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			scanf("%d", &paper[i][j]);
		}
	}
	check_paper(1, 1, N, N);
	printf("%d\n%d\n%d", neg, zero, pos);
	return 0;
}

