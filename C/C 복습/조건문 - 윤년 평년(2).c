#include<stdio.h>
#pragma warning (disable:4996)

int main(void) {
	int n;
	scanf("%d", &n);
	if (n % 4 == 0) {
		if (n % 100 == 0) {
			if (n % 400 == 0) printf("leap year");
			else printf("common year");
		}
		else printf("leap year");
	}
	else printf("common year");
	return 0;
}
