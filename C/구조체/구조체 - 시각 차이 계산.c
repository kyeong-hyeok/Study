#include <stdio.h>

struct clock {
  int h;
  int m;
  int s;
};

int main(void) {
  struct clock c1,c2,c3;
  scanf("%d %d %d", &c1.h, &c1.m, &c1.s);
  scanf("%d %d %d", &c2.h, &c2.m, &c2.s);
  if(c2.s-c1.s<0) {
    c3.s = 60 - (c1.s-c2.s);
    c2.m -= 1;
  }
  else c3.s = c2.s-c1.s;
  if(c2.m-c1.m<0) {
    c3.m = 60 - (c1.m-c2.m);
    c2.h -= 1;
  }
  else c3.m = c2.m-c1.m;
  c3.h = c2.h - c1.h;
  printf("%d %d %d\n", c3.h, c3.m, c3.s);
  return 0;
}
