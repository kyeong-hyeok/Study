#include <stdio.h>

int main(void) {
  int a[5], i, j, temp;
  for(i=0; i<5; i++)
    scanf("%d", &a[i]);
  for(i=0; i<5; i++) {
    for(j=i+1; j<5; j++) {
      if(a[i]>a[j]) {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }
  }
  printf("%d\n", a[4]);
  printf("%d\n", a[3]);
  return 0;
}
