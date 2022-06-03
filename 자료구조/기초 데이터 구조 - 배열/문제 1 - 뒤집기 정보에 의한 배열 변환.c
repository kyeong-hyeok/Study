#include<stdio.h>
#include<stdlib.h>

void reverse(int *x, int a, int b) {
	int i, tmp;
	for (i = 0; i < ((b - a +1)/ 2); i++) {
		tmp = x[a+i];
		x[a+i] = x[b-i];
		x[b-i] = tmp;
	}
}

int main(void) {
	int n, i, r, a, b, *x=NULL;
	scanf("%d", &n);
	x = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
		scanf("%d", &x[i]);
	scanf("%d", &r);
	while (getchar() != '\n');
	for (i = 0; i < r; i++) {
		scanf("%d", &a);
		scanf("%d", &b);
		reverse(x, a, b);
	}
	for (i = 0; i < n; i++)
		printf(" %d", x[i]);
	return 0;
}
