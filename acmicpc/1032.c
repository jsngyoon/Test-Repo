#include <stdio.h>
#define MAX_DIM 50

char name[MAX_DIM + 1][MAX_DIM + 1];
int N;

int main(void) {
	int i, j, len=0;
	char result[MAX_DIM + 1];

	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%s", name[i]);
	while (name[0][len]!='\0') {
		result[len] = name[0][len];
		len++;
	}
	result[len] = '\0';

	for (j = 0; j < len; j++)
		for (i = 1; i < N; i++) {
			if (name[i][j] != name[i - 1][j]) result[j] = '?';
		}
	printf("%s", result);
	return 0;
}

