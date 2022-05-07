#include <stdio.h>
#include <string.h>

int main(void) {
  char p[20];
  int i=0;
  scanf("%s", p);
  while(p[i]) {
    if(p[i]>='a' && p[i]<='z')
      printf("%c", p[i]);
    i++;
  }
  return 0;

}
