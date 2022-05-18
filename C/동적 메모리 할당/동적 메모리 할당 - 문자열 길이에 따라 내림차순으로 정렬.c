#include <stdio.h>
#include <string.h>

int main(void) {
  int n, i, l, j;
  int *k = NULL;
  char p[100], tmp[100];
  char **pch;
  scanf("%d", &n);
  while(getchar() != '\n');
  pch = (char**)malloc((n+1)*sizeof(char*));
  k = (int *)malloc(n*sizeof(int));
  for(i=0; i<n; i++) {
    gets(p);
    pch[i] = (char*)malloc((strlen(p)+1)*sizeof(char));
    strcpy(pch[i], p);
  }
  for(i=0; i<n-1; i++) {
    for(j=0; j<n-1-i; j++) {
      if(strlen(pch[j]) < strlen(pch[j+1])) {
        strcpy(tmp,pch[j]);
        strcpy(pch[j],pch[j+1]);
        strcpy(pch[j+1], tmp);
      }
    }
  }
  for(i=0; i<n; i++)
    printf("%s\n", pch[i]);
  for(i=0; i<n; i++)
    free(pch[i]);
  free(pch);
  return 0;
}
