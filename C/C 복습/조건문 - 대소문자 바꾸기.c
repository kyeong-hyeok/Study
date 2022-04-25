#include <stdio.h>

int main(void) {
  char alp;
  scanf("%c", &alp);
  if (alp>=97 && alp<=122)
    printf("%c", alp-32);
  else if (alp>=65 && alp<=90)
    printf("%c", alp+32);
  else
    printf("none");
  return 0;
}
