#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning (disable:4996)
// RCV 연구실에서 Runtime Error 뜨는 원인 찾고 해결 필요
int top;
int n=0;

void initStack(char stack[]) {
	top = -1;
}

void push(char stack[], char ch) {
	if (top >= 999) return;
	n++;
	stack[++top] = ch;
}

char pop(char stack[]) {
	if (top < 0) 
		printf("empty");
	return stack[top--];
}

int test_pair(char stack[], char ch) {
	int pair = 0;
	char e;
	if (top >= 0) {
		e = pop(stack);
		if (e == '{') {
			if (ch == '}') pair = 1;
		}
		else if (e == '(') {
			if (ch == ')') pair = 1;
		}
		else if (e == '[') {
			if (ch == ']') pair = 1;
		}
		else pair = 0;
	}
	return pair;
}

int main(void) {
	char *stack, ch;
	int inx = 0, pair=1;
	stack = (char*)malloc(1000 * sizeof(char));
	initStack(stack);
	while (1) {
		scanf("%c", &ch);
		if (ch == '\n') break;
		if (ch == '{' || ch == '[' || ch == '(')
			push(stack, ch);
		else if (ch == '}' || ch == ']' || ch == ')') {
			n++;
			if (test_pair(stack, ch) == 0)
				pair = 0;
		}
	}
	if (top >= 0) pair = 0;
	if(pair)
		printf("OK_%d", n);
	else
	 printf("Wrong_%d", n);
	free(stack);
	return 0;
}
