#include <stdio.h>

int N;

void plot_star(int n, int row, int col){
	if (n == 1) {
		printf("*");
		return;
	}
	n /= 3;
	if (row/n == 1 && col/n == 1) printf(" ");
	else plot_star(n, row%n, col%n);
}

int main(void) {
	int i, j;
	scanf("%d", &N);
	for (i = 0; i < N; i++ ) {
		for (j = 0; j < N; j++) plot_star(N,i,j);
		printf("\n");
	}


	return 0;
}
