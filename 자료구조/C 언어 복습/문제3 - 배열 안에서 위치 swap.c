#include<stdio.h>

void swap(int* a, int* b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main() {
	int i, n, arr[50], a, b;
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
		scanf_s("%d", &arr[i]);
	scanf_s("%d %d", &a, &b);
	swap(&arr[a], &arr[b]);
	for (i = 0; i < n; i++)
		printf(" %d", arr[i]);
	return 0;
}
