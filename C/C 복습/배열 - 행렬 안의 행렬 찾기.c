#include <stdio.h>

int main(void) {
  int i, j, a[3][3], b[2][2], r=-1, c=-1;
  for(i=0; i<3; i++) {
    for(j=0; j<3; j++)
      scanf("%d", &a[i][j]);
  }
  for(i=0; i<2; i++) {
    for(j=0; j<2; j++)
      scanf("%d", &b[i][j]);
  }
  for(i=0; i<2; i++) {
    for(j=0; j<2; j++) {
      if (a[i][j]==b[0][0] && a[i+1][j]==b[1][0] && a[i][j+1]==b[0][1] && a[i+1][j+1]==b[1][1]) {
        r=i;
        c=j;
        }
    }
  }
  if(r!=-1) printf("%d %d", r, c);
  else printf("none");
  return 0;
}
