#include <stdio.h>

int main(void) {
  int a, b, c, min, max;
  scanf("%d %d %d", &a, &b, &c);
  if(a<b) {
    min=a;
    max=b;
    if(c<a)
      min=c;
    else if(c>b)
      max=c;
  }
  else {
    min=b;
    max=a;
    if(c<b)
      min=c;
    else if(c>a)
      max=c;
  }
  printf("%d %d", max, min);
  return 0;
}  

