#include <stdio.h>

int mid(int *x);
int main(void) {
  int x[3];
  int *p;
  for(p=x; p<x+3; p++)
    scanf("%d", p);
  printf("%d", mid(x));
  return 0;
}

int mid(int *x) {
  int *p, *k, tmp;
  for(p=x; p<x+3; p++) {
    for(k=x; k<x+2; k++) {
      if(*k>*(k+1)) {
        tmp = *k;
        *k = *(k+1);
        *(k+1) = tmp;
      }
    }
  }
  return *(x+1);
}
