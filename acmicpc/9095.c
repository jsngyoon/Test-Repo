#include <stdio.h>

int T, n;
int count;

void find_comb(int num) {
	if (num < 0) return;
	if (num == 0) {
		count++;
		return;
	}
	find_comb(num - 1);
	find_comb(num - 2);
	find_comb(num - 3);
}

int main(void) {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		count = 0;
		find_comb(n);
		printf("%d\n", count);
	}
	return 0;
}
