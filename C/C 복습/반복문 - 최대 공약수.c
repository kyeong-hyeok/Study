#include <stdio.h>

int main(void) {
  int N, M, i, result;
  scanf("%d %d", &N, &M);
  for(i=0; i<=N && i<=M; i++) {
    if (N%i==0 && M%i==0)
      result = i;
  }  
  printf("%d", result);
  return 0;
}
