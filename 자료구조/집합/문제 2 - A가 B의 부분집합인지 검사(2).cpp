#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable:4996)

typedef struct node {
	int elem;
	struct node* next;
}Node;

struct Set {
	int n, N;
	Node* F;

	void init() {
		F = (Node*)malloc(sizeof(Node));
		F->next = NULL;
		n = 0;
		N = 100;
	}


	bool member(int e) {
		Node* p = F;
		if (n == 0) return false;
		while (1) {
			int a = p->elem;
			if (a < e) {
				if (p->next == NULL)
					return false;
				else
					p = p->next;
			}
			else if (a > e) return false;
			else return true;
		}
	}

	int subset(Set B) {
		Node* p = F;
		if (n == 0) return 0;
		while (1) {
			if (B.member(p->elem)) {
				if (p->next == NULL)
					return 0;
				else
					p = p->next;
			}
			else return p->elem;
		}
	}

	void addlast(int e) {
		Node* p = F;
		Node* q = (Node*)malloc(sizeof(Node));
		while (p->next != NULL)
			p = p->next;
		q->elem = e;
		q->next = NULL;
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
