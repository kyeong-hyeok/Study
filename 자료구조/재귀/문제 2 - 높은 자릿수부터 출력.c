#include<stdio.h>

void digits(int n) {
	if (n < 10) {
		printf("%d\n", n);
		return 0;
	}
	else {
		digits(n / 10);
		printf("%d\n", n % 10);
	}
}

int main(void) {
	int n;
	scanf("%d", &n);
	digits(n);
	return 0;
}
