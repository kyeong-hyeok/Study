#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n,i,sum=0;
  int *p = NULL;
  scanf("%d", &n);
  p = (int *)malloc(n*sizeof(int));
  for(i=0; i<n; i++) {
    scanf("%d", &p[i]);
    sum+=p[i];
  }
  printf("%d", sum);
  free(p);
  return 0;
}
