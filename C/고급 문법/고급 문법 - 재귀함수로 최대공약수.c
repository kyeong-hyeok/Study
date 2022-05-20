#include <stdio.h>

int gcd(int x, int y) {
  if(x>y) {
    return gcd(x-y,y);
  }
  else if(y>x) {
    return gcd(x,y-x);
  }
  else 
    return x; 
}
int main(void) {
  int a, b;
  scanf("%d %d", &a, &b);
  printf("%d", gcd(a,b));
  return 0;
}
