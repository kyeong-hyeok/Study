#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
	int elem;
	struct node* prev;
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
	p->prev = NULL;
	return p;
}
void add_rear(Que* q, int e) {
	Node* p = getnode();
	p->elem = e;
	if (isEmpty(q)) {
		q->f = p;
		q->r = p;
	}
	else {
		p->prev = q->r;
		q->r->next = p;
		q->r = p;
	}
	return;
}
void add_front(Que* q, int e) {
	Node* p = getnode();
	p->elem = e;
	if (isEmpty(q)) {
		q->f = p;
		q->r = p;
	}
	else {
		p->next = q->f;
		q->f->prev = p;
		q->f = p;
	}
	return;
}

void emptyQueueException() {
	printf("underflow");
}

void putnode(Node* p) {
	free(p);
	p->elem = NULL;
}
int delete_front(Que* q) {
	if (isEmpty(q)) {
		emptyQueueException();
		return -1;
	}
	int e = q->f->elem;
	Node* p = q->f;
	q->f = q->f->next;
	if (q->f == NULL)
		q->r = NULL;
	else
		q->f->prev = NULL;
	putnode(p);
	return e;
}

int delete_rear(Que* q) {
	if (isEmpty(q)) {
		emptyQueueException();
		return -1;
	}
	int e = q->r->elem;
	Node* p = q->r;
	q->r = q->r->prev;
	if (q->r == NULL)
		q->f = NULL;
	else
		q->r->next = NULL;
	putnode(p);
	return e;
}

void print(Que* q) {
	Node* p = q->f;
	while (p != NULL) {
		printf(" %d", p->elem);
		p = p->next;
	}
	printf("\n");
}

int main() {
	int n, e, end=0;
	Que q;
	char ch1, ch2;
	initQueue(&q);
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		scanf("%c", &ch1);
		if (ch1 == 'A') {
			scanf("%c", &ch2);
			getchar();
			scanf("%d", &e);
			if (ch2 == 'F')
				add_front(&q, e);
			else if (ch2 == 'R')
				add_rear(&q, e);
		}
		if (ch1 == 'D') {
			scanf("%c", &ch2);
			if (isEmpty(&q)) end = 1;
			if (ch2 == 'F')
				delete_front(&q);
			else if (ch2 == 'R')
				delete_rear(&q);
		}
		if (ch1 == 'P') print(&q);
		if (end) break;
		getchar();
	}
	return 0;
}
