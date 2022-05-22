#include <stdio.h>

int factorial(int n) {
  if (n>1)
    return n * factorial(n-1);
  else
    return 1;
}
int main(void) {
  int n, i;
  double result=1.0;
  scanf("%d", &n);
  for(i=1; i<=n; i++) {
    result += 1.0/factorial(i);
  }
  printf("%0.6f", result);
  return 0;
}
