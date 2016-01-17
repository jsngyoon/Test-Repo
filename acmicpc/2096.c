#include <stdio.h>
#define MAX_DIM 100000
#define MIN(a,b) (((a) > (b)) ? (b) : (a))
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
//int list[MAX_DIM + 1][3];
//int cache[MAX_DIM + 1][3];
int N;
int now[3];
int min[3];
int min_new[3];
int max[3];
int max_new[3];

int main(void) {
	int i, j;
	int max_ans, min_ans;

	scanf("%d", &N);
	
	for (j = 0; j < 3; j++) {
		min[j] = 0;
		max[j] = 0;
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < 3; j++) {
			scanf("%d", &now[j]);
		}
		min_new[0] = now[0] + MIN(min[0], min[1]);
		min_new[1] = now[1] + MIN(MIN(min[0], min[1]), min[2]);
		min_new[2] = now[2] + MIN(min[1],min[2]);
		min[0] = min_new[0];
		min[1] = min_new[1];
		min[2] = min_new[2];

		max_new[0] = now[0] + MAX(max[0], max[1]);
		max_new[1] = now[1] + MAX(MAX(max[0], max[1]), max[2]);
		max_new[2] = now[2] + MAX(max[1], max[2]);
		max[0] = max_new[0];
		max[1] = max_new[1];
		max[2] = max_new[2];
	}
	max_ans = MAX(MAX(max[0], max[1]), max[2]);
	min_ans = MIN(MIN(min[0], min[1]), min[2]);

	printf("%d %d", max_ans, min_ans);
	return 0;
}

