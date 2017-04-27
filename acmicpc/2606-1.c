#include <stdio.h>
#define MAX_DIM 100

int com[MAX_DIM + 1][MAX_DIM + 1];
int floyd[MAX_DIM + 1][MAX_DIM + 1];
int N, E;

int main(void) {
	int i;
	int u, v;

	scanf("%d%d", &N, &E);
	for (i = 0; i < E; i++) {
		scanf("%d %d", &u, &v);
		com[u][v] = 1;
		com[v][u] = 1;
	}


	for (u = 1; u <= N; u++)
		for (v = 1; v <= N; v++) floyd[u][v] = com[u][v];

	for (i = 1; i <= N; i++)
		for (u = 1; u <= N; u++)
			for (v = 1; v <= N; v++) {
				if (floyd[u][i] && floyd[i][v])
					floyd[u][v] = 1;
			}

	int count = 0;
	for (i = 2; i <= N; i++) if (floyd[1][i]) count++;

	printf("%d", count);

	return 0;
}


