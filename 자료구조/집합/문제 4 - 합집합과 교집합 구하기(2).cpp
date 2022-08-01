#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable:4996)

typedef struct node {
	int elem;
	struct node* next;
}Node;

struct Set {
	int n, N;
	Node* header;

	void init() {
		header = (Node*)malloc(sizeof(Node));
		header->next = NULL;
		n = 0;
		N = 100;
	}


	bool member(int e) {
		Node* p = header->next;
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
		Node* p = header->next;
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
		Node* p = header;
		Node* q = (Node*)malloc(sizeof(Node));
		while (p->next != NULL)
			p = p->next;
		q->elem = e;;
		q->next = NULL;
		p->next = q;
		n++;
	}
	
	int isEmpty() {
		if (n == 0) return 1;
		else return 0;
	}

	int get(int r) {
		Node* p = header;
		for (int i = 1; i <= r; i++)
			p = p->next;
		return p->elem;
	}

	int removeFirst() {
		Node* p = header->next;
		int e = p->elem;
		header->next = p->next;
		n--;
		return e;
	}
		
	void print() {
		Node* p = header;
		if (n == 0) printf(" %d", 0);
		else {
			for (int i = 1; i <= n; i++) {
				p = p->next;
				printf(" %d", p->elem);
			}
		}
		printf("\n");
	}
};

Set my_union(Set A, Set B) {
	Set C;
	C.init();
	while (!A.isEmpty() && !B.isEmpty()) {
		int a = A.get(1);
		int b = B.get(1);
		if (a < b) {
			C.addlast(a);
			A.removeFirst();
		}
		else if (a > b) {
			C.addlast(b);
			B.removeFirst();
		}
		else {
			C.addlast(a);
			A.removeFirst();
			B.removeFirst();
		}
	}
	while (!A.isEmpty()) {
		C.addlast(A.get(1));
		A.removeFirst();
	}
	while (!B.isEmpty()) {
		C.addlast(B.get(1));
		B.removeFirst();
	}
	return C;
}

Set my_intersect(Set A, Set B) {
	Set C;
	C.init();
	while (!A.isEmpty() && !B.isEmpty()) {
		int a = A.get(1);
		int b = B.get(1);
		if (a < b)
			A.removeFirst();
		else if (a > b)
			B.removeFirst();
		else {
			C.addlast(a);
			A.removeFirst();
			B.removeFirst();
		}
	}
	while (!A.isEmpty())
		A.removeFirst();
	while (!B.isEmpty())
		B.removeFirst();
	return C;
}

int main(void) {
	Set A, B, C, D, X, Y;
	int i, na, nb, e;
	A.init();
	B.init();
	C.init();
	D.init();
	X.init();
	Y.init();
	scanf("%d", &na);
	getchar();
	for (i = 0; i < na; i++) {
		scanf("%d", &e);
		getchar();
		A.addlast(e);
		X.addlast(e);
	}
	scanf("%d", &nb);
	getchar();
	for (i = 0; i < nb; i++) {
		scanf("%d", &e);
		getchar();
		B.addlast(e);
		Y.addlast(e);
	}
	C = my_union(A, B);
	C.print();
	D = my_intersect(X, Y);
	D.print();
	return 0;
}
