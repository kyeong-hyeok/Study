#include <stdio.h>

int main(void) {
  char c;
  int a;
  scanf("%c", &c);
  (c>=65 && c<=90) || (c>=97 && c<=122) ? (a=1) : (a=0);
  printf("%d", a);
  return 0;
}
