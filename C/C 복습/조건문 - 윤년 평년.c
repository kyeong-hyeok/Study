#include <stdio.h>

int main(void) {
  int N, M;
  scanf("%d", &N);
  if (N%400==0) 
    printf("leap year");
  else if (N%100==0)
    printf("common year");
  else if (N%4==0)
    printf("leap year");
  else
    printf("common year");
  return 0;
}  
