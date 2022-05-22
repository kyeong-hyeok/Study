#include <stdio.h>

int factorial(int n) {
  if (n>1)
    return n * factorial(n-1);
  else
    return 1;
}
double facsum(int n) {
  if(n>=1)
    return facsum(n-1) + 1.0/factorial(n);
  else
    return 1.0;
}
int main(void) {
  int n;
  scanf("%d", &n);
  printf("%0.6f", facsum(n));
  return 0;
}
