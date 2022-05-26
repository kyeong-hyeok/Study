#include<stdio.h>

int sum(int n) {
	int i, result=0;
	for (i = 1; i <= n; i++)
		result += i;
	return result;
}

int main(void) {
	int i, x, s = 0;
	scanf_s("%d", &x);
	for (i = 1; i <= x; i++)
		s += sum(i);
	printf("%d", s);
}
