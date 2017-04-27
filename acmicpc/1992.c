#include <stdio.h>
#define MAX_DIM 64
char disp[MAX_DIM + 1][MAX_DIM + 1];
int N;

int check_area(int row1, int col1, int row2, int col2, char ch) {
	int i, j;

	for (i = row1; i <= row2; i++)
		for (j = col1; j <= col2; j++) if (disp[i][j] != ch) return 0;

	return 1;
}
void quadtree(int row1, int col1, int row2, int col2) {
	int delta;
	
	if (check_area(row1, col1, row2, col2, '0') == 1) {
		printf("0");
		return;
	}
	if (check_area(row1, col1, row2, col2, '1') == 1) {
		printf("1");
		return;
	}
	delta = (row2 - row1 + 1) / 2;
	if (delta == 0) return;
	printf("(");
	quadtree(row1, col1, row1+delta-1, col1+delta-1);
	quadtree(row1, col1+delta, row1+delta-1, col2);
	quadtree(row1+delta, col1, row2, col1+delta-1);
	quadtree(row1+delta, col1+delta, row2, col2);
	printf(")");

}

int main(void) {
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf(" %s", disp[i]);
	quadtree(0, 0, N - 1, N - 1);
	return 0;
}
