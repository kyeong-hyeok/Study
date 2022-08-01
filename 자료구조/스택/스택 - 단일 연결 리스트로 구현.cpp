#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int elem;
	struct node* next;
}Node;

typedef struct stack {
	Node* top;
}Stack;

void init(Stack* s) {
	s->top = NULL;
}

void push(Stack* s, int e) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->elem = e;
	p->next = s->top;
	s->top = p;
}

int isEmpty(Stack* s) {
	return (s->top == NULL);
}

void emptyStackException() {
	printf("StackException \n");
}

int pop(Stack* s) {
	if (isEmpty(s))
		emptyStackException();
	int e = s->top->elem;
	Node* p = (Node*)malloc(sizeof(Node));
	p = s->top;
	s->top = s->top->next;
	free(p);
	return e;
}

void traverse(Stack* s) {
	Node* p = (Node*)malloc(sizeof(Node));
	p = s->top;
	while (p != NULL) {
		printf("%d ", p->elem);
		p = p->next;
	}
	printf("\n");
}

int main(void) {
	Stack S;
	init(&S);
	push(&S, 1);
	push(&S, 2);
	push(&S, 3);
	pop(&S);
	traverse(&S);
	return 0;
}
