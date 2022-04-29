#include <stdio.h>

int main(void) {
  int a[5]={4,5,6,7,8}, b[5]={1,3,5,7,9}, c[5]={0,2,4,6,8}, *p[3];
  p[0] = a;
  p[1] = b;
  p[2] = c;
  printf("%p %d\n", &p[0], *p[0]);
  printf("%p %d\n", &p[1], *p[1]);
  printf("%p %d\n", &p, *p[2]);
  return 0;
}
