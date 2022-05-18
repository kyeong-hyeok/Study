#include <stdio.h>
#include <string.h>

void add(int *s, int **ar) {
  int i, newsize = *s + 3;
  int *temp;
  temp = (int *)malloc(newsize*sizeof(int));
  for(i=0; i<*s; i++)
    temp[i]=(*ar)[i];
  free(*ar);
  *ar=temp;
  *s=newsize;
}

int main(void) {
  int n, i=0, size=5, j;
  int *p = NULL;
  p = (int *)malloc(size*sizeof(int));
  while(1) {
    scanf("%d", &p[i]);
    if(p[i] == -1) {
      for(j=0; j<=i; j++)
        printf(" %d", p[j]);
      break;
    }
    i++;
    if(i>=size || i<=17) {
      add(&size, &p);
    }
  }
  free(p);
  return 0;
}
