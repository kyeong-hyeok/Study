#include<stdio.h>

int main(){
	int n, i, j, k, sum=0;
	scanf("%d", &n);
	for (i = 1; i <= 6; i++) {
		if (n-i <= 12 && n-i >= 2) {
			for (j = 1; j <= 6; j++) {
				if (n - (i+j) <= 6 && n - (i + j) >= 1){
					printf("%d", i);
					printf(" %d", j);
					printf(" %d\n", n - i-j);
				}
			}
		}
	}
	return 0;
}
