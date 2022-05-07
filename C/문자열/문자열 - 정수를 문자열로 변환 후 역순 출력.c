#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
  int n, i=0;
  char p[10];
  scanf("%d", &n);
  while(n!=0) {
    p[i] = n%10 + 48;
    n /= 10;
    i++;
  }
  p[i+1]='\0';
  printf("%s\n", p);
  return 0;

}
