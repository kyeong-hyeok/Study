#include <stdio.h>

struct number {
  int k;
  int rank;
};

int main(void) {
  struct number n[11];
  int i, j, rank, r3, r7;
  for(i=0; i<10; i++) {
    scanf("%d", &n[i].k);
  }
  for(i=0; i<10; i++) {
    rank = 1;
    for(j=0; j<10; j++) {
      if(n[j].k > n[i].k) {
        rank++;
      }
    }
    n[i].rank = rank;
  }
  for(i=0; i<10; i++) {
    if(n[i].rank == 3) {
      r3 = n[i].k;
      break;
    }
    }
  for(i=0; i<10; i++) {
    if(n[i].rank == 7) {
      r7 = n[i].k;
      break;
    }
  }  
  printf("%d %d", r3, r7);
  return 0;
}
