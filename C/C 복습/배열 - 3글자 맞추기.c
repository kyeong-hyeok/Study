#include <stdio.h>

int main(void) {
  char a[3], b, c[3]={'_','_','_'};
  int i, j, k=1;
  for(i=0; i<3; i++)
    scanf("%c", &a[i]);
  while (k<=5) {
    getchar();
    scanf("%c", &b);
    if(b==a[0]) c[0] = b;
    if(b==a[1]) c[1] = b;
    if(b==a[2]) c[2] = b;
    printf(" ");
    for(j=0; j<3; j++)
      printf("%c", c[j]);
    printf("\n");
    k++;
    if(a[0]==c[0] && a[1]==c[1] && a[2]==c[2])
      break;
  }
  return 0;
}
