#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning (disable:4996)
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

int isalpha(char s) {
	if (s >= 'A' && s <= 'Z') return 1;
	return 0;
}

int getPrior(char s) {
	char Prior[10] = { '(','|','&','<','>','+','-','*','/','!'};
	int Prior_N[10] = { 0,1,2,3,3,4,4,5,5,6};
	for (int i = 0; i < 10; i++) {
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
	if (s == '&' || s == '|')
		printf("%c", s);
	printf("%c", s);
}

void convert(char* infix_array, int N) {
	Stack S;
	initStack(&S);
	int idx = 0;
	while (idx != N) {
		char s = infix_array[idx++];
		if (isalpha(s))
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
	int n, idx, d=0;
	char c, infix_array[100];
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		idx = 0;
		while (1) {
			scanf("%c", &c);
			if (c == '\n')  break;
			if (c == '&' && infix_array[idx - 1] == '&')
				continue;
			else if (c == '|' && infix_array[idx - 1] == '|')
				continue;
			infix_array[idx++] = c;
		}
		convert(infix_array, idx);
		printf("\n");
	}
}
