#include<stdio.h>
#include<stdlib.h>

void move(int *x, int f, int t) {
	int i, tmp;
	tmp = x[f];
  x[f] = x[t];
  x[t] = tmp;
}

int main(void) {
	int n, i, r, f, t, *x=NULL;
	scanf("%d", &n);
	x = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
		scanf("%d", &x[i]);
	scanf("%d", &r);
	while (getchar() != '\n');
  scanf("%d", &f);
	scanf("%d", &t);
  move(x, f, t);
	for (i = 2; i < r; i++) {
		scanf("%d", &t);
		move(x, f, t);
	}
	for (i = 0; i < n; i++)
		printf(" %d", x[i]);
	return 0;
}
