#include<stdio.h>

int maxint(int a[], int n) {
	if (n == 1) {
		return a[0];
	}
	else {
		if (a[n - 1] > maxint(a, n - 1))
			return a[n - 1];
		else
			return maxint(a, n - 1);
	}
}

int main(void) {
	int n, i, p[20];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &p[i]);
	printf("%d\n", maxint(p, n));
	return 0;
}
