#include <stdio.h>

int main(void) {
  double pi, r, N, S;
  pi = 3.14;
  scanf("%lf", &N);  # 원의 둘레의 길이 받기
  r = N / (2 * pi);
  S = pi * r*r;
  printf("%d", (int)(S+0.5));  # 소수 첫째 자리에서 반올림
  return 0;
}
