#include <stdio.h>
#include <string.h>

int main(void) {
  int n, i, k, min=100;
  int *p = NULL;
  char **pch;
  scanf("%d", &n);
  while(getchar() != '\n');
  pch = (char**)malloc((n+1)*sizeof(char*));
  for(i=0; i<n; i++)
    pch[i] = (char*)malloc(100*sizeof(char));
  p = (int *)malloc(n*sizeof(int));
  for(i=0; i<n; i++) {
    gets(pch[i]);
    p[i] = strlen(pch[i]);
    if(p[i]<min) {
      min = p[i];
      k=i;
    }
  }
  printf("%s", pch[k]);
  free(p);
  for(i=0; i<n; i++)
    free(pch[i]);
  free(pch);
  return 0;
}
