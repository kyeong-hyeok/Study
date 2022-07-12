#include<stdio.h>
#pragma warning (disable:4996)

void change(char* ch);

int main(void) {
	char a[100];
	int i, cnt = 0;
	for (i = 0; ; i++) {
		scanf("%c", &a[i]);
		if (a[i] == '*')
			cnt++;
		if (cnt == 2) break;
	}
	change(a);
	for (i = 0; ; i++) {
		if (a[i] == '*')
			break;
		printf("%c", a[i]);
	}
	return 0;
}

void change(char* ch) {
	int i, j, inx1 = -1, inx2 = -1, p, last, k;
	for (i = 0; ; i++) {
		if (*(ch + i) == '*' && inx1 != -1) {
			inx2 = i;
			break;
		}
		if (*(ch + i) == '*' && inx1 == -1)
			inx1 = i;
	}
	for (i = 0; i <= inx1 - (inx2 - inx1 - 1); i++) {
		p = 1;
		k = 0;
		for (j = inx1 + 1; j < inx2; j++) {
			if (*(ch + i+k) != *(ch + j))
				p = 0;
			k++;
		}
		if (p) last = i;
	}
	for (i = last; i < last + inx2 - inx1 - 1; i++)
		*(ch + i) -= 32;
}
