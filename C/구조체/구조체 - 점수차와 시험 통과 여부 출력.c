#include <stdio.h>

struct result {
  int hg; int lg; char pass; int st; int sub;
};
void passorfail(struct result *r) {
  r->sub = r->hg - r->lg;
  if(r->sub <= r->st) r->pass = 'P';
  else r->pass = 'F';
}

int main(void) {
  struct result a;
  scanf("%d %d %d", &a.hg, &a.lg, &a.st);
  passorfail(&a);
  printf("%d %c", a.sub, a.pass);
  return 0;
}
