#include <stdio.h>

int add_to_k(int *x, int *y);

int main(void) {
  int a[100], *ar, n, total=0;
  scanf("%d", &n);
  for(ar=a; ar<a+n; ar++) {
    scanf("%d", ar);
  }
  for(ar=a; ar<a+n; ar++) { // 반복 호출하여 수식의 값 구하기(d[0] + (d[0]+d[1]) + ,,, + (d[0]+d[1]+,,,d[N-1]))
    total += add_to_k(a,ar);
  }
  printf("%d", total);
  return 0;
}

int add_to_k(int *x, int *y) {
  int sum=0, *p;
  for(p=x; p<y+1; p++)  // 첫 번째 포인터 ~ 두 번째 포인터까지 원소의 합
    sum += *p;
  return sum;
}
