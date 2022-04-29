#include <stdio.h>

int main(void) {
  int ar[5]={2,3,5,7,-1};
  int i, *p=ar;
  for(i=0; i<5; i++) {
    printf("%d\n", *(p+i));
  }
  return 0;
}
