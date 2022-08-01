#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable:4996)

typedef struct node {
	int elem;
	struct node* prev;
	struct node* next;
}Node;

struct Set {
	int n, N;
	Node* header;
	Node* trailer;

	void init() {
		header = (Node*)malloc(sizeof(Node));
		trailer = (Node*)malloc(sizeof(Node));
		header->next = trailer;
		trailer->prev = header;
		header->prev = NULL;
		trailer->next = NULL;
		n = 0;
		N = 100;
	}


	bool member(int e) {
		Node* p = header->next;
		if (n == 0) return false;
		while (1) {
			int a = p->elem;
			if (a < e) {
				if ((p->next)->next == NULL)
					return false;
				else
					p = p->next;
			}
			else if (a > e) return false;
			else return true;
		}
	}

	int subset(Set B) {
		Node* p = header->next;
		if (n == 0) return 0;
		while (1) {
			if (B.member(p->elem)) {
				if ((p->next)->next == NULL)
					return 0;
				else
					p = p->next;
			}
			else return p->elem;
		}
	}

	void addlast(int e) {
		Node* p = header;
		Node* q = (Node*)malloc(sizeof(Node));
		while (p->next != trailer)
			p = p->next;
		q->elem = e;
		q->prev = p;
		q->next = trailer;
		trailer->prev = q;
		p->next = q;
		n++;
	}

};
int main(void) {
	Set A, B;
	int i, na, nb, e;
	A.init();
	B.init();
	scanf("%d", &na);
	getchar();
	for (i = 0; i < na; i++) {
		scanf("%d", &e);
		getchar();
		A.addlast(e);
	}
	scanf("%d", &nb);
	getchar();
	for (i = 0; i < nb; i++) {
		scanf("%d", &e);
		getchar();
		B.addlast(e);
	}
	printf("%d", A.subset(B));
	return 0;
}
