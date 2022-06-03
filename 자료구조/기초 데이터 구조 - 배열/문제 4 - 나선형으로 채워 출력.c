#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int n, m, i, a=0, b=-1, d=0, j, c=1, **p=NULL;
  int ud[4] = {0, 1, 0, -1};
  int rl[4] = {1, 0, -1, 0};
  scanf("%d %d", &n, &m);
  p = (int**)malloc(n*sizeof(int*));
  for(i=0; i<n; i++)
    p[i] = (int*)malloc(m*sizeof(int));
  for(i=0; i<n; i++) {
    for(j=0; j<m; j++)
      p[i][j] = 0;
  }
  while(c<=n*m) {
    if(p[a+ud[d]][b+rl[d]] == 0 && (a+ud[d]<n) && (a+ud[d]>=0) && (b+rl[d]<m) && (b+rl[d]>=0)) {
      a+=ud[d];
      b+=rl[d];
      p[a][b] = c;
      c++;
    }
    else
      d= (d+1)%4;
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
