#include <stdio.h>

int main(void) {
  char str1[40], str2[20];
  int n, i=0, j=0, k;
  scanf("%s", str1);
  scanf("%s", str2);
  scanf("%d", &n);
  while(str2[j]) {
    j++;
  }
  k=n;
  while(str1[k]) {
    str1[k+j] = str1[k];
    k++;
  }
  str1[k+j] = '\0';
  while(str2[i]) {
    str1[i+n] = str2[i];
    i++;
  }
  printf("%s", str1);
  return 0;
}
