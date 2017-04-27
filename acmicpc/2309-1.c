#include <stdio.h>
#define MAX_DIM 9

int height[MAX_DIM + 1];
int visited[MAX_DIM + 1];
int answer[MAX_DIM + 1];
int found;

void dfs(int sum) {
	int i, count;

	if (found) return;
	if (sum == 100) {
		for (i = 0, count=0; i < 9; i++) {
			if (visited[i] == 1) answer[count++] = height[i];
		}
        if (count ==7) found = 1;
		return;
	}

	for (i = 0; i < 9; i++)  {
		if (!visited[i] && sum + height[i] <= 100) {
			visited[i] = 1;
			dfs(sum + height[i]);
			visited[i] = 0;
		}
	}

}
int main(void) {
	int i, j, temp;

	found = 0;
	for (i = 0; i < 9; i++) scanf("%d", &height[i]);
	dfs(0);
	for (i = 0; i < 7; i++)
		for (j = i + 1; j < 7; j++) {
			if (answer[i] > answer[j]) {
				temp = answer[i];
				answer[i] = answer[j];
				answer[j] = temp;
			}
		}
	for (i = 0; i < 7; i++) printf("%d\n", answer[i]);

	return 0;
}
