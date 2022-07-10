#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning (disable:4996)
int N;
int top;

void initStack(char stack[]) {
	top = -1;
}

void push(char stack[], char ch) {
	if (top >= N - 1)
		printf("Stack FULL\n");
	else stack[++top] = ch;
}

char pop(char stack[]) {
	if (top < 0) {
		printf("Stack Empty\n");
	}
	else return stack[top--];
}

void peek(char stack[]) {
	if (top < 0)
		printf("Stack Empty\n");
	else
		printf("%c", stack[top]);
}

void duplicate(char stack[]) {
	if (top >= N-1)
		printf("Stack FULL\n");
	else {
		push(stack, pop(stack));
		push(stack, stack[top]);
	}
}

void upRotate(char stack[], int n) {
	char tmp;
	if (n > top + 1) return;
	else {
		tmp = stack[top];
		for (int i = top - 1; i > top - n; i--)
			stack[i + 1] = stack[i];
		stack[top - n + 1] = tmp;
	}
}

void downRotate(char stack[], int n) {
	char tmp;
	if (n > top + 1) return;
	else {
		tmp = stack[top-n+1];
		for (int i = top-n+1; i <= top - 1; i++)
			stack[i] = stack[i+1];
		stack[top] = tmp;
	}
}

void print(char stack[]) {
	for (int i= top; i >=0; i--)
		printf("%c", stack[i]);
	printf("\n");
}

int main(void) {
	int cnt, m;
	char* stack;
	char ch[10], e;
	scanf("%d", &N);
	stack = (char*)malloc(N * sizeof(char));
	initStack(stack);
	scanf("%d", &cnt);
	getchar();
	for (int i = 0; i < cnt; i++) {
		scanf("%s", ch);
		getchar();
		if (strcmp(ch, "POP") == 0) pop(stack);
		else if (strcmp(ch, "PUSH") == 0) {
			scanf("%c", &e);
			getchar();
			push(stack, e);
		}
		else if (strcmp(ch, "PRINT") == 0) print(stack);
		else if (strcmp(ch, "UpR") == 0) {
			scanf("%d", &m);
			getchar();
			upRotate(stack, m);
		}
		else if (strcmp(ch, "DownR") == 0) {
			scanf("%d", &m);
			getchar();
			downRotate(stack, m);
		}
		else if (strcmp(ch, "PEEK") == 0) peek(stack);
		else if (strcmp(ch, "DUP") == 0) duplicate(stack);
	}
	free(stack);
	return 0;
}
