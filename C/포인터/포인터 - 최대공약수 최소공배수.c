#include <stdio.h>

void gcdlcm(int x, int y, int *a, int *b);
int main(void) {
  int n, m, o, p;
  scanf("%d %d", &n, &m);
  gcdlcm(n,m, &o, &p);
  printf("%d %d", o, p);
  return 0;
}

void gcdlcm(int x, int y, int *a, int *b) {
  int i;
  for(i=1; i<=x && i<= y; i++) {
    if(x%i==0 && y%i==0)
      *a = i;
  }
  *b = (x*y)/(*a);
}
