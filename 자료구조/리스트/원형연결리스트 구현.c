#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node {
	char elem;
	struct node* next;
}Node;

typedef struct LIST {
	Node* head;
	Node* trail;
}LIST;

void init(LIST* list) {
	list->head = (Node*)malloc(sizeof(Node));
	list->trail = (Node*)malloc(sizeof(Node));
	list->head->next = list->trail;
	list->trail->next = list->head;
}

int size(LIST* list) {
	Node* p;
	int n = -1;
	p = list->head->next;
	while (p != list->head) {
		n++;
		p = p->next;
	}
	return n;
}

void get(LIST* list, int r) {
	Node* p;
	if ((r < 0) || (r > size(list))) {
		printf("invalid position\n");
		return 0;
	}
	p = list->head;
	for (int i = 1; i <= r; i++)
		p = p->next;
	printf("%c\n", p->elem);
}

char set(LIST* list, int r, char e) {
	Node* p;
	if ((r < 0) || (r > size(list))) {
		printf("invalid position\n");
		return 0;
	}
	p = list->head;
	for (int i = 1; i <= r; i++)
		p = p->next;
	p->elem = e;
	return e;
}

void add(LIST* list, int r, char e) {
	int n, i;
	Node* p;
	Node* q = (Node*)malloc(sizeof(Node));
	q->elem = e;
	n = size(list);
	if ((r < 0) || (r > size(list)+1)) {
		printf("invalid position\n");
		return 0;
	}
	p = list->head;
	for (int i = 1; i <= r-1; i++)
		p = p->next;
	q->next = p->next;
	p->next = q;
}

char remov(LIST* list , int r) {
	int n = size(list), i;
	char e;
	Node* p;
	Node* q = (Node*)malloc(sizeof(Node));
	if (n == 0)
		printf("empty list\n");
	if ((r < 0) || (r > n)) {
		printf("invalid position\n");
		return 0;
	}
	p = list->head;
	for (int i = 1; i <= r - 1; i++)
		p = p->next;
	q = p->next;
	e = q->elem;
	p->next = q->next;
	free(q);
	return e;
}

void print(LIST* list) {
	Node* p;
	p = list->head->next;
	while (p != list->trail) {
		printf("%c", p->elem);
		p = p->next;
	}
	printf("\n");
}

int main(void) {
	int n, i, r;
	char k, e;
	LIST* list = (LIST*)malloc(sizeof(LIST));
	init(list);
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++) {
		scanf("%c", &k);
		getchar();
		if (k == 'A') {
			scanf("%d %c", &r, &e);
			getchar();
			add(list, r, e);
		}
		else if (k == 'R') {
			scanf("%d", &r);
			getchar();
			remov(list, r);
		}
		else if (k == 'G') {
			scanf("%d", &r);
			getchar();
			get(list, r);
		}
		else if (k == 'P') {
			print(list);
		}
		else if (k == 'S') {
			scanf("%d %c", &r, &e);
			getchar();
			set(list, r, e);
		}
	}
	return 0;
}
