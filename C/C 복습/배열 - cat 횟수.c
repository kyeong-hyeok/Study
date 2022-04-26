#include <stdio.h>

int main(void) {
  char a[7];
  int i, cnt=0;
  for (i=0; i<7; i++)
    scanf("%c", &a[i]);
  for(i=0; i<=4; i++) {
    if(a[i]=='c' && a[i+1]=='a' && a[i+2]=='t')
      cnt++;
  }
  printf("%d",cnt);
  return 0;
}
