#include <stdio.h>

int main(void) {
  int x[3];
  int *p, tmp;
  for(p=x; p<x+3; p++)
    scanf("%d", p);
  for(p=x; p<x+2; p++) {
    if(*p>*(p+1)) {
      tmp = *p;
      *p = *(p+1);
      *(p+1) = tmp;
    }
  }
  printf("%d", *(x+1));
  return 0;
}
