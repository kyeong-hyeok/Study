#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
	char elem;
	struct node* next;
}Node;

typedef struct stack {
	Node* top;
}Stack;

void initStack(Stack* s) {
	s->top = NULL;
	return;
}

Node* getNode() {
	Node* p = (Node*)malloc(sizeof(Node));
	p->elem = -1;
	p->next = NULL;
	return p;
}

void push(Stack* s, char e) {
	Node* p = getNode();
	p->elem = e;
	p->next = s->top;
	s->top = p;
	return;
}

int isEmpty(Stack* s) {
	return (s->top == NULL);
}

void emptyStackException() {
	printf("StackException\n");
}

void putnode(Node* p) {
	free(p);
	p = NULL;
}

char pop(Stack* s) {
	if (isEmpty(s)) {
		emptyStackException();
		return -1;
	}
	char e = s->top->elem;
	Node* p = s->top;
	s->top = s->top->next;
	putnode(p);
	return e;
}

void traverse(Stack* s) {
	Node* p = (Node*)malloc(sizeof(Node));
	p = s->top;
	while (p != NULL) {
		printf("%d ", p->elem - '0');
		p = p->next;
	}
	printf("\n");
}

int isOperand(char s) {
	char array[10] = { '0','1','2','3','4','5','6','7','8','9' };
	for (int i = 0; i < 10; i++) {
		if (s == array[i])
			return 1;
	}
	return 0;
}

int getPrior(char s) {
	char Prior[5] = { '(','+','-','x','/' };
	int Prior_N[5] = { 0,1,1,2,2 };
	for (int i = 0; i < 5; i++) {
		if (s == Prior[i])
			return Prior_N[i];
	}
}

char top(Stack* s) {
	if (s->top == NULL) {
		emptyStackException();
		return -1;
	}
	return s->top->elem;
}

void write(char s) {
	printf("%c ", s);
}

void convert(char* infix_array) {
	Stack S;
	initStack(&S);
	int N = strlen(infix_array);
	int idx = 0;
	while (idx != N) {
		char s = infix_array[idx++];
		if (isOperand(s))
			write(s);
		else if (s == '(')
			push(&S, s);
		else if (s == ')') {
			while (top(&S) != '(')
				write(pop(&S));
			pop(&S);
		}
		else {
			while (!isEmpty(&S) && (getPrior(s) <= getPrior(top(&S))))
				write(pop(&S));
			push(&S, s);
		}
	}
	while (!isEmpty(&S))
		write(pop(&S));
	return;
}

int main() {
	char infix_array[100] = "a-b-c+(d+exf)/g";
	convert(infix_array);
	printf("\n");
}
