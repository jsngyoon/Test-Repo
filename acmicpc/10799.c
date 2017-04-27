#include <stdio.h>
#define MAX_DIM 100000

char code[MAX_DIM + 1];

int is_laser(int i) {
	if (code[i + 1] == ')') return 1;
	else return 0;
}

int main(void) {
	int i=0;
	int rod_num=0;
	int total=0;

	scanf("%s", code);

	while (code[i] != '\0') {
		if (code[i] == '(') {
			if (is_laser(i)) {
				total += rod_num;
				i += 2;
			}
			else {
				rod_num++;
				i++;
			}
		}
		else {
			total++;
			rod_num--;
			i++;
		}
	}
	printf("%d", total);

	return 0;
}
