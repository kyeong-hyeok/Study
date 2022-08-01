#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

typedef struct node {
	int elem;
	struct node* next;
}Node;

struct Que {
	Node* f;
	Node* r;
};

void initQueue(Que* q) {
	q->f = NULL;
	q->r = NULL;
}

int isEmpty(Que* q) {
	return (q->f == NULL);
}

Node* getnode() {
	Node* p = (Node*)malloc(sizeof(Node));
	p->elem = -1;
	p->next = NULL;
	return p;
}
void enqueue(Que* q, int e) {
	Node* p = getnode();
	p->elem = e;
	p->next = NULL;
	if (isEmpty(q)) {
		q->f = p;
		q->r = p;
	}
	else {
		q->r->next = p;
		q->r = p;
	}
}

void emptyQueueException() {
	printf("EmptyQueueException \n");
}

void putnode(Node* p) {
	free(p);
	p = NULL;
}

int dequeue(Que* q) {
	if (isEmpty(q)) {
		emptyQueueException();
		return -1;
	}
	int e = q->f->elem;
	Node* p = q->f;
	q->f = q->f->next;
	if (q->f == NULL)
		q->r = NULL;
	putnode(p);
	return e;
}

void traverse(Que* q) {
	Node* p = q->f;
	while (p != NULL) {
		printf(" %d", p->elem);
		p = p->next;
	}
	printf("\n");
}

int main() {
	Que q;
	initQueue(&q);
	enqueue(&q, 10);
	enqueue(&q, 20);
	traverse(&q);
	enqueue(&q, 30);
	enqueue(&q, 40);
	dequeue(&q);
	traverse(&q);
	enqueue(&q, 50);
	enqueue(&q, 60);
	enqueue(&q, 70);
	traverse(&q);
}
