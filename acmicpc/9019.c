#include <stdio.h>
#define MAX_Q 10000000
#define MAX_DIM 10000

typedef struct {
	int num;
	int from;
	char cmd;
} Node;
Node myq[MAX_Q];
int head, tail;
int visited[MAX_DIM + 1];
char path[MAX_DIM + 1];

void q_init() {
	int i;
	head = 0;
	tail = 0;
	for (i = 0; i <= MAX_DIM; i++) visited[i] = 0;
}

int q_size() {
	return tail - head;
}

int q_isempty() {
	return q_size() == 0;
}

void push(Node v) {
	if (visited[v.num]) return;
	visited[v.num] = 1;
	myq[tail].num = v.num;
	myq[tail].from = v.from;
	myq[tail].cmd = v.cmd;
	tail++;
}

Node pop() {
	return myq[head++];
}

int T, A, B;

void i2s(int i, char *s) {
	int j;
	for (j = 3; j >=0 ; j--) {
		s[j] = i % 10 + '0';
		i /= 10;
	}
}

int s2i(char *s) {
	int j, n=0;
	for (j = 0; j < 4; j++) {
		n = n * 10 + s[j] - '0';
	}
	return n;
}

int OP_L(int i) {
	char s[5], ch;
	int j;

	i2s(i, s);
	ch = s[0];
	for (j = 0; j < 3; j++) s[j] = s[j + 1];
	s[3] = ch;
	return s2i(s);
}

int OP_R(int i) {
	char s[5], ch;
	int j;

	i2s(i, s);
	ch = s[3];
	for (j = 2; j >=0; j--) s[j+1] = s[j];
	s[0] = ch;
	return s2i(s);
}

int main(void) {
	int i, found, from;
	Node v, next;
	int qsize, step;

	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &A, &B);
		q_init();
		v.num = A;
		v.from = 0;
		push(v);
		found = 0;
		step = 0;
		while (!found && !q_isempty()) {
			qsize = q_size();
			step++;
			for (i = 0; i < qsize; i++) {
				v = pop();
				if (v.num == B) {
					found = 1;
					break;
				}
				next.from = head - 1;
				next.num = (v.num * 2) % 10000; //D
				next.cmd = 'D';
				push(next);
				next.num = v.num == 0 ? 9999 : v.num - 1; //S
				next.cmd = 'S';
				push(next);
				next.num = OP_L(v.num); //L
				next.cmd = 'L';
				push(next);
				next.num = OP_R(v.num); //R
				next.cmd = 'R';
				push(next);
			}
		}
		if (found == 1) {
			path[step-1] = myq[head - 1].cmd;
			from = myq[head - 1].from;
			for (i = step-2; i > 0; i--) {
				path[i] = myq[from].cmd;
				from = myq[from].from;
			}
			for (i = 1; i <= step-1; i++) printf("%c", path[i]);
			printf("\n");
		}
	}
	return 0;
}
