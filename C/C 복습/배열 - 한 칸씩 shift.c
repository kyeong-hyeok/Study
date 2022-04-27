#include <stdio.h>

int main(void) {
  char a[5], temp;
  int i, j;
  for(i=0; i<5; i++)
    scanf("%c", &a[i]);
  for(i=0; i<5; i++) {
    for(j=0; j<5; j++)
      printf("%c", a[j]);
    temp = a[4];
    a[4] = a[3];
    a[3] = a[2];
    a[2] = a[1];
    a[1] = a[0];
    a[0] = temp;
    printf("\n");
  }
  return 0;
}
