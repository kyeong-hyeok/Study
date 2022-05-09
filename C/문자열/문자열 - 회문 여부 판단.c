#include <stdio.h>
#include <string.h>

int check(char *x) {
  int i, leng, result=1;
  leng = strlen(x);
  for(i=0; i<leng/2; i++) {
    if(x[i] != x[leng-i-1]) {
      result=0;
      break;
      }
  }
  return result;
}
int main(void) {
  int l;
  char a[30];
  scanf("%s", a);
  l = strlen(a);
  printf("%d %d", l, check(a));
  return 0;
}
