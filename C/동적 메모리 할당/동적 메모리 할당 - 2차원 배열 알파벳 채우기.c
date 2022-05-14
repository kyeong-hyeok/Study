#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int c, r, i, j, k;
  char **pch;
  scanf("%d %d", &c, &r);
  pch = (char **)malloc(r*sizeof(char*));
  for(i=0; i<r; i++)
    pch[i]=(char *)malloc(c*sizeof(char));
  k=97;
  for(i=0; i<r; i++) {
    for(j=0; j<c; j++) {
      pch[i][j]=k;
      if(k>='z')
        k = 'A';
      else if(k>='Z' && k<'a')
        k = 'a';
      else
        k++;
      printf("%c ", pch[i][j]);
      }
    printf("\n");
  }
  for(i=0; i<r; i++)
    free(pch[i]);
  free(pch);
  return 0;
}
