#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int n, m, i, j, a=0, b=0, c=1, tmp, **p=NULL;
  scanf("%d %d", &n, &m);
  p = (int**)malloc(n*sizeof(int*));
  for(i=0; i<n; i++)
    p[i] = (int*)malloc(m*sizeof(int));
  i=0;
  j=0;
  while(c<=n*m) {
    if(a<=n-1 && b>=0) {
      p[a][b] = c;
      a+=1;
      b-=1;
      c++;
      }
    else {
      if(j<m-1)
        j++;
      else
        i++;
      a=i;
      b=j;
    }
  }
  for(i=0; i<n; i++) {
    for(j=0; j<m; j++)
      printf(" %d", p[i][j]);
    printf("\n");
  }
  for(i=0; i<n; i++)
    free(p[i]);
  free(p);
	return 0;
}
