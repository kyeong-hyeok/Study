#include <stdio.h>

int main(void) {
  int n, i, temp;
  int *p = NULL;
  scanf("%d", &n);
  while(getchar() != '\n');
  p = (int *)malloc(n*sizeof(int));
  for(i=0; i<n; i++)
    scanf("%d", &p[i]);
  for(i=0; i<n-1; i++) {
    if(p[i] > p[i+1]) {
      temp = p[i];
      p[i] = p[i+1];
      p[i+1] = temp;
    }
  }
  for(i=0; i<n; i++)
    printf("%d\n", p[i]);
  free(p);
  return 0;
}
