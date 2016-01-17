#include <stdio.h>

int N, count;

void hanoi(int disk_num, int from, int to, int mid) {
	if (disk_num == 1) {
		printf("%d %d\n", from, to);
		return;
	}
	hanoi(disk_num - 1, from, mid, to);
	hanoi(1, from, to, mid);
	hanoi(disk_num - 1, mid, to, from);
}

void hanoi_count(int disk_num, int from, int to, int mid) {
	if (disk_num == 1) {
		count++;
		return;
	}
	hanoi_count(disk_num - 1, from, mid, to);
	hanoi_count(1, from, to, mid);
	hanoi_count(disk_num - 1, mid, to, from);
}

int main(void) {
	int i;

	scanf("%d", &N);
	hanoi_count(N, 1, 3, 2);
	printf("%d\n", count);
	hanoi(N, 1, 3, 2);

	return 0;

}
