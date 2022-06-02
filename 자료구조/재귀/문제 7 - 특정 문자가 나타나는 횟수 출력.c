#include <stdio.h>
#include<string.h>

int cnt=0;
int alpha(char *s1, char s2, int n) {
  int l = strlen(s1);
  if(n==0)
    return cnt;
  else {
    if(s1[l-n] == s2)
      cnt++;
    return alpha(s1, s2, n-1);
  }
}

int main(void) {
  char s1[100], s2;
  scanf("%s", s1);
  while(getchar()!='\n');
  scanf("%c", &s2);
  printf("%d", alpha(s1,s2,strlen(s1)));
  return 0;
}
