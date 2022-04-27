#include <stdio.h>

int main(void) {
  int i, j, a[3][3];
  for(i=0; i<3; i++) {
    for(j=0; j<3; j++)
      scanf("%d", &a[i][j]);
  }
  printf("%d", a[0][0]+a[1][1]+a[2][2]);
  return 0;
}
