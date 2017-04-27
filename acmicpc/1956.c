#include <stdio.h>
#define MAX_V 400
#define MAX_D 10000
#define MIN(a,b) (((a) > (b)) ? (b) : (a))

int V, E;
int city[MAX_V + 1][MAX_V + 1];
int floyd[MAX_V + 1][MAX_V + 1];

int main(void) {
	int i;
	int from, to, dist;
	int u, v;

	scanf("%d%d", &V, &E);
	for (u = 1; u <= V; u++)
		for (v = 1; v <= V; v++) city[u][v] = MAX_D + 1;
	for (i = 0; i < E; i++) {
		scanf("%d%d%d", &from, &to, &dist);
		city[from][to] = MIN(city[from][to], dist);
	}
	for (u = 1; u <= V; u++)
		for (v = 1; v <= V; v++) floyd[u][v] = city[u][v];

	for (i = 1; i <= V; i++)
		for (u = 1; u <= V; u++)
			for (v = 1; v <= V; v++) {
				if (floyd[u][v] > floyd[u][i] + floyd[i][v])
					floyd[u][v] = floyd[u][i] + floyd[i][v];
			}
	dist = MAX_D+1;
	for (i = 1; i <= V; i++) dist = MIN(dist, floyd[i][i]);

	if (dist == MAX_D + 1) printf("-1");
	else printf("%d", dist);

	return 0;
}
