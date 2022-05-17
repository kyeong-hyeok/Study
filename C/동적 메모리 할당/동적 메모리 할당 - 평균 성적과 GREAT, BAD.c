#include <stdio.h>

struct student {
  char name[8]; int kor; int eng; int mat; double avg;
};

int main(void) {
  struct student *p = NULL;
  int n, i;
  scanf("%d", &n);
  p = (struct student *)malloc(n*sizeof(struct student));
  for(i=0; i<n; i++)
    scanf("%s %d %d %d", p[i].name, &p[i].kor, &p[i].eng, &p[i].mat);
  for(i=0; i<n; i++) {
    p[i].avg = (p[i].kor + p[i].eng + p[i].mat) / 3.0;
    printf("%s %.1f", p[i].name, p[i].avg);
    if(p[i].kor>=90 || p[i].eng>=90 || p[i].mat>=90 )
      printf(" GREAT");
    if(p[i].kor<70 || p[i].eng<70 || p[i].mat<70 )
      printf(" BAD");
    printf("\n");
  }
  free(p);
  return 0;
}
