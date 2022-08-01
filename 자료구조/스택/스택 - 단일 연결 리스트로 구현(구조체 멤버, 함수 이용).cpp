#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable:4996)

typedef struct node {
	int elem;
	struct node* next;
}Node;

struct Stack {
	Node* top;

	void init() {
		top = NULL;
	}

	void push(int e) {
		Node* p = (Node*)malloc(sizeof(Node));
		p->elem = e;
		p->next = top;
		top = p;
	}

	int isEmpty() {
		return (top == NULL);
	}

	void emptyStackException() {
		printf("StackException \n");
	}

	int pop() {
		if (isEmpty())
			emptyStackException();
		int e = top->elem;
		Node* p = (Node*)malloc(sizeof(Node));
		p = top;
		top = top->next;
		free(p);
		return e;
	}

	void traverse() {
		Node* p = (Node*)malloc(sizeof(Node));
		p = top;
		while (p != NULL) {
			printf("%d ", p->elem);
			p = p->next;
		}
		printf("\n");
	}
};

int main(void) {
	Stack S;
	S.init();
	S.push(1);
	S.push(2);
	S.push(3);
	S.pop();
	S.traverse();
	return 0;
}
