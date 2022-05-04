#include <stdio.h>

void addArray(int *a, int *b, int *c, int n);

int main(void) {
  int x[20], y[20], z[20], w;
  int *p;
  scanf("%d", &w);
  for(p=x; p<x+w; p++)
    scanf("%d", p);
  for(p=y; p<y+w; p++)
    scanf("%d", p);
  addArray(x,y,z,w);
  for(p=z; p<z+w; p++)
    printf(" %d", *p);  
  return 0;
}

void addArray(int *a, int *b, int *c, int n) {
  int *d, i=0;
  for(d=a; d<a+n; d++) {  
    *(c+i) = *(a+i) + *(b+n-1-i);  // 역방향으로 더하여 새로운 배열에 저장하기
    i++;
  }
}
