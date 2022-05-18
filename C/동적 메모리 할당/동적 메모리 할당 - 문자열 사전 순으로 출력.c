#include <stdio.h>
#include <string.h>

int main(void) {
  int n, i, j=0, k=0;
  char **pch = NULL;
  char p[100], tmp[100];
  scanf("%d", &n);
  while(getchar() != '\n');
  pch = (char **)malloc(n*sizeof(char*));
  for(i=0; i<n; i++) {
    gets(p);
    pch[i] = (char *)malloc((strlen(p)*sizeof(char)));
    strcpy(pch[i],p);
  }
  for(i=0; i<n-1; i++) {
    for(j=0; j<n-1-i; j++) {
      if(strcmp(pch[j],pch[j+1])>0) {
        strcpy(tmp,pch[j]);
        strcpy(pch[j],pch[j+1]);
        strcpy(pch[j+1],tmp);
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
