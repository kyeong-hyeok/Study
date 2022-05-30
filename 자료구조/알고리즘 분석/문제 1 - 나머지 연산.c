#include<stdio.h>

int modulo(int a, int b) {
	while (a - b >= 0) {
		a = a - b;
	}
	return a;
}

int main(void) {
	int a, b;
	scanf_s("%d %d", &a, &b);
	printf("%d", modulo(a, b));
	return 0;
}
