#include <stdio.h>

void hanoi(int n, char f, char b, char t) {
  if(n==1) {
    printf("%c %c\n", f, t);
  }
  else {
    hanoi(n-1, f, t, b);
    hanoi(1, f, b, t);
    hanoi(n-1, b, f, t);
  }
}
int main(void) {
  int n;
  char A, B, C;
  scanf("%d", &n);
  hanoi(n, 'A', 'B', 'C');
  return 0;
}
