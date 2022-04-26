#include <stdio.h>

int main(void) {
  int n, a, cnt=0;
  scanf("%d", &n);
  do {
    scanf("%d", &a);
    if (n<a)
      printf("%d>?\n", a);
    else if (n>a)
      printf("%d<?\n", a);
    else
      printf("%d==?\n", a);
    cnt++;
  } while(n!=a);
  printf("%d\n", cnt);
  return 0;
}
