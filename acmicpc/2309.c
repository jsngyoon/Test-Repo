#include <stdio.h>
#define MAX_DIM 9

int height[MAX_DIM + 1];

int main(void) {
	int i, j, temp=0;

	for (i = 0; i < 9; i++) {
		scanf("%d", &height[i]);
		temp += height[i];
	}
	
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			if (i == j) continue;
			if (temp - height[i] - height[j] == 100) {
				height[i] = 101;
				height[j] = 101;
				break;
			}
		}
		if (height[i] == 101) break;
	}

	for (i = 0; i < 9; i++)
		for (j = i + 1; j < 9; j++) {
			if (height[i] > height[j]) {
				temp = height[i];
				height[i] = height[j];
				height[j] = temp;
			}
		}
	for (i = 0; i < 7; i++) printf("%d\n", height[i]);

	return 0;
}
