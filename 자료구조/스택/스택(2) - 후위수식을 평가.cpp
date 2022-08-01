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

void write(char s) {
	printf("%d ", s - '0');
}

int doOperator(char op, int x, int y) {
	int v;
	switch (op) {
	case '+': v = x + y; break;
	case '-': v = x - y; break;
	case 'x': v = x * y; break;
	case '/': v = x / y; break;
	}
	return v;
}

void evaluate(char* postfix_array) {
	Stack S;
	initStack(&S);
	int N = strlen(postfix_array);
	int idx = 0;
	while (idx != N) {
		char s = postfix_array[idx++];
		if (isOperand(s))
			push(&S, s);
		else {
			int a = pop(&S) - '0';
			int b = pop(&S) - '0';
			push(&S, doOperator(s, b, a) + '0');
		}
		//traverse(&S);
	}
	write(pop(&S));
	return;
}

int main() {
	char postfix_array[100] = "41-2-423x+5/+";
	evaluate(postfix_array);
	printf("\n");
}
