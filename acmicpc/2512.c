#include <stdio.h>
#define MAX_N 10000

int N, M;
int budget[MAX_N + 1]; // <= 100,000
int sum[MAX_N + 1];

int check_budget(int cut) {
	int i, sum=0;

	for (i = 0; i < N; i++) {
		if (budget[i] > cut) sum += cut;
		else sum += budget[i];
	}
	if (sum <= M) return 1;
	return 0;

}
int main(void) {
	int i;
	int low=0, upper, mid;
	int answer;

	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", &budget[i]);
	scanf("%d", &M);
	if (check_budget(M)) {
		for (i = 0, answer = 0; i < N; i++) if (budget[i] > answer) answer = budget[i];
	}
	else {
		upper = M;
		while (low <= upper) {
			mid = (upper + low) / 2;
			if (check_budget(mid)) {
				answer = mid;
				low = mid + 1;
			}
			else upper = mid - 1;
		}
	}
	printf("%d", answer);
	return 0;
}
/*
int main(void) {
	int i, j;
	int temp;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &budget[i]);
		for (j = i; j > 0; j--) {
			if (budget[j] < budget[j - 1]) {
				temp = budget[j - 1];
				budget[j - 1] = budget[j];
				budget[j] = temp;
			}
			else break;
		}
	}
	for (i = 0; i < N; i++) {
		if (i == 0) sum[i] = budget[i];
		else sum[i] = sum[i - 1] + budget[i];
	}
	scanf("%d", &M);
	for (i = N - 1; i >= 0; i--) {

	}
}
*/

