#include <stdio.h>

void print_row1(int x);
void print_row2(int x);

int main(void) {
  int N, i;
  scanf("%d", &N);
  print_row1(N);
  for(i=0; i<N-2; i++)  
    print_row2(N);
  print_row1(N);
  return 0;
}

void print_row1(int x) {
  int i;
  for(i=0; i<x; i++)
    printf("%d", x);
  printf("\n");
}

void print_row2(int x) {
  int i;
  printf("%d", x);
  for(i=0; i<x-2; i++)
    printf(" ");
  printf("%d", x);
  printf("\n");
}
