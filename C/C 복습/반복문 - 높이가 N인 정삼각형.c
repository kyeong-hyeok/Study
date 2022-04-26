#include <stdio.h>

int main(void) {
  int N, i, j, k;
  scanf("%d", &N);
  for(i=1; i<=N; i++) {
    for(k=1; k<=Nㅂ-i; k++)
      printf(" ");
    for(j=1; j<2*i; j++)
      printf("*");
    for(k=1; k<=N-i; k++)
      printf(" ");
    printf("\n");
  }
  return 0;
