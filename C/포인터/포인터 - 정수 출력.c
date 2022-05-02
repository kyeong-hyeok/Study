#include <stdio.h>

void input(int *x, int *y, int *z);
void output(int *x, int *y, int *z);

int main(void) {
  int x, y, z;
  input(&x,&y,&z);
  output(&x,&y,&z);
  return 0;
}

void input(int *a, int *b, int *c) {
  scanf("%d %d %d", a, b, c);
}
void output(int *a, int *b, int *c) {
  printf("%d %d %d", *a, *b, *c);
}
