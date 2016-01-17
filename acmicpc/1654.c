#include <stdio.h>
#define MAX_K 10000

int K, N;
int lan[MAX_K + 1];

int check_lan(int length) {
	int i, sum=0;
	for (i = 0; i < K; i++) {
		sum += lan[i] / length;
	}
	if (sum >= N) return 1;
	return 0;
}

int main(void) {
	int i, low=1, upper, mid, max=0;
	int answer;

	scanf("%d %d", &K, &N);
	for (i = 0; i < K; i++) {
		scanf("%d", &lan[i]);
		if (lan[i] > max) max = lan[i];
	}
	upper = max;
	while (low <= upper) {
		mid = (low + upper) / 2;
		if (check_lan(mid)) {
			answer = mid;
			low = mid + 1;
		}
		else upper = mid - 1;
	}
	printf("%d", answer);

	return 0;
}
