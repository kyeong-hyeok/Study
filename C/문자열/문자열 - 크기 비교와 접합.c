#include <stdio.h>
#include <string.h>

int main(void) {
  char a[100], b[100];
  int c;
  scanf("%s", a);
  scanf("%s", b);
  c=strcmp(a,b);
  if(c>0) printf("%s", strcat(a,b));
  if(c<0) printf("%s", strcat(b,a));
  return 0;
}
