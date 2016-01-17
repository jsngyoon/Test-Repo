#include <stdio.h>
#define MAX_DIM 100

int N, E;
int matrix[MAX_DIM + 1][MAX_DIM + 1];
int visited[MAX_DIM];
int count;

void dfs(int u) {
	int i;

	if (visited[u]) return;

	visited[u] = 1;
	count++;
	for (i = 1; i <= N; i++) {
		if (i == u) continue;
		if (matrix[u][i] == 1) dfs(i);
	}

}

int main(void) {
	int i, u, v;
	scanf("%d%d", &N, &E);
	for (i = 0; i < E; i++) {
		scanf("%d%d", &u, &v);
		matrix[u][v] = 1;
		matrix[v][u] = 1;
	}
	dfs(1);
	printf("%d\n", count-1);

	return 0;
}

