#include<stdio.h>
#pragma warning (disable:4996)

int main(void) {
	int k, e, m;
	double avg;
	scanf("%d %d %d", &k, &e, &m);
	avg = (k + e + m) / 3.0;
	printf("%.2f\n", avg);
	avg /= 25;
	switch ((int)avg) {
	case 4: case 3:
		printf("A");
		break;
	case 2:
		printf("B");
		break;
	default:
		printf("F");
		break;
	}
	return 0;
}
