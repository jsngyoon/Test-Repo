#include <stdio.h>
#define MAXE 15
#define MAXS 28
#define MAXM 19

int E, S, M;

int main(void) {
	int count=0;
	int e=1, s=1, m=1;

	scanf("%d%d%d", &E, &S, &M);
	while (1) {
		count++;
		if (e == E && s == S && m == M) break;
		e = (e == MAXE) ? 1 : e + 1;
		s = (s == MAXS) ? 1 : s + 1;
		m = (m == MAXM) ? 1 : m + 1;
	}
	printf("%d", count);
	return 0;
