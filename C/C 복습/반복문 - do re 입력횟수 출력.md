## 문제

do re가 몇 번 입력되는지 계산하여라. '.'이 입력되면 종료한다.

-----

## 풀이

문자열을 사용하지 않고 입력을 받아야 하는 상황에서 문자 두 개를 scanf로 같이 입력받으려 했었다.
 
하지만 그 방법보다 문자 하나를 입력받아 다른 변수에 저장하고 다시 문자를 입력 받아 두 변수에 저장된 문자를 비교하여 문제를 해결하는 것이 더 간단했다.

바로 앞과 뒤의 문자로 비교하므로, 공백이 입력되는 것을 고려하지 않아도 문제를 해결할 수 있었다.
```C
#include<stdio.h>
#pragma warning (disable:4996)

int main(void) {
	int docnt = 0, recnt = 0;
	char a, b=1;
	while (1) {
		scanf("%c", &a);
		if (a == '.') break;
		if (b == 'd' && a == 'o') docnt++;
		if (b == 'r' && a == 'e') recnt++;
		b = a;
	}
	printf("do=%d\n", docnt);
	printf("re=%d", recnt);
	return 0;
}
```
