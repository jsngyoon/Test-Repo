#include <stdio.h>
#define MAX_DIM 1000

int main(void) {
	int T, N;
	int i=1, j=1, k=1;
	int si, sj, sk, found;

	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		found = 0;
		for (i = 1; i < 1000; i++) {
			si = i*(i + 1) / 2;
			if (found ==1 || si >= N) break;
			for (j = 1; j < 1000; j++) {
				sj = j*(j + 1) / 2;
				if (found == 1 || si + sj >= N) break;
				for (k = 1; k < 1000; k++) {
					sk = k*(k + 1) / 2;
					if (si + sj + sk > N) break;
					if (si + sj + sk == N) {
						found = 1;
						break;
					}
				}
			}
		}
		if (found == 1) printf("1\n");
		else printf("0\n");
	}
	return 0;
}
