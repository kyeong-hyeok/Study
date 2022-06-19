#include<stdio.h>
#pragma warning (disable:4996)

int main(void) {
	int y;
	char w;
	scanf("%d", &y);
	w = (y % 100 != 0 && y % 4 == 0) || (y % 400 == 0) ? 'L' : 'C';
	printf("%c", w);
	return 0;
}
