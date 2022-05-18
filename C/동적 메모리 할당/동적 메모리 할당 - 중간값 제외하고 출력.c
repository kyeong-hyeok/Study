#include <stdio.h>

int main(void) {
  int n, i, j=0, k=0;
  int *p = NULL;
  int *q = NULL;
  scanf("%d", &n);
  p = (int *)malloc(n*sizeof(int));
  for(i=0; i<n; i++)
    p[i] = i;
  q = (int *)malloc((n-1)*sizeof(int));
  while(1) {
    if(k != (n-1)/2) {
      q[j] = p[k];
      j++;
    }
    k++;
    if(k==n)
      break;
  }
  for(i=0; i<n-1; i++)
    printf(" %d", q[i]);
  free(p);
  free(q);
  return 0;
}
