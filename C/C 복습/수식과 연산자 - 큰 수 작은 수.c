#include <stdio.h>

int main(void) {
  int N, M, q, l;
  scanf("%d %d", &N, &M);
  N>M ? (q=N/M, l=N%M) : (q=M/N, l=M%N);
  printf("%d\n", q);
  printf("%d", l);
  return 0;
}
