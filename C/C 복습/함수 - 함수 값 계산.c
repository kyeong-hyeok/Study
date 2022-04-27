#include <stdio.h>

int func2(int x, int a, int b, int c);

int main(void) {
  int N, x, i, a, b, c;
  scanf("%d", &x);
  scanf("%d %d %d", &a, &b, &c);
  printf("%d", func2(x,a,b,c));
  return 0;
}

int func2(int x, int a, int b, int c) {
    return a*x*x+b*x+c;
}
