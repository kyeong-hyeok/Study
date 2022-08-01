#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

struct Que {
	int f;
	int r;
	int* Q;
};

void initQueue(Que* q, int N) {
	q->Q = (int*)malloc(sizeof(int) * N);
	q->f = 1;
	q->r = 0;
	for (int i = 0; i < N; i++)
		q->Q[i] = 0;
	return;
}

int isEmpty(Que* q, int N) {
	return (q->r + 1) % N == q->f;
}

int isFull(Que* q, int N) {
	return (q->r + 2) % N == q->f;
}

void fullQueueException() {
	printf("overflow");
}

void enqueue(Que* q, int N, int e) {
	if (isFull(q, N)) {
		fullQueueException();
		return;
	}
	q->r = (q->r + 1) % N;
	q->Q[q->r] = e;
	return;
}

void emptyQueueException() {
	printf("underflow");
}

int dequeue(Que* q, int N) {
	if (isEmpty(q, N)) {
		emptyQueueException();
		return -1;
	}
	int e = q->Q[q->f];
	q->Q[q->f] = 0;
	q->f = (q->f + 1) % N;
	return e;
}

void traverse(Que* q, int N) {
	for (int i = 0; i < N; i++)
		printf(" %d", q->Q[i]);
	printf("\n");
}

int main() {
	Que Q;
	int n, q, e;
	char ch;
	scanf("%d", &q);
	scanf("%d", &n);
	getchar();
	initQueue(&Q, q);
	for (int i = 0; i < n; i++) {
		scanf("%c", &ch);
		getchar();
		if (ch == 'I') {
			scanf("%d", &e);
			getchar();
			if (isFull(&Q, q)) {
				enqueue(&Q, q, e);
				traverse(&Q, q);
				break;
			}
			enqueue(&Q, q, e);
		}
		else if (ch == 'D') {
			if (isEmpty(&Q, q)) {
				dequeue(&Q, q);
				break;
			}
			dequeue(&Q, q);
		}
		else if (ch == 'P')
			traverse(&Q, q);
	}
	return 0;
}
