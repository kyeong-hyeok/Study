#include<stdio.h>
#pragma warning (disable:4996)

void sort(int* ar, int* p);
void merge(int* ar1, int* ar2, int* ar3, int* p, int* q);

int main(void) {
	int ar1[100], ar2[100], ar3[100], N, M, *p;
	scanf("%d", &N);
	for (p = ar1; p < ar1 + N; p++)
		scanf("%d", p);
	scanf("%d", &M);
	for (p = ar2; p < ar2 + M; p++)
		scanf("%d", p);
	sort(ar1, &N);
	sort(ar2, &M);
	merge(ar1, ar2, ar3, &N, &M);
	for (p = ar3; p < ar3 + N+M; p++)
		printf(" %d", *p);
	return 0;
}

void sort(int* ar, int* p) {
	int* a, * b, tmp;
	for (a = ar; a < ar + *p-1; a++) {
		for (b = ar; b < ar + *p-1; b++) {
			if (*b > *(b + 1)) {
				tmp = *b;
				*b = *(b + 1);
				*(b + 1) = tmp;
			}
		}
	}
}

void merge(int* ar1, int* ar2, int* ar3, int* p, int* q) {
	int c1 = 0, c2 = 0, c3 = 0, * a;
	while (1) {
		if (*(ar1 + c1) < *(ar2 + c2)) {
			*(ar3 + c3) = *(ar1 + c1);
			c1++;
		}
		else {
			*(ar3 + c3) = *(ar2 + c2);
			c2++;
		}
		c3++;
		if (c1 == *p) {
			for (a = ar2 + c2; a < ar2 + *q; a++) {
				*(ar3 + c3) = *a;
				c3++;
			}
			break;
		}
		else if (c2 == *q) {
			for (a = ar1 + c1; a < ar1 + *p; a++) {
				*(ar3 + c3) = *a;
				c3++;
			}
			break;
		}
	}
}
