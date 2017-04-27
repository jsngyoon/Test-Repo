#include <stdio.h>
#define MAX_DIM 45

int cache[MAX_DIM + 1];
int N;

int f(int n) {
	if (n <= 1) return n;
	if (cache[n]) return cache[n];

	cache[n] = f(n - 1) + f(n - 2);
	return cache[n];
}

int main(void) {
	scanf("%d", &N);
	printf("%d", f(N));
	return 0;
}
