#include <stdio.h>

int main(void) {
  int ar[50]={0}, N, cnt=0;
  int *p;
  scanf("%d", &N);
  for (p=ar; p<ar+N; p++)  //반복문으로 배열 훑어보기
    scanf("%d", p);
  for (p=ar; p<ar+N; p++) {
    if(*p==0) break;
    else cnt++;
  }
  printf("%d", cnt);
  return 0;
}
