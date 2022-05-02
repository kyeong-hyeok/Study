#include <stdio.h>


int main(void) {
  char ch[10], *p, *k, cnt[10]={}, maxchar;
  int i=0, max=-1;
  scanf("%s", ch);
  for(p=ch; p<ch+10; p++) {
    for(k=ch; k<ch+10; k++) {
      if(*p == *k)
        cnt[i]++;
    }
    if (cnt[i]>max) {
      max=cnt[i];
      maxchar = *p;
    }
    i++;
  }
  printf("%c %d", maxchar, max);
  return 0;
}
