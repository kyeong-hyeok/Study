#include <stdio.h>

int main(void) {
    double num;
    printf("실수 입력 : ");
    scanf("%lf", &num);
    printf("반올림 정수 출력 : %d", (int)(num+0.5));
  return 0;
}
