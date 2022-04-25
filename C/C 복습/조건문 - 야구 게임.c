#include <stdio.h>

int main(void) {
  int a, b, c, d, e, f, st=0, ba=0;
  scanf("%d %d %d", &a, &b, &c);
  scanf("%d %d %d", &d, &e, &f);
  if (a==d || a==e || a==f) {
    if (a==d)
      st++;
    else
      ba++;
    }
  if (b==d || b==e || b==f) {
    if (b==e)
      st++;
    else
      ba++;
    }
  if (c==d || c==e || c==f) {
    if (c==f)
      st++;
    else
      ba++;
  }
  printf("%dS%dB",st,ba);
  return 0;
}  
