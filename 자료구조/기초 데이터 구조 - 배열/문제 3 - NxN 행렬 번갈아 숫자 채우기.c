#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int n, i, a=0, b=0, j=1, **p=NULL;
  scanf("%d", &n);
  p = (int**)malloc(n*sizeof(int*));
  for(i=0; i<n; i++)
    p[i] = (int*)malloc(n*sizeof(int));
  i=1;
  while(j<=n*n) {
    if(b+i==n) {
      p[a][b]=j;
      i=-1;
      a++;
    }
    else if (b+i==-1) {
      p[a][b]=j;
      i=1;
      a++;
    }
    else {
      p[a][b]=j;
      b += i;
    }
    j++;
  }
  for(i=0; i<n; i++) {
    for(j=0; j<n; j++)
      printf(" %d", p[i][j]);
    printf("\n");
  }
  for(i=0; i<n; i++)
    free(p[i]);
  free(p);
	return 0;
}
