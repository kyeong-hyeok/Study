#include <stdio.h>

#include <stdlib.h>

 

int main(void) {
  int n, i, cnt1=0, cnt2=0;
  char *p = NULL;
  char c1, c2;
  scanf("%d", &n);
  p = (char *)malloc((n+1)*sizeof(char));
  scanf("%s", p);
  while(getchar() != '\n');  // 개행 문자 비우기
  scanf("%c %c", &c1, &c2);
  for(i=0;i<n;i++) {
    if(c1==p[i]) 
      cnt1+=1;
    if(c2==p[i]) 
      cnt2+=1;
  }
  printf("%d %d", cnt1, cnt2);
  free(p);
  return 0;
}
