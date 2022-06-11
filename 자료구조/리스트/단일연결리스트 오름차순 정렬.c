#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node {
	int elem;
	struct node* next;
}Node;

typedef struct LIST {
	Node* header;
}LIST;

void init(LIST* list) {
	list->header = (Node*)malloc(sizeof(Node));
	list->header->next = NULL;
	list->header->elem = 0;
}

int size(LIST* list) {
	Node* p;
	int n = 0;
	p = list->header->next;
	while (p != NULL) {
		n++;
		p = p->next;
	}
	return n;
}

void ascend(LIST* list) {
	Node* p;
	int i, j, tmp, n = size(list);
	for (i = 0; i < n - 1; i++) {
		p = list->header->next;
		for (j = 0; j < n - 1 - i; j++) {
			if (p->elem > p->next->elem) {
				tmp = p->elem;
				p->elem = p->next->elem;
				p->next->elem = tmp;
			}
			p = p->next;
		}
	}
}

void append(LIST* list, int e) {
	int n = size(list);
	Node* p;
	Node* q = (Node*)malloc(sizeof(Node));
	q->elem = e;
	p = list->header;
	for (int i = 1; i <= n; i++)
		p = p->next;
	q->next = p->next;
	p->next = q;
}

void print(LIST* list) {
	int n = size(list);
	Node* p;
	p = list->header->next;
	printf(" %d", p->elem);
	p = p->next;
	for (int i = 0; i < n-1; i++) {
		printf(" %d", p->elem);
		p = p->next;
	}
	printf("\n");
}

int main(void) {
	int n, i, e;
	LIST* L = (LIST*)malloc(sizeof(LIST));
	init(L);
	scanf_s("%d", &n);
	getchar();
	for (i = 0; i < n; i++) {
		scanf_s("%d", &e);
		getchar();
		append(L, e);
	}
	ascend(L);
	print(L);
	return 0;
}
