#include <stdio.h>

struct date {
  int year; int month; int day;
};
struct date *select_min(struct date *a, struct date *b) {
  if(a->year < b->year) return a;
  else if(a->year > b->year) return b;
  else {
    if (a->month < b->month) return a;
    else if (a->month > b->month) return b;
    else {
      if (a->day < b->day) return a;
      else return b;
    }
  }
}

int main(void) {
  struct date x,y,*z;
  scanf("%d/%d/%d", &x.year, &x.month, &x.day);
  scanf("%d/%d/%d", &y.year, &y.month, &y.day);
  z = select_min(&x,&y);
  printf("%d/%d/%d", z->year, z->month, z->day);
  return 0;
}
