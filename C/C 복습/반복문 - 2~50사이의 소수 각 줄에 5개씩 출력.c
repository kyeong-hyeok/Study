#include<stdio.h>

int main(){
	int n = 2, i, j, line=0;
	while (n <= 50) {
		j = 1;
		for (i = 2; i <= n - 1; i++) {
			if (n % i == 0) {
				j = 0;
				break;
			}
		}
		if (j == 1) {
			printf(" %d", n);
			line++;
		}
		if (line == 5) {
			printf("\n");
			line = 0;
		}
		n++;
	}
	return 0;
}
