#include <stdio.h>

int main(void) {
  int N, i, cnt, j;
  scanf("%d", &N);
  for(i=1; i<=N; i++) {
    j=i;
    while(1) {
      if(j/10==0) {
        if(j==3)
          cnt++;
        break;
      }
      else {
        if(j%10==3)
          cnt++;
        j = j/10;
      }
    }
  }
  printf("%d", cnt);
  return 0;
}
