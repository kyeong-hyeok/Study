#include <stdio.h>

int main(void) {
  int h, m, s, t;
  scanf("%d", &t);
  h = t / 3600;
  m = (t % 3600) / 60;
  s = (t % 3600) % 60;
  printf("%02d:%02d:%02d", h, m, s);
  return 0;
}
