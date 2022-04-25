#include <stdio.h>

int main(void) {
  int N, M;
  scanf("%d", &N);
  scanf("%d", &M);
  if (N==1) {
    printf("Americano\n");
    printf("%d %d", (M-500)/500, (M-500)%500/100);
    }
  else if (N==2) {
    printf("Cafe Latte\n");
    printf("%d %d", (M-400)/500, (M-400)%500/100);
    }
  else if (N==3) {
    printf("Lemon Tea\n");
    printf("%d %d", (M-300)/500, (M-300)%500/100);
    }
  return 0;
}  
