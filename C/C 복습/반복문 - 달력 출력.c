#include<stdio.h>

int main(){   // 0~6 사이의 정수를 입력 받아, 그 정수에 해당하는 요일에 1일이 시작하는 달력 출력하기
	int i,n, d=1, j=0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		printf("   ");
		j++;
	}
	while (d <= 31) {
		if (j == 7) {
			printf("\n");
			j = 0;
		}
		printf("%3d", d);
		j++;
		d++;
	}
	return 0;
}
