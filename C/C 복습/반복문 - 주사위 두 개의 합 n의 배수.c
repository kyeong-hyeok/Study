#include<stdio.h>

int main(){
	int n, sum=0, i, j;
	scanf("%d", &n);
	for (i = 1; i <= 6; i++) {
		for (j = 1; j <= 6; j++) {
			if ((i + j) % n == 0)
				printf("%d %d\n", i, j);
		}
	}
	return 0;
}
