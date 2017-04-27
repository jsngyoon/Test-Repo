#include <stdio.h>
#define MAX_DIM 100
#define MAX_COST 100000
#define MIN(a,b) ((a) > (b) ? (b) : (a))

int city[MAX_DIM + 1][MAX_DIM + 1];
int floyd[MAX_DIM + 1][MAX_DIM + 1];

int N, M; //City수, Bus수

int main(void) {
	int i;
	int from, to, cost;
	int u, v;

	scanf("%d%d", &N, &M);
	for (u = 1; u <= N; u++)
		for (v = 1; v <= N; v++) city[u][v] = MAX_COST+1;

	for (i = 0; i < M; i++) {
		scanf("%d%d%d", &from, &to, &cost);
		city[from][to] = MIN(city[from][to], cost);
	}

	for (u = 1; u <= N; u++)
		for (v = 1; v <= N; v++) floyd[u][v] = city[u][v];

	for (i = 1; i <= N; i++)
		for (u = 1; u <= N; u++)
			for (v = 1; v <= N; v++) {
				if (floyd[u][v] > floyd[u][i] + floyd[i][v])
					floyd[u][v] = floyd[u][i] + floyd[i][v];
			}

	for (u = 1; u <= N; u++) {
		for (v = 1; v <= N; v++) {
			if (u == v || floyd[u][v] > MAX_COST) printf("0 ");
			else printf("%d ", floyd[u][v]);
		}
		printf("\n");
	}

	return 0;
}
