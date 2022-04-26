#include <stdio.h>

int main(void) {
  int N, M, i, j, fac;
  scanf("%d %d", &M, &N);
  for(i=M; i<=N; i++) {
    printf("%d!=1", i);
    fac=1;
    for(j=2; j<=i; j++) {
      fac *= j;
      printf("*%d", j);
    }
    printf("=%d\n", fac);
  }  
  return 0;
}
