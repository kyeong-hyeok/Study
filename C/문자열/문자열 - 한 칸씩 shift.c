#include <stdio.h>

int main(void) {
  char p[100], tmp;
  int i, j, k=0;
  scanf("%s", p);
  while(p[k]) {
    tmp = p[0];
    printf("%s\n", p);
    for(i=0; i<100; i++) {
      if(p[i+1] == '\0') {
        p[i] = tmp;
        p[i+1] = '\0';
        break;
        }
      p[i] = p[i+1];
    }
    k++;
  }
  return 0;

}
