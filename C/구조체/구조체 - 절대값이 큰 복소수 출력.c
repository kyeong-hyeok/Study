#include <stdio.h>

struct complex {
  double real, imag;
};

struct complex *add_complex(struct complex *a, struct complex *b) {
  if((a->real)*(a->real)+(a->imag)*(a->imag) >(b->real)*(b->real)+(b->imag)*(b->imag))
    return a;
  else
    return b;
}
int main(void) {
  struct complex x,y,*z;
  scanf("%lf %lf", &x.real, &x.imag);
  scanf("%lf %lf", &y.real, &y.imag);
  z=add_complex(&x,&y);
  printf("%.1f + %.1fi", z->real, z->imag);
  return 0;
}
