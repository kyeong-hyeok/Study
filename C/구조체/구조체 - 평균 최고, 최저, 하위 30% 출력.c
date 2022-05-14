#include <stdio.h>

struct student {
  char name[10]; int q1; int q2; int q3; double avg;
};

void read_data(struct student a[]) {
  int i;
  for(i=0; i<10; i++)
    scanf("%s %d %d %d", a[i].name, &a[i].q1, &a[i].q2, &a[i].q3);
}

void cal_avg(struct student a[]) {
  int i;
  for(i=0; i<10; i++) {
    a[i].avg = (a[i].q1 + a[i].q2 + a[i].q3) / 3.0;
  }
}
void sort(struct student a[]) {
  int i, j;
  double temp;
  for(i=0; i<10; i++) {
    for(j=0; j<9-i; j++) {
      if(a[j].avg < a[j+1].avg) {
        temp = a[j].avg;
        a[j].avg = a[j+1].avg;
        a[j+1].avg = temp;
      }
    }
  }
}
void print_score(struct student a[]) {
  int i;
  printf("%s %.2f\n", a[0].name, a[0].avg);
  printf("%s %.2f\n", a[9].name, a[9].avg);
  for(i=7; i<10; i++)
    printf("%s %.2f\n", a[i].name, a[i].avg);
}
int main(void) {
  struct student x[10];
  read_data(x);
  cal_avg(x);
  sort(x);
  print_score(x);
  return 0;
}
