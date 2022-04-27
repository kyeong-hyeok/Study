#include <stdio.h>

void die1(int x);
void die2(int x, int y);
void die3(int x, int y, int z);
int N;
int main(void) {
  int i;
  scanf("%d", &N);
  for(i=1; i<=6; i++) 
    die1(i);
  return 0;
}

void die1(int x) {
  int i;
  for(i=1; i<=6; i++)
    die2(x,i);
}
void die2(int x, int y) {
  int i;
  for(i=1; i<=6; i++)
    die3(x,y,i);
}  
void die3(int x, int y, int z) {
  if(x+y+z==N) {
    printf("%d %d %d", x, y, z);
    printf("\n");
    }
}
