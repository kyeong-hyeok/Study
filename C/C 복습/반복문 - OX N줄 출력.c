#include <stdio.h>

int main(void) {
  int N, i, j, k;
  scanf("%d", &N);
  for(i=1; i<=N; i++) {
    for(j=1; j<=N; j++) {
      printf(" ");
      if(j==i || j==N-i+1)
        printf("X");
      else
        printf("O");
      }
    printf("\n");
    }
  return 0;

}
