#include<stdio.h>

int main(){ // n의 각 자리수를 더한다.->한 자리 수가 될 때까지 반복한다.
	int n, sum=0;
	scanf("%d", &n);
	while (n>=10) {
		sum = 0;
		while (n != 0) {
			sum += n % 10;
			n /= 10;
		}
		n = sum;
	}
	printf("%d", n);
	return 0;
}
