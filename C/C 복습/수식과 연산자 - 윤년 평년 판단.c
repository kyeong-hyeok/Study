#include<stdio.h>
#pragma warning (disable:4996)

int main(void) {
	int y;
	scanf("%d", &y);
	if (y % 400 == 0) printf("L");
	else if (y % 100 != 0 && y % 4 == 0) printf("L");
	else printf("C");
	return 0;
}
