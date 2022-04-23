#include <stdio.h>

int main(void) {
  int num, tt, th, hu, t, o;
  scanf("%d", &num);
  tt=num/10000;
  th=(num%10000)/1000;
  hu=(num%1000)/100;
  t=(num%100)/10;
  o=(num%10);
  printf("%dTTHO %dTHO %dHUN %dTEN %d", tt, th, hu, t, o);
}
