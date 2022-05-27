#include<stdio.h>
#include<string.h>

int main() {
	int i, l, j;
	char p[100], tmp;
	scanf("%s", p);
	l = strlen(p);
	for (i = 0; i < l; i++) {
		printf("%s\n", p);
		tmp = p[0];
		for (j = 0; j < l - 1; j++)
			p[j] = p[j+1];
		p[l-1] = tmp;
	}
	return 0;
}
