#include <stdio.h>

int add(int x, int y);

int main(void) {
  int N, i, sum=0;
  scanf("%d", &N);
  for(i=1; i<=N; i++) {
    sum = add(sum, i);
  };
  printf("%d", sum);
  return 0;
}

int add(int x, int y) {
  return x+y;
}
