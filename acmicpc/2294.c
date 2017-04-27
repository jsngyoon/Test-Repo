#include <stdio.h>
#define MAX_N 100
#define MAX_K 10000

int coin[MAX_N + 1];
int cache[MAX_K + 1];

int N, K;
/*
int min_coin(int k) {
	int i, d, min=10000;
	if (k == 0) return 0;
	if (cache[k] != -1) return cache[k];
	
	for (i = 0; i < N; i++) {
		if (k - coin[i] >= 0) {
			d = min_coin(k - coin[i]);
			if (d < min) min = d;
		}
	}
	cache[k] = min + 1;
	return cache[k];
}
*/
int min_coin(int money) {
	int i, k, d, min;

	for (k = 1; k <= money; k++) {
		min = 20000;
		for (i = 0; i < N; i++) {
			if (k - coin[i] >= 0) {
				d = cache[k - coin[i]]+1;
				if (d < min) min = d;
			}
		}
		cache[k] = min;
	}
	return cache[money];
}

int main(void) {
	int i, min;

	scanf("%d%d", &N, &K);
	for (i = 0; i < N; i++) scanf("%d", &coin[i]);
	for (i = 0; i <= K; i++) cache[i] = 0;

	min = min_coin(K);
	if (min == 20000) printf("-1");
	else printf("%d", min);

	return 0;
}
