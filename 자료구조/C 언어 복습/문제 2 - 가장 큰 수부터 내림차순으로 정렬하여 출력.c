#include<stdio.h>

void ABC(int a[], int k) {
	int i, max = a[k], inx = k, tmp;
	for (i = k+1; i < 10; i++) {
		if (a[i] > max) {
			max = a[i];
			inx = i;
		}
	}
	tmp = a[k];
	a[k] = max;
	a[inx] = tmp;
}

int main(void) {
	int i, a[10], k=0;
	for (i = 0; i < 10; i++)
		scanf("%d", &a[i]);
	for (i = 0; i < 9; i++) {
		ABC(a, k);
		k++;
	}
	for (i = 0; i < 10; i++)
		printf(" %d", a[i]);
	return 0;
}
