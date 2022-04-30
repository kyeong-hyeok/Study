#include <stdio.h>

int main(void) {
  char ch[20], *p = ch;
  int i=0, j;
  scanf("%s", p);
  while(*(p+i)!='#') {
    i++;
  }
  for(j=i-1; j>=0; j--)
    printf("%c", *(p+j));
  return 0;
}
