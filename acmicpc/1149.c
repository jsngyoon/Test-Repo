#include <stdio.h>
#define MAX_DIM 1000
#define MIN(a,b) ((a) < (b) ? (a) : (b))

int cost[MAX_DIM + 1][3];
int cache[MAX_DIM + 1][3];
int N;

int calc_min(int house, int color) {
	int i, c, min=1000000000;
	
	if (house == N - 1) return cost[house][color];
	if (cache[house][color] != -1) return cache[house][color];

	for (i = 0; i < 3; i++) {
		if (i == color) continue;
		c = calc_min(house + 1, i);
		if (c < min) min = c;
	}
	cache[house][color] = min+cost[house][color];
	return cache[house][color];

}

int main(void) {
	int i, j;
	int cost_min;

	scanf("%d", &N);
	for (i = 0; i < N; i++)
		for (j = 0; j < 3; j++) {
			scanf("%d", &cost[i][j]);
			cache[i][j] = -1;
		}
	cost_min = MIN(MIN(calc_min(0,0), calc_min(0,1)),calc_min(0,2));
	printf("%d", cost_min);

	return 0;

}
