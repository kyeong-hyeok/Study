#include <stdio.h>

int main(void) {
  int num, hun, r;
  scanf("%d", &num);
  hun = (num%1000) / 100;
  hun>=5 ? (r=num-num%1000+1000) : (r=num-num%1000);
  printf("%d", r);
  return 0;
}
