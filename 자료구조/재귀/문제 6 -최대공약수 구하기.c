#include <stdio.h>

int gcd(int a, int b) {
  if(a>b) {
    a = a%b;
    if(a==0)
      return b;
    }
  else {
    b = b%a;
    if (b==0)
      return a;
    }
  gcd(a,b);
}

int main(void) {
  int a, b;
  scanf("%d %d", &a, &b);
  printf("%d", gcd(a,b));
  return 0;
}
