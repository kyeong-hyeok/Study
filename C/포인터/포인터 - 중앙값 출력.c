#include <stdio.h>

int main(void) {
  int x[3];
  int *p, *k, tmp;
  for(p=x; p<x+3; p++)
    scanf("%d", p);
  for(p=x; p<x+3; p++) {
    for(k=x; k<x+2; k++) {
      if(*k>*(k+1)) {
        tmp = *k;
        *k = *(k+1);
        *(k+1) = tmp;
      }
    }
  }
  printf("%d", *(x+1));
  return 0;
}
