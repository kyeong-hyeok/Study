#include <stdio.h>

int main(void) {
  int N, i, j, k;
  scanf("%d", &N);
  i=0;
  while(i<N) {
    k=i+1;
    for(j=1; j<=N; j++) {
      printf(" ");
      if (k>9)
        k=0;
      printf("%d", k);
      k++;
    }
    printf("\n");
    i++;
  }

  return 0;

}
