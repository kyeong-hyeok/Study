#include <stdio.h>
#include <string.h>

int main(void) {
  char str1[80], str2[10], a[10];
  int i, l1, l2, result=0;
  scanf("%s", str1);
  scanf("%s", str2);
  l1 = strlen(str1);
  l2 = strlen(str2);
  a[l2] = '\0';
  for(i=0; i<=str1-str2; i++) {
    strncpy(a, str1+i, l2);
    if( strcmp(str2,a) == 0 ) {
      result = 1;
      break;
    }
  }
  printf("%d %d", l1, result);
  return 0;
}
