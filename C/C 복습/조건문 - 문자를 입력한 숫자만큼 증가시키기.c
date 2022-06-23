#include<stdio.h>
#pragma warning (disable:4996)

int main(void) {
	int num;	// 숫자 num
	char ch;	// 문자 ch
	scanf("%c %d", &ch, &num);	// 문자와 숫자 입력받기
	if (ch >= 'a' && ch <= 'z') 	// 소문자일 때
		ch = 'a' + (ch - 'a' + num) % 26; // 'a'로부터 ch가 떨어진 값에 num을 더해 26('a'에서 'z'까지의 길이)으로 나눈 나머지를, 'a'에 더해 ch에 저장
	else if (ch >= 'A' && ch <= 'Z') 	// 대문자일 때
		ch = 'A' + (ch - 'A' + num) % 26;	// 'A'로부터 ch가 떨어진 값에 num을 더해 26('A'에서 'Z'까지의 길이)으로 나눈 나머지를, 'A'에 더해 ch에 저장
	printf("%c", ch);	// 입력한 숫자만큼 증가시킨 문자 출력
	return 0;
}
