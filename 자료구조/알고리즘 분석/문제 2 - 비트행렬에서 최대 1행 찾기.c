#include<stdio.h>
#include<stdlib.h>

int mostOnes(int **A, int n) {
	int max = 0, i=0, j=0;
	while (A[0][j] != 0) {
		j++;
	}
	while ((i<n) && (j<n)) {
		if (A[i][j] == 1) {
			j++;
			max = i;
		}
		else
			i++;
	}
	return max;
}

int main(void) {
	int n, i, j, **p;
	scanf("%d", &n);
	p = (int**)malloc(n * sizeof(int*));
	for(i=0; i<n; i++)
		p[i] = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			scanf("%d", &p[i][j]);
	}
	printf("%d\n", mostOnes(p, n));
	for (i = 0; i < n; i++)
		free(p[i]);
	free(p);
	return 0;
}
